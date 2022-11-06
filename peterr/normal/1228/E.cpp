#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 250;
int kpow[MAXN + 1];
int kmpow[MAXN + 1];
int choose[MAXN + 1][MAXN + 1];
int dp[MAXN + 1][MAXN];

int mult(int a, int b)
{
    return (int) (((long long) a * b) % MOD);
}

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int main()
{
    int n, k;
    cin >> n >> k;
    kpow[0] = kmpow[0] = choose[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        kpow[i] = mult(kpow[i - 1], k);
        kmpow[i] = mult(kmpow[i - 1], k - 1);
        choose[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp[1][i] = mult(choose[n][i], kmpow[i]);
        //cout << i << " " << dp[1][i] << endl;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = mult(dp[i - 1][j], kmpow[j]);
            temp = mult(temp, add(add(kpow[n - j], -kmpow[n - j]), MOD));
            dp[i][j] = add(dp[i][j], temp);
            for (int k = j + 1; k < n; k++)
            {
                temp = mult(dp[i - 1][k], choose[k][j]);
                temp = mult(temp, kmpow[j]);
                temp = mult(temp, kpow[n - k]);
                dp[i][j] = add(dp[i][j], temp);
            }
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}