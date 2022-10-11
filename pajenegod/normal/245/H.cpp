#include <iostream>

using namespace std;

const int MAXN = 5000 + 10;

string s;
int n, q, dp[MAXN][MAXN];
bool isPal[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = (int)s.size();
    for (int i = 0 ; i < n ; i++)
    {
        isPal[i][i] = 1;
        dp[i][i] = 1;
        isPal[i+1][i] = 1;
    }
    for (int len = 2 ; len <= n ; len++)
        for (int start = 0 ; start <= n-len ; start++)
        {
            isPal[start][start+len-1] = isPal[start+1][start+len-2] & s[start] == s[start+len-1];
            dp[start][start+len-1] = dp[start][start+len-2] + dp[start+1][start+len-1] - dp[start+1][start+len-2] + isPal[start][start+len-1];
        }
    cin >> q;
    for (int i = 1 ; i <= q ; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << dp[l][r] << "\n";
    }
    return 0;
}