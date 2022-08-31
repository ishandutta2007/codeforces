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
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int used[maxN][2];
vector<int> g[maxN];
bool Draw = false;
vector<int> path;
bool dfs(int v, int c) {
    if (used[v][1] == 1 || used[v][0] == 1) {
        Draw = true;
    }
    if (used[v][c]) return false;
    used[v][c] = 1;
    if (g[v].empty() && c == 1) {
        path.push_back(v);
        return true;
    }
    for(auto &u : g[v]) {
        if (dfs(u, c ^ 1)) {
            path.push_back(v);
            return true;
        }
    }
    used[v][c] = 2;
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        int c; cin >> c;
        range(_, c) {
            int x; cin >> x;
            g[i].push_back(x);
        }
    }
    int s; cin >> s;
    if (dfs(s, 0)) {
        cout << "Win\n";
        reverse(all(path));
        for(auto &v : path) {
            cout << v << ' ';
        }
        return;
    }
    cout << (Draw ? "Draw" : "Lose");
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