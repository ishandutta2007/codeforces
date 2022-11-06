#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 50;
const int MAXM = 50;
const int MAXW = 100;
bool likes[MAXN];
int weight[MAXN];
int dp[MAXW + 1][MAXM + 1][MAXM + 1][MAXM + 1];
int dp2[MAXW + 1][MAXM + 1][MAXM + 1][MAXM + 1];

void modInv(int a, int b, int& ainv, int& binv)
{
    if (a == 0)
    {
        ainv = 0;
        binv = 1;
        return;
    }
    int x, y;
    modInv(b % a, a, x, y);
    ainv = (y - ((long long) x * (b / a)) % MOD + MOD) % MOD;
    binv = x % MOD;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> likes[i];
    int good = 0, bad = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        if (likes[i])
            good += weight[i];
        else
            bad += weight[i];
    }
    int trash;
    for (int w = 1; w <= MAXW; w++)
    {
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[w][0][i][j] = w;
                dp2[w][0][i][j] = w;
            }
        }
    }
    for (int v = 1; v <= m; v++)
    {
        for (int w = MAXW - v; w >= 0; w--)
        {
            for (int i = m - v; i >= 0; i--)
            {
                for (int j = m - v; j >= 0; j--)
                {
                    if (w > good + i || j > bad)
                        continue;
                    int pInv;
                    modInv(good + bad + i - j, MOD, pInv, trash);
                    int r1 = (((long long) w * pInv % MOD) * dp[w+1][v-1][i+1][j]) % MOD;
                    int r2 = (((long long) (good + i - w) * pInv % MOD) * dp[w][v-1][i+1][j]) % MOD;
                    int r3 = (((long long) (bad - j) * pInv % MOD) * dp[w][v-1][i][j+1]) % MOD;
                    dp[w][v][i][j] = ((long long) r1 + r2 + r3) % MOD;
                    //cout << w << " " << v << " " << i << " " << j << endl;
                    assert(dp[w][v][i][j] >= 0);
                }
            }
        }
    }
    for (int v = 1; v <= m; v++)
    {
        for (int w = 1; w <= MAXW - v; w++)
        {
            for (int i = m - v; i >= 0; i--)
            {
                for (int j = m - v; j >= 0; j--)
                {
                    if (w > bad - j || j > bad)
                        continue;
                    int pInv;
                    modInv(good + bad + i - j, MOD, pInv, trash);
                    int r1 = (((long long) w * pInv % MOD) * dp2[w-1][v-1][i][j+1]) % MOD;
                    int r2 = (((long long) (bad - j - w) * pInv % MOD) * dp2[w][v-1][i][j+1]) % MOD;
                    int r3 = (((long long) (good + i) * pInv % MOD) * dp2[w][v-1][i+1][j]) % MOD;
                    dp2[w][v][i][j] = ((long long) r1 + r2 + r3) % MOD;
                    // cout << w << " " << v << " " << i << " " << j << endl;
                    assert(dp2[w][v][i][j] >= 0);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (likes[i])
        {
            cout << dp[weight[i]][m][0][0] << endl;
        }
        else
        {
            cout << dp2[weight[i]][m][0][0] << endl;
        }
    }

    return 0;
}