#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 2e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> ts;
int used[maxN];
vector<int> g[maxN];

bool dfs(int v) {
    used[v] = 1;
    for (auto &u : g[v]) {
        if (used[u] == 1) return false;
        if (used[u] == 2) continue;
        if (!dfs(u)) return false;
    }
    used[v] = 2;
    ts.push_back(v);
    return true;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        used[i] = 0;
        int k;
        cin >> k;
        range(_, k) {
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            if (!dfs(i)) {
                cout << "-1\n";
                return;
            }
        }
    }
    vector<int> dp(n + 1, 1);
    for (auto &v : ts) {
        for (auto &u : g[v]) {
            dp[v] = max(dp[v], dp[u] + (u > v));
        }
    }
    cout << *max_element(all(dp)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}