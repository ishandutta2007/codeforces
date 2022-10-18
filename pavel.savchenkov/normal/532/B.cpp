#include <bits\stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef vector<int> Vint;

const ll inf = (ll)1e18;

void dfs(int x, const vector<Vint> &sons, Vint &a,
         vector<vector<ll> > &dp)
{
    for (int dest : sons[x])
        dfs(dest, sons, a, dp);

    ll mindiff = inf;
    int curd = 0;
    ll cur = 0;
    for (int dest : sons[x])
    {
        if (dp[1][dest] > dp[0][dest])
            curd++, cur += dp[1][dest], mindiff = min(mindiff, dp[1][dest] - dp[0][dest]);
        else
            cur += dp[0][dest], mindiff = min(mindiff, dp[0][dest] - dp[1][dest]);
    }

    curd %= 2;
    dp[curd][x] = cur;
    dp[curd ^ 1][x] = max(cur - mindiff, dp[curd ^ 1][x]);
    dp[1][x] = max(dp[1][x], dp[0][x] + a[x]);
}

void solve(int n)
{
    Vint parent(n + 1);
    Vint a(n + 1);
    vector<Vint> sons(n + 1);

    int p, val;
    for (int i = 1; i <= n; i++)
    {
        scanf(" %d %d", &p, &val);
        parent[i] = p;
        a[i] = val;
        if (p != -1)
            sons[p].pb(i);
    }

    vector<vector<ll> > dp(2, vector<ll>(n + 1, 0));
    dfs(1, sons, a, dp);

    ll best = 0;
    for (int i = 0; i < 2; i++)
    for (int j = 1; j <= n; j++)
        best = max(best, dp[i][j]);

    cout << best << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n;
    while (cin >> n)
        solve(n);
}