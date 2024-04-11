#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

const int N_MAX = 2005, MOD = 1000000007;

int N, derange[N_MAX], dp[N_MAX][N_MAX];
bool available[N_MAX], missing[N_MAX];

int solve(int n, int k)
{
    assert(n >= k);

    if (n == k)
        return derange[n];

    if (dp[n][k] != -1)
        return dp[n][k];

    long long answer = (long long) (n - k) * solve(n - 1, k);

    if (k > 0)
        answer += (long long) k * solve(n - 1, k - 1);

    return dp[n][k] = (answer % MOD + MOD) % MOD;
}

int main()
{
    scanf("%d", &N);
    memset(available, false, sizeof(available));
    memset(missing, true, sizeof(missing));
    int S = 0;

    for (int i = 0; i < N; i++)
    {
        int p;
        scanf("%d", &p);

        if (p == -1)
        {
            available[i] = true;
            S++;
        }
        else
        {
            p--;
            missing[p] = false;
        }
    }

    derange[0] = 1;

    for (int n = 1; n <= N; n++)
        derange[n] = ((long long) n * derange[n - 1] + (n % 2 == 0 ? +1 : -1)) % MOD;

    int K = 0;

    for (int i = 0; i < N; i++)
        if (available[i] && missing[i])
            K++;

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(S, K));
    return 0;
}