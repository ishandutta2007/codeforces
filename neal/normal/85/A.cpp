#include <cstdio>
using namespace std;

int n;
char next_letter = 'a', grid [4][105];

inline char adv ()
{
    return next_letter = (next_letter - 'a' + 1) % 26 + 'a';
}

int main ()
{
    scanf ("%d", &n);

    for (int c = 0; c < n; c++)
    {
        if (c == 0)
            grid [0][c] = grid [1][c] = adv ();

        if (c == n - 1)
        {
            if (n % 2 == 0)
                grid [0][c] = grid [1][c] = adv ();
            else
                grid [2][c] = grid [3][c] = adv ();
        }
        else if (c % 2 == 1)
        {
            grid [0][c] = grid [0][c + 1] = adv ();
            grid [1][c] = grid [1][c + 1] = adv ();
            grid [2][c] = grid [2][c - 1] = adv ();
            grid [3][c] = grid [3][c - 1] = adv ();
        }
    }

    if (n % 2 == 0)
    {
        grid [2][n - 1] = grid [2][n - 2] = adv ();
        grid [3][n - 1] = grid [3][n - 2] = adv ();
    }

    for (int r = 0; r < 4; r++)
        puts (grid [r]);

    return 0;
}