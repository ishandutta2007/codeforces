#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

const int MAXN = 205, MAXM = 20005;

int N, M;

inline bitset <MAXN> input ()
{
    int k;
    scanf ("%d", &k);
    bitset <MAXN> bset;

    for (int a, i = 0; i < k; i++)
    {
        scanf ("%d", &a); a--;
        bset [a] = 1;
    }

    return bset;
}

inline void output (bitset <MAXN> bset)
{
    printf ("%d", (int) bset.count ());

    for (int i = 0; i < MAXN; i++)
        if (bset [i])
            printf (" %d", i + 1);

    putchar ('\n');
}

bitset <MAXN> sets [MAXM];
bool done [MAXN];

int main ()
{
    scanf ("%d", &N);
    M = N * (N - 1) / 2;

    for (int i = 0; i < M; i++)
        sets [i] = input ();

    if (M == 1)
    {
        int one = -1;

        for (int i = 0; i < MAXN; i++)
            if (sets [0][i])
                one = i;

        sets [0][one] = 0;
        printf ("1 %d\n", one + 1);
        output (sets [0]);
        return 0;
    }

    memset (done, false, sizeof (done));

    for (int b = 0; b < MAXN; b++)
        if (!done [b])
            for (int i = 0; i < M; i++)
                if (sets [i][b] == 1)
                {
                    for (int j = i + 1; j < M; j++)
                        if (sets [j][b] == 1)
                        {
                            bitset <MAXN> bset = sets [i] & sets [j];
                            output (bset);

                            for (int k = 0; k < MAXN; k++)
                                if (bset [k])
                                    done [k] = true;

                            break;
                        }

                    break;
                }

    return 0;
}