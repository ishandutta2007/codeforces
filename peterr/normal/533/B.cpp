#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int val[MAXN + 1];
long long dp[MAXN + 1][2];

void solve(int v, int p)
{
    long long sum = 0;
    bool parity = 0;
    long long diff = 1E11;
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            solve(adj, v);
            sum += max(dp[adj][0], dp[adj][1]);
            if (dp[adj][1] > dp[adj][0])
                parity = !parity;
            diff = min(diff, abs(dp[adj][0] - dp[adj][1]));
        }
    }
    dp[v][parity] = max(0LL, sum);
    dp[v][!parity] = max(0LL, sum - diff);
    vector<long long> delta;
    sum = val[v];
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            sum += dp[adj][0];
            delta.push_back(dp[adj][1] - dp[adj][0]);
        }
    }
    sort(delta.rbegin(), delta.rend());
    long long temp = sum;
    int ptr = 0;
    while (ptr < (int) delta.size() - 1 && delta[ptr] + delta[ptr + 1] > 0)
    {
        temp += delta[ptr] + delta[ptr + 1];
        ptr += 2;
    }
    dp[v][1] = max(dp[v][1], temp);
    //cout << v << " " << 0 << " " << dp[v][0] << endl;
    //cout << v << " " << 1 << " " << dp[v][1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int p, a;
        cin >> p >> a;
        if (i > 1)
        {
            adjList[i].push_back(p);
            adjList[p].push_back(i);
        }
        val[i] = a;
    }
    solve(1, 1);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}