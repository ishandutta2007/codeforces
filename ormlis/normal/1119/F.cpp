#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

ll cost[maxN];
int U[maxN], V[maxN];
vector<pair<int, int>> g[maxN], g2[maxN];
ll dp[maxN][2];
int T = 1;

struct kek_struct {
    multiset<ll> L, R;
    ll sumL = 0;

    void update_size(int s) {
        s = max(s, 0);
        while ((int) L.size() < s) {
            sumL += *R.begin();
            L.insert(*R.begin());
            R.erase(R.begin());
        }
        while ((int) L.size() > s) {
            R.insert(*L.rbegin());
            sumL -= *L.rbegin();
            L.erase(prev(L.end()));
        }
    }

    void insert(ll x) {
        if (R.empty() || x <= (*R.begin())) {
            L.insert(x);
            sumL += x;
        } else {
            R.insert(x);
        }
    }

    void erase(ll x) {
        if (R.find(x) == R.end()) {
            L.erase(L.find(x));
            sumL -= x;
        } else R.erase(R.find(x));
    }
};

kek_struct ss[maxN];
int was[maxN];

void dfs(int v, int p, int cur) {
    dp[v][0] = 0;
    dp[v][1] = 0;
    vector<ll> can;
    was[v] = T;
    int need = (int)g2[v].size() - cur;
    for (auto &[u, i] : g[v]) {
        if (u == p) {
            dp[v][1] += cost[i];
            continue;
        }
        dfs(u, v, cur);
        if (dp[u][1] <= dp[u][0]) {
            need--;
            dp[v][0] += dp[u][1];
            dp[v][1] += dp[u][1];
            continue;
        }
        dp[v][0] += dp[u][0];
        dp[v][1] += dp[u][0];
        can.push_back(dp[u][1] - dp[u][0]);
        ss[v].insert(dp[u][1] - dp[u][0]);
    }
    if (cur == 0 && p != -1) {
        dp[v][0] = INF;
    } else{
        ss[v].update_size(need);
        dp[v][0] += ss[v].sumL;
    }
    ss[v].update_size(need - 1);
    dp[v][1] += ss[v].sumL;
    for(auto &x : can) ss[v].erase(x);
}


void solve() {
    int n;
    cin >> n;
    range(i, n - 1) {
        cin >> U[i] >> V[i] >> cost[i];
        g2[U[i]].emplace_back(V[i], i);
        g2[V[i]].emplace_back(U[i], i);
        ss[U[i]].insert(cost[i]);
        ss[V[i]].insert(cost[i]);
    }
    vector<vector<int>> to(n);
    range(i, n) to[g2[i + 1].size()].push_back(i + 1);
    vector<ll> ans(n);
    vector<int> cur;
    for(int i = n - 1; i >= 0; --i) {
        T++;
        for(auto &v : cur) {
            if (was[v] == T) continue;
            dfs(v, -1, i);
            ans[i] += dp[v][0];
        }
        for(auto &v : to[i]) {
            cur.push_back(v);
            was[v] = T;
            for(auto &[u, i] : g2[v]) {
                if (was[u] == T) {
                    g[u].emplace_back(v, i);
                    g[v].emplace_back(u, i);
                    ss[u].erase(cost[i]);
                    ss[v].erase(cost[i]);
                }
            }
        }
    }
    range(i, n) cout << ans[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}