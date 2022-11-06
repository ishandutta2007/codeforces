#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 3E5;
int dp[MAXN + 1][3];
int ans[MAXN + 1];
vector<int> adjList[MAXN + 1];
int threePow[MAXN + 1];
int twoPow[MAXN + 1];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

void solve(int v, int p)
{
    dp[v][0] = dp[v][1] = dp[v][2] = 1;
    int sub = 1;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        solve(adj, v);
        int temp = (int) (((long long) 2 * ans[adj]) % MOD);
        add(temp, dp[adj][2]);
        add(temp, 3);
        dp[v][0] = (int) (((long long) dp[v][0] * temp) % MOD);
        temp = ans[adj];
        add(temp, 2);
        add(temp, dp[adj][0]);
        dp[v][1] = (int) (((long long) dp[v][1] * temp) % MOD);
        dp[v][2] = (int) (((long long) dp[v][2] * (ans[adj] + 1)) % MOD);
        sub = (int) (((long long) sub * (ans[adj] + 1)) % MOD);
    }
    add(dp[v][0], MOD - 1);
    //add(dp[v][1], MOD - 1);
    add(dp[v][1], MOD - sub);
    add(dp[v][2], MOD - 1);
    add(ans[v], dp[v][0]);
    add(ans[v], dp[v][1]);
    //cout << v << " " << 0 << " " << dp[v][0] << endl;
    //cout << v << " " << 1 << " " << dp[v][1] << endl;
    //cout << v << " " << 2 << " " << dp[v][2] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    threePow[0] = twoPow[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        threePow[i] = (int) (((long long) threePow[i - 1] * 3) % MOD);
        twoPow[i] = (int) (((long long) twoPow[i - 1] * 2) % MOD);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    solve(1, 1);
    cout << ans[1] << endl;
    return 0;
}