#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 3E5;
int dp[MAXN + 1];
int twopow[MAXN + 1];
string board[MAXN];

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
    twopow[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        twopow[i] = (int) ((long long) twopow[i - 1] * 2 % MOD);
    }
    for (int i = 2; i <= MAXN; i++)
    {
        dp[i] = twopow[i - 2];
        add(dp[i], dp[i - 1]);
        add(dp[i], (int) ((long long) dp[i - 2] * 2 % MOD));
        //cout << i << " " << dp[i] << endl;
    }
    int n, m;
    cin >> n >> m;
    int white = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for (char ch : board[i])
            white += ch == 'o';
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int ptr = 0;
        while (ptr < m)
        {
            if (board[i][ptr] == 'o')
            {
                int cnt = 0;
                while (ptr < m && board[i][ptr] == 'o')
                {
                    cnt++;
                    ptr++;
                }
                add(ans, (int) ((long long) dp[cnt] * twopow[white - cnt] % MOD));
            }
            else
                ptr++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int ptr = 0;
        while (ptr < n)
        {
            if (board[ptr][i] == 'o')
            {
                int cnt = 0;
                while (ptr < n && board[ptr][i] == 'o')
                {
                    cnt++;
                    ptr++;
                }
                add(ans, (int) ((long long) dp[cnt] * twopow[white - cnt] % MOD));
            }
            else
                ptr++;
        }
    }
    cout << ans << "\n";
    return 0;
}