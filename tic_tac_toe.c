#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
void choose_your_symbol();
void display_player_symbols();
void display_the_checkboard();
void check_and_mark_for_player1();
void check_and_mark_for_player2();
void update_board_position();
int check_win_for_either_player1_or_player2();
char square[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char mark, mark1;
int p = 0, choice, count = 0, choice1, t = 0, m = 0, res = 0, f = 0, trounce = 0;
char choose, choose1;
int main()
{
    choose_your_symbol();
    display_player_symbols();
    sleep(2);
    if (p == 2)
    {
        while (res <= 8)
        {
            update_board_position();
            printf("PLAYER 1 CHOSE %c \n", choose);
            printf("\n");
            printf("PLAYER 2 CHOSE %c \n", choose1);
            display_the_checkboard();
            if (count % 2 == 0)
            {
                check_and_mark_for_player1();
            }
            else
            {
                check_and_mark_for_player2();
            }
            f = check_win_for_either_player1_or_player2();
            if (f == 1)
            {
                printf("PLAYER 1 WINS");
                printf("\n");
                break;
            }
            else if (f == 2)
            {
                printf("PLAYER 2 WINS");
                printf("\n");
                break;
            }
            else
            {
                if ((f == 0) && (trounce == 9))
                {
                    printf("\n");
                    display_the_checkboard();
                    printf("its a tiee");
                }
            }
            count++;
            res++;
        }
        printf("\n");
        getch();
        return 0;
    }
}
void choose_your_symbol()
{
    do
    {
        p = 2;
        printf("\n");
        printf("PLAYER 1,ENTER YOUR CHOICE ");
        printf("\n");
        scanf(" %c", &choose);
        if ((choose != 'x') && (choose != 'X') && (choose != 'o') && (choose != 'O'))
        {
            printf("INVALID ,PLEASE TYPE CORRECT CHOICE");
            printf("\n");
            p = 1;
        }
    } while (p == 1);
}
void display_player_symbols()
{
    if ((choose == 'x') || (choose == 'X') || (choose == 'o') || (choose == 'O'))
    {
        if ((choose == 'x') || (choose == 'X'))
        {
            choose = 'x';
            printf("\n");
            printf("PLAYER 1 CHOOSES x\n");
        }
        else
        {
            choose = 'o';
            printf("\n");
            printf("PLAYER 1 CHOOSES o\n");
        }
    }
    if (choose == 'x')
    {
        choose1 = 'o';
        printf("\n");
        printf("PLAYER 2 CHOOSES o\n");
    }
    else
    {
        choose1 = 'x';
        printf("\n");
        printf("PLAYER 2 CHOOSES x\n");
    }
}
void display_the_checkboard()
{
    printf("\n");
    printf("\n\n TIC TAC TOE \n ");
    printf("\n");
    printf("      |      |   \n");
    printf("  %c   | %c    |  %c\n", square[0][0], square[0][1], square[0][2]);
    printf("______|______|___\n");
    printf("      |      |   \n");
    printf("  %c   | %c    |  %c\n", square[1][0], square[1][1], square[1][2]);
    printf("______|______|___\n");
    printf("      |      |   \n");
    printf("  %c   | %c    |  %c\n", square[2][0], square[2][1], square[2][2]);
    printf("      |      |   \n\n");
}
void check_and_mark_for_player1()
{

    do
    {
        t = 2;
        printf("Player 1 enter a number : ");
        scanf("%d", &choice);
        mark = choose;
        if (choice == 1 && (square[0][0] != mark1) && (square[0][0] != mark))
            square[0][0] = mark;
        else if (choice == 2 && (square[0][1] != mark1) && (square[0][1] != mark))
            square[0][1] = mark;
        else if (choice == 3 && (square[0][2] != mark1) && (square[0][2] != mark))
            square[0][2] = mark;
        else if (choice == 4 && (square[1][0] != mark1) && (square[1][0] != mark))
            square[1][0] = mark;
        else if (choice == 5 && (square[1][1] != mark1) && (square[1][1] != mark))
            square[1][1] = mark;
        else if (choice == 6 && (square[1][2] != mark1) && (square[1][2] != mark))
            square[1][2] = mark;
        else if (choice == 7 && (square[2][0] != mark1) && (square[2][0] != mark))
            square[2][0] = mark;
        else if (choice == 8 && (square[2][1] != mark1) && (square[2][1] != mark))
            square[2][1] = mark;
        else if (choice == 9 && (square[2][2] != mark1) && (square[2][2] != mark))
            square[2][2] = mark;
        else
        {
            printf(" \n Invalid move ");
            printf("\n");
            t = 1;
        }
    } while (t == 1);
}
void check_and_mark_for_player2()
{
    do
    {
        m = 2;
        printf("Player 2 enter a number : ");
        scanf("%d", &choice1);
        mark1 = choose1;
        if (choice1 == 1 && (square[0][0] != mark1) && (square[0][0] != mark))
            square[0][0] = mark1;
        else if (choice1 == 2 && (square[0][1] != mark1) && (square[0][1] != mark))
            square[0][1] = mark1;
        else if (choice1 == 3 && (square[0][2] != mark1) && (square[0][2] != mark))
            square[0][2] = mark1;
        else if (choice1 == 4 && (square[1][0] != mark1) && (square[1][0] != mark))
            square[1][0] = mark1;
        else if (choice1 == 5 && (square[1][1] != mark1) && (square[1][1] != mark))
            square[1][1] = mark1;
        else if (choice1 == 6 && (square[1][2] != mark1) && (square[1][2] != mark))
            square[1][2] = mark1;
        else if (choice1 == 7 && (square[2][0] != mark1) && (square[2][0] != mark))
            square[2][0] = mark1;
        else if (choice1 == 8 && (square[2][1] != mark1) && (square[2][1] != mark))
            square[2][1] = mark1;
        else if (choice1 == 9 && (square[2][2] != mark1) && (square[2][2] != mark))
            square[2][2] = mark1;
        else
        {
            printf(" \n Invalid move ");
            printf("\n");
            m = 1;
        }
    } while (m == 1);
}
void update_board_position()
{
    system("cls");
}
int check_win_for_either_player1_or_player2()
{
    if (square[0][0] == square[0][1] && square[0][1] == square[0][2])
    {
        if (square[0][0] == choose)
        {
            display_the_checkboard();
            return 1;
        }
        else
        {
            display_the_checkboard();
            return 2;
        }
    }
    else if (square[1][0] == square[1][1] && square[1][1] == square[1][2])
    {
        if (square[1][0] == choose)
        {
            display_the_checkboard();
            return 1;
        }
        else
        {
            display_the_checkboard();
            return 2;
        }
    }
    else if (square[2][0] == square[2][1] && square[2][1] == square[2][2])
    {
        if (square[2][0] == choose)
        {
            display_the_checkboard();
            return 1;
        }
        else
        {
            display_the_checkboard();
            return 2;
        }
    }
    else if (square[0][0] == square[1][0] && square[1][0] == square[2][0])
    {
        if (square[0][0] == choose)
        {
            display_the_checkboard();
            return 1;
        }
        else
        {
            display_the_checkboard();
            return 2;
        }
    }
    else if (square[0][1] == square[1][1] && square[1][1] == square[2][1])
    {
        if (square[0][1] == choose)
        {
            display_the_checkboard();
            return 1;
        }
        else
        {
            display_the_checkboard();
            return 2;
        }
    }
    else if (square[0][2] == square[1][2] && square[1][2] == square[2][2])
    {
        if (square[0][2] == choose)
        {
            display_the_checkboard();
            return 1;
        }
        else
        {
            display_the_checkboard();
            return 2;
        }
    }
    else if (square[0][0] == square[1][1] && square[1][1] == square[2][2])
    {
        if (square[0][0] == choose)
        {
            display_the_checkboard();
            return 1;
        }
        else
        {
            display_the_checkboard();
            return 2;
        }
    }
    else if (square[0][2] == square[1][1] && square[1][1] == square[2][0])
    {
        if (square[0][2] == choose)
        {
            display_the_checkboard();
            return 1;
        }
        else
        {
            display_the_checkboard();
            return 2;
        }
    }
    else
    {
        trounce++;
        return 0;
    }
}