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

const int N = 2e5 + 100;

vector<pair<int, pii>> g[N];
int res[N];

// g[source] = {target , {a[i] , b[i]}};

vector<int> pref;

void dfs(int node, int par, int ss)
{
    int last_b_sum = 0;

    if (!pref.empty())
    {
        res[node] = upper_bound(all(pref), ss) - pref.begin();

        last_b_sum = pref.back();
    }

    for (auto x : g[node])
    {
        if (x.first == par)
            continue;

        pref.push_back(last_b_sum + x.second.second);

        dfs(x.first, node, ss + x.second.first);

        pref.pop_back();
    }
}

void solve()
{
    int n;
    cin >> n;

    int p, a, b;

    f(i, n - 1)
    {
        cin >> p >> a >> b;

        g[i + 2].pb({p, {a, b}});
        g[p].pb({i + 2, {a, b}});
    }

    dfs(1, -1, 0);

    for (int i = 2; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';

    for (int i = 1; i <= n; i++)
        g[i].clear();
}

signed main()
{
    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}