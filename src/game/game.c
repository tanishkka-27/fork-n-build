#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lower, upper, x, guess, count = 0;
    int flag = 0;
    int total_chances;

    // Taking Inputs
    printf("Enter Lower bound: ");
    scanf("%d", &lower);

    printf("Enter Upper bound: ");
    scanf("%d", &upper);

    //for generating random number
    srand(time(0));
    // Generating the random number between lower and upper bounds
    x = (rand() % (upper - lower + 1)) + lower;
    // Calculate the total number of chances based on the range
    total_chances = (int)ceil(log2(upper - lower + 1) / log(2));

    printf("\n\tYou've only %d chances to guess the integer!\n\n",total_chances);


    // for calculation of minimum number of guesses acc to the range
    while (count < total_chances) {
        count++;

        // Now to take a guessing number as input
        printf("Guess a number: ");
        scanf("%d", &guess);

        //Guessing part of the game
        if (guess < lower || guess > upper) {
            printf("Please guess a number between %d and %d\n",
                   lower, upper);
            count--; // Do not count this as a valid guess
            continue;
            }

        if (x == guess) {
            printf(
                "Congratulations you did it in %d try!\n",
                count);
            // set flag to 1 to indicate that the number has been guessed correctly
            flag = 1;
            break;
        }
        else if (x > guess) {
            printf("You guessed too small!\n");
        }
        else if (x < guess) {
            printf("You guessed too high!\n");
        }

    }

    // If the user did not guess the number correctly
    if (!flag) {
        printf("\nThe number is %d\n\tBetter luck next time!\n", x);
    }

    return 0;
}
