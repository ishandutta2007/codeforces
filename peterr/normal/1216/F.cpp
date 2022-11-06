#include <bits/stdc++.h>

using namespace std;

long long INF = 1E18;
const int MAXN = 2E5;
long long dp[MAXN + 1][2];
bool router[MAXN + 1];

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++)
        router[i] = s[i - 1] == '1';
    dp[1][1] = 1;
    dp[1][0] = INF;
    deque<int> minSt;
    if (router[1])
        minSt.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        if (!minSt.empty() && minSt.front() < i - k)
            minSt.pop_front();
        int prev = max(0, i - k - 1);
        if (router[i])
        {
            dp[i][1] = INF;
            if (!minSt.empty())
                dp[i][1] = i + dp[minSt.front()][1];
            dp[i][1] = min(dp[i][1], i + min(dp[prev][0], dp[prev][1]));
        }
        else
            dp[i][1] = i + min(dp[i - 1][0], dp[i - 1][1]);
        if (minSt.empty())
            dp[i][0] = INF;
        else
        {
            dp[i][0] = dp[minSt.front()][1];
        }
        if (router[i])
        {
            while (!minSt.empty() && dp[i][1] <= dp[minSt.back()][1])
                minSt.pop_back();
            minSt.push_back(i);
        }
        //cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
    return 0;
}