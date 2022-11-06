#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
const int MAXP = 14;
int pi[MAXN][MAXN];
int len[MAXN][MAXN];
int lift[MAXN][MAXP + 1];
int dp[MAXN];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        string temp = s.substr(i, (int) s.length() - i);
        for (int j = 1; j < (int) temp.length(); j++)
        {
            int k = pi[i][j - 1];
            while (k > 0 && temp[j] != temp[k])
                k = pi[i][k - 1];
            pi[i][j] = k;
            if (temp[j] == temp[k])
                pi[i][j]++;
        }
        for (int j = 1; j < (int) temp.length(); j++)
        {
            lift[j][0] = pi[i][j - 1];
        }
        for (int k = 1; k <= MAXP; k++)
        {
            for (int j = 0; j < (int) temp.length(); j++)
                lift[j][k] = lift[lift[j][k - 1] - 1][k - 1];
        }
        for (int j = (int) temp.length() - 1; j >= 1; j--)
        {
            int x = pi[i][j];
            for (int k = MAXP; k >= 0; k--)
            {
                while (lift[x][k] > (j + 1) / 2)
                    x = lift[x][k];
            }
            if (x > (j + 1) / 2)
                x = pi[i][x - 1];
            pi[i][j] = x;
            /*
            while (pi[i][j] > (j + 1) / 2)
                pi[i][j] = pi[i][pi[i][j] - 1];
            */
            //cout << i << " " << j << " " << pi[i][j] << endl;
        }
    }
    dp[0] = a;
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + a;
        for (int j = 0; j < i; j++)
        {
            if (pi[j][i - j] > 0)
                dp[i] = min(dp[i], b + dp[i - pi[j][i - j]]);
        }
        //cout << i << " " << dp[i] << endl;
    }
    cout << dp[n - 1] << endl;
    return 0;
}