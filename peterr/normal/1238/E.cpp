#include <bits/stdc++.h>

using namespace std;

const int INF = 2E6;
const int MAXM = 20;
int dp[1 << MAXM];
int num[1 << MAXM];
int adj[MAXM][MAXM];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; i++)
    {
        int a = s[i] - 'a';
        int b = s[i + 1] - 'a';
        if (a == b)
            continue;
        adj[a][b]++;
        adj[b][a]++;
    }
    for (int i = 1; i < (1 << m); i++)
    {
        int lo = __builtin_ctz(i & -i);
        num[i] = num[i ^ (1 << lo)];
        for (int j = 0; j < m; j++)
        {
            if (j == lo)
                continue;
            if (i & (1 << j))
                num[i] -= adj[lo][j];
            else
                num[i] += adj[lo][j];
        }
    }
    for (int i = 1; i < (1 << m); i++)
    {
        dp[i] = INF;
        for (int j = 0; j < m; j++)
        {
            if (!(i & (1 << j)))
                continue;
            dp[i] = min(dp[i], dp[i ^ (1 << j)] + num[i]);
        }
    }
    cout << dp[(1 << m) - 1] << "\n";
    return 0;
}