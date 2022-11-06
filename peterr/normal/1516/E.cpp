#include <bits/stdc++.h>

using namespace std;

const int MAXK = 200;
const int MOD = 1E9 + 7;
int fac[2 * MAXK + 1];
int invFac[2 * MAXK + 1];
int dp[2 * MAXK + 1][MAXK + 1];
int dp2[2 * MAXK + 1][MAXK + 1];

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % MOD);
        b = (int) ((long long) b * b % MOD);
        e >>= 1;
    }
    return ans;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

int choose(int x, int y)
{
    if (y > x)
        return 0;
    int ans = (int) ((long long) fac[x] * (invFac[y]) % MOD);
    return (int) ((long long) ans * (invFac[x - y]) % MOD);
}

void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fac[0] = invFac[0] = 1;
    for (int i = 1; i <= 2 * MAXK; i++)
    {
        fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
        invFac[i] = modinv(fac[i]);
    }
    int n, k;
    cin >> n >> k;
    dp[0][0] = dp[1][0] = 1;
    for (int i = 2; i <= 2 * MAXK; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= MAXK; j++)
        {
            add(dp[i][j], (int) ((long long) (i - 1) * dp[i - 1][j - 1] % MOD));
            add(dp[i][j], dp[i - 1][j]);
            //cout << "dp " << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    for (int i = 0; i <= 2 * MAXK; i++)
    {
        for (int j = 0; j <= MAXK; j++)
        {
            for (int c = 0; c <= i; c++)
            {
                int temp = choose(i, c);
                temp = (int) ((long long) temp * dp[i - c][j] % MOD);
                if (c & 1)
                    temp = MOD - temp;
                add(dp2[i][j], temp);
            }
            //cout << "dp " << i << " " << j << " " << dp2[i][j] << endl;
        }
    }
    //cout << "HERE" << endl;
    for (int i = 1; i <= k; i++)
    {
        //cout << "iter " << i << endl;
        int ans = 0;
        for (int j = 0; j <= 2 * k; j++)
        {
            //cout << "j " << j << endl;
            if (j > n)
                break;
            int temp = 0;
            for (int c = i; c >= 0; c -= 2)
            {
                add(temp, dp2[j][c]);
            }
            int ch = 1;
            for (int c = 0; c < j; c++)
            {
                ch = (int) ((long long) ch * (n - c) % MOD);
            }
            ch = (int) ((long long) ch * invFac[j] % MOD);
            temp = (int) ((long long) temp * ch % MOD);
            add(ans, temp);
        }
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}