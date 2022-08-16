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
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int N = 2e5 + 100;
const int MOD = 1e9 + 7;
vi g[N];
int n, m;

void calc(vector<pii>& dat, int src) {
    f(i, n) dat[i] = { N  , 0 };

    dat[src] = { 0 , 1 };

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        auto z = q.front(); q.pop();

        if (z != src) {
            for (auto x : g[z]) {
                if (dat[x].F == dat[z].F - 1) {
                    dat[z].S = (dat[z].S + dat[x].S) % MOD;
                }
            }
        }

        for (auto x : g[z]) {
            if (dat[x].F == N) {
                dat[x].F = dat[z].F + 1;
                q.push(x);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    int s, t;
    cin >> s >> t;
    s--, t--;

    f(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector< pii >  goS(n), goT(n);

    calc(goS, s);
    calc(goT, t);

    int dis = goS[t].F;
    int res = goS[t].S;

    vi ways2(n, 0);

    f(i, n) {

        for (auto x : g[i])
        {
            if (goS[x].F == goS[i].F)
            {
                ways2[i] += goS[x].S;
                ways2[i] %= MOD;
            }
        }

        ways2[i] *= goT[i].S;
        ways2[i] %= MOD;

        if (goS[i].F + goT[i].F == dis)
        {
            res += ways2[i];
            res %= MOD;
        }
    }

    cout << res << '\n';
    f(i, n)g[i].clear();
}

signed main()
{
    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}