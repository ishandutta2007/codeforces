#include <cstdio>
#include <cstring>
using namespace std;

const int N_MAX = 1000005, BITS = 22, FULL = (1 << BITS) - 1;

int N, A[N_MAX], dp[1 << BITS];

int main()
{
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", A + i);
        dp[A[i]] = A[i];
    }

    for (int m = 0; m < 1 << BITS; m++)
        for (int i = 0; i < BITS && dp[m] == -1; i++)
            if (m & 1 << i)
                dp[m] = dp[m ^ 1 << i];

    for (int i = 0; i < N; i++)
        printf("%d%c", dp[FULL ^ A[i]], i < N - 1 ? ' ' : '\n');

    return 0;
}