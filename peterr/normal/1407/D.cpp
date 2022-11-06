#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int h[MAXN];
int dp[MAXN];
vector<int> adjList[MAXN];

int conv(int x, int n)
{
    return n - x - 1;
}

void conn(int n, bool rev)
{
    vector<int> mx;
    mx.push_back(0);
    for (int i = 1; i < n; i++)
    {
        while (!mx.empty() && h[mx.back()] < h[i])
        {
            mx.pop_back();
        }
        if (!mx.empty())
        {
            adjList[(rev ? conv(i, n) : i)].push_back((rev ? conv(mx.back(), n) : mx.back()));
            adjList[(rev ? conv(mx.back(), n) : mx.back())].push_back((rev ? conv(i, n) : i));
        }
        mx.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < 2; i++)
    {
        conn(n, false);
        reverse(h, h + n);
        conn(n, true);
        reverse(h, h + n);
        for (int j = 0; j < n; j++)
        {
            h[j] = -h[j];
        }
    }
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = dp[i + 1] + 1;
        for (int adj : adjList[i])
        {
            if (adj < i)
                continue;
            dp[i] = min(dp[i], 1 + dp[adj]);
        }
    }
    cout << dp[0] << "\n";
    return 0;
}