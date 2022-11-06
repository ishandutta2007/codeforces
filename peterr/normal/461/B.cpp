#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MOD = 1E9 + 7;
vector<int> adjList[MAXN];
bool isBlack[MAXN];
int dp[MAXN][2];

int modInv(int x)
{
    int k = MOD - 2;
    int ans = 1;
    while (k)
    {
        if (k & 1)
        {
            ans = (int) (((long long) ans * x) % MOD);
        }
        k >>= 1;
        x = (int) (((long long) x * x) % MOD);
    }
    return ans;
}

void solve(int v, int p)
{
    int prod = 1;
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            solve(adj, v);
            int sum = dp[adj][0] + dp[adj][1];
            if (sum >= MOD)
                sum -= MOD;
            prod = (int) (((long long) prod * sum) % MOD);
        }
    }
    if (isBlack[v])
    {
        dp[v][0] = 0;
        dp[v][1] = prod;
    }
    else
    {
        dp[v][0] = prod;
        for (int adj : adjList[v])
        {
            if (adj != p)
            {
                int sum = dp[adj][0] + dp[adj][1];
                if (sum >= MOD)
                    sum -= MOD;
                int temp = (int) (((long long) dp[adj][1] * prod) % MOD);
                temp = (int) (((long long) temp * modInv(sum)) % MOD);
                dp[v][1] += temp;
                if (dp[v][1] >= MOD)
                    dp[v][1] -= MOD;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int p;
        cin >> p;
        adjList[i].push_back(p);
        adjList[p].push_back(i);
    }
    for (int i = 0; i < n; i++)
        cin >> isBlack[i];
    solve(0, 0);
    cout << dp[0][1] << "\n";
    return 0;
}