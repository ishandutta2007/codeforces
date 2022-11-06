#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long) 1E18;
const int MAXN = 1E5;
int amb[MAXN];
long long dp[MAXN][4];
string hard = "hard";

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> amb[i];
    }
    dp[0][0] = s[0] == 'h' ? amb[0] : 0;
    dp[0][1] = s[0] == 'h' ? 0 : INF;
    dp[0][2] = dp[0][3] = INF;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + (s[i] == 'h' ? amb[i] : 0);
        //cout << i << " " << 0 << " " << dp[i][0] << endl;
        for (int j = 1; j < 4; j++)
        {
            dp[i][j] = INF;
            if (s[i] != 'h' && s[i] != 'a' && s[i] != 'r' && s[i] != 'd')
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                if (s[i] == hard[j])
                {
                    dp[i][j] = dp[i - 1][j] + amb[i];
                }
                else if (s[i] == hard[j - 1])
                {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }

            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    long long ans = min(dp[n - 1][0], min(dp[n - 1][1], min(dp[n - 1][2], dp[n - 1][3])));
    cout << ans << endl;
    return 0;
}