#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 100005;

int N, SG [MAXN], SG_partial [MAXN], win_move [MAXN];
int seen [MAXN];

int main ()
{
    scanf ("%d", &N);
    SG [0] = SG_partial [0] = 0;

    for (int n = 1; n <= N; n++)
    {
        win_move [n] = MAXN;

        for (int k = 2; k * k < 2 * n; k++)
            if ((2 * n) % k == 0)
            {
                int a = 2 * n / k - k + 1;

                if (a % 2 != 0)
                    continue;

                a /= 2;
                int sg = SG_partial [a - 1] ^ SG_partial [a + k - 1];

                if (sg == 0 && k < win_move [n])
                    win_move [n] = k;

                seen [sg] = n;
            }

        SG [n] = 0;

        while (seen [SG [n]] == n)
            SG [n]++;

        SG_partial [n] = SG_partial [n - 1] ^ SG [n];
    }

    printf ("%d\n", SG [N] == 0 ? -1 : win_move [N]);
    return 0;
}