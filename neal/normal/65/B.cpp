#include <cstdio>
#include <vector>
using namespace std;

int N, P, Y, Z;
vector <int> solution;

int main ()
{
    scanf ("%d", &N);
    P = 1000;

    while (N-- > 0)
    {
        scanf ("%d", &Y);
        Z = 10000;

        for (int d = 0; d <= 9; d++)
        {
            int NY = Y - (Y / 1000) % 10 * 1000 + d * 1000;

            if (NY >= P && NY < Z)
                Z = NY;

            NY = Y - (Y / 100) % 10 * 100 + d * 100;

            if (NY >= P && NY < Z)
                Z = NY;

            NY = Y - (Y / 10) % 10 * 10 + d * 10;

            if (NY >= P && NY < Z)
                Z = NY;

            NY = Y - Y % 10 + d;

            if (NY >= P && NY < Z)
                Z = NY;
        }

        if (Z > 2011)
        {
            puts ("No solution");
            return 0;
        }

        solution.push_back (Z);
        P = Z;
    }

    for (int i = 0; i < (int) solution.size (); i++)
        printf ("%d\n", solution [i]);

    return 0;
}