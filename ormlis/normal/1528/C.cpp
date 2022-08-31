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
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 1e6 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g1[maxN];
int tin[maxN], tout[maxN];
int ord[maxN];
int T = 1;

void dfs1(int v) {
    ord[T] = v;
    tin[v] = T++;
    for(auto &u : g1[v]) {
        dfs1(u);
    }
    tout[v] = T++;
}

vector<int> g2[maxN];
set<int> s;
int ans = 0;
void dfs2(int v) {
    bool add = false;
    int dele = -1;
    auto it = s.lower_bound(tin[v]);
    if (it == s.end()) {
        add = true;
    } else {
        if ((*it) > tout[v]) {
            add = true;
        }
    }
    if (add && it != s.begin()) {
        --it;
        int p = ord[*it];
        if (tin[p] < tin[v] && tout[v] < tout[p]) {
            dele = tin[p];
            s.erase(it);
        }
    }
    if (add) {
        s.insert(tin[v]);
    }
    ans = max(ans, (int)s.size());
    for(auto &u : g2[v]) {
        dfs2(u);
    }
    if (add) {
        s.erase(tin[v]);
    }
    if (dele != -1) {
        s.insert(dele);
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        g2[i].clear();
        g1[i].clear();
    }
    for(int i = 2; i <= n; ++i) {
        int p; cin >> p;
        g2[p].push_back(i);
    }
    for(int i = 2; i <= n; ++i) {
        int p; cin >> p;
        g1[p].push_back(i);
    }
    ans = 0;
    dfs1(1);
    dfs2(1);
    cout << ans << '\n';
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