#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 2E5;
int pref[4][MAXN + 2];
int suf[4][MAXN + 2];
int threepow[MAXN + 1];
string pat = "?abc";

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    s = "#" + s;
    threepow[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        threepow[i] = (int) ((long long) threepow[i - 1] * 3 % MOD);
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            pref[i][j] = pref[i][j - 1];
            if (j <= n && s[j] == pat[i])
                pref[i][j]++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = n; j >= 0; j--)
        {
            suf[i][j] = suf[i][j + 1];
            if (j > 0 && s[j] == pat[i])
                suf[i][j]++;
        }
    }
    int ans = 0;
    int k = pref[0][n];
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'b')
        {
            temp = (int) ((long long) pref[1][i - 1] * suf[3][i + 1] % MOD);
            temp = (int) ((long long) temp * threepow[k] % MOD);
            add(ans, temp);
            if (k >= 1)
            {
                temp = (int) ((long long) pref[0][i - 1] * suf[3][i + 1] % MOD);
                temp = (int) ((long long) temp * threepow[k - 1] % MOD);
                add(ans, temp);

                temp = (int) ((long long) pref[1][i - 1] * suf[0][i + 1] % MOD);
                temp = (int) ((long long) temp * threepow[k - 1] % MOD);
                add(ans, temp);
            }
            if (k >= 2)
            {
                temp = (int) ((long long) pref[0][i - 1] * suf[0][i + 1] % MOD);
                temp = (int) ((long long) temp * threepow[k - 2] % MOD);
                add(ans, temp);
            }
        }
        if (s[i] == '?')
        {
            temp = (int) ((long long) pref[1][i - 1] * suf[3][i + 1] % MOD);
            temp = (int) ((long long) temp * threepow[k - 1] % MOD);
            add(ans, temp);
            if (k >= 2)
            {
                temp = (int) ((long long) pref[0][i - 1] * suf[3][i + 1] % MOD);
                temp = (int) ((long long) temp * threepow[k - 2] % MOD);
                add(ans, temp);

                temp = (int) ((long long) pref[1][i - 1] * suf[0][i + 1] % MOD);
                temp = (int) ((long long) temp * threepow[k - 2] % MOD);
                add(ans, temp);
            }
            if (k >= 3)
            {
                temp = (int) ((long long) pref[0][i - 1] * suf[0][i + 1] % MOD);
                temp = (int) ((long long) temp * threepow[k - 3] % MOD);
                add(ans, temp);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}