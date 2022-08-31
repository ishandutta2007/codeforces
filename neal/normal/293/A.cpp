#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

const int N_MAX = 1000005;

int N;
char S[2 * N_MAX], T[2 * N_MAX];
int pairs[2][2];

int main()
{
    scanf("%d %s %s", &N, S, T);
    memset(pairs, 0, sizeof(pairs));

    for (int i = 0; i < 2 * N; i++)
        pairs[S[i] - '0'][T[i] - '0']++;

    int first = 0, second = 0;

    for (int it = 0; it < 2 * N; it++)
        if (it % 2 == 0)
        {
            if (pairs[1][1] > 0)
            {
                first++;
                pairs[1][1]--;
            }
            else if (pairs[1][0] > 0)
            {
                first++;
                pairs[1][0]--;
            }
            else if (pairs[0][1] > 0)
                pairs[0][1]--;
            else
                pairs[0][0]--;
        }
        else
        {
            if (pairs[1][1] > 0)
            {
                second++;
                pairs[1][1]--;
            }
            else if (pairs[0][1] > 0)
            {
                second++;
                pairs[0][1]--;
            }
            else if (pairs[1][0] > 0)
                pairs[1][0]--;
            else
                pairs[0][0]--;
        }

    assert(pairs[0][0] + pairs[0][1] + pairs[1][0] + pairs[1][1] == 0);

    if (first > second)
        puts("First");
    else if (second > first)
        puts("Second");
    else
        puts("Draw");

    return 0;
}