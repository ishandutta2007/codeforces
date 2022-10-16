#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

#define int long long
#define pb push_back
#define S second
#define F first
#define f(i, n) for (int i = 0; i < n; i++)
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define vi vector<int>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define precise(x) fixed << setprecision(x)

const int MOD = 1e9 + 7;

int mod_pow(int a, int b, int M = MOD)
{
    if (a == 0)
        return 0;
    b %= (M - 1); // M must be prime here

    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }

    return res;
}

const int N = 5e5 + 100;

vi g[N];

//{ops , max nodes along the subtree chain}
pair<int, int> dfs(int node, int par, int mid)
{
    pair<int, int> res = {0, 1};

    for (auto x : g[node])
    {
        if (x != par)
        {
            auto tmp = dfs(x, node, mid);
            res.first += tmp.first;
            res.second = max(res.second, tmp.second + 1);
        }
    }

    if (node != 1 && par != 1 && res.second == mid)
    {
        res.first++;
        res.second = -1;
    }

    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        g[i + 1].pb(x);
        g[x].pb(i + 1);
    }

    int l = 1;
    int r = n - 1;
    int res = r;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (dfs(1, -1, mid).first <= k)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << res << '\n';

    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
    }
}

signed main()
{
    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}