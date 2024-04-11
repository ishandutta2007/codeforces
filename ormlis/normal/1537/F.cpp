#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g[maxN];
bool used[maxN];
ll a[maxN];
int colors[maxN];
pair<int, int> edge = {-1, -1};

void dfs(int v) {
    used[v] = true;
    for(auto &u : g[v]) {
        if (used[u]) {
            if (colors[u] == colors[v]) {
                edge = {u, v};
            }
            continue;
        }
        colors[u] = colors[v] ^ 1;
        dfs(u);
        a[v] -= a[u];
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        a[i] = 0;
        used[i] = false;
        colors[i] = 0;
        g[i].clear();
    }
    range(i, n) {
        int x; cin >> x;
        a[i + 1] -= x;
    }
    range(i, n) {
        int x; cin >> x;
        a[i + 1] += x;
    }
    range(_, m) {
        int i, j; cin >> i >> j;
        g[i].emplace_back(j);
        g[j].emplace_back(i);
    }
    edge.first = -1;
    dfs(1);
    if (a[1] == 0) {
        cout << "YES\n";
        return;
    }
    if (edge.first == -1 || a[1] % 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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