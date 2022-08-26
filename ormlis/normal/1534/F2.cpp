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
const int maxN = 4e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g[maxN], gr[maxN];
int comp[maxN];
bool has[maxN];
int N;
bool used[maxN];
vector<int> ts;
void dfs1(int v) {
    used[v] = 1;
    for(auto &u : gr[v]) {
        if (used[u]) continue;
        dfs1(u);
    }
    ts.push_back(v);
}

int c = 0;
void dfs2(int v) {
    comp[v] = c;
    for(auto &u : g[v]) {
        if (comp[u]) continue;
        dfs2(u);
    }
}

vector<int> gc[maxN];

void compress() {
    for(int i = 0; i < N; ++i) {
        for(auto &u : g[i]) {
            gr[u].emplace_back(i);
        }
    }
    range(i, N) {
        if (used[i]) continue;
        dfs1(i);
    }
    reverse(all(ts));
    for(auto &v : ts) {
        if (comp[v]) continue;
        c++;
        dfs2(v);
    }
    range(v, N) {
        for(auto &u : g[v]) {
            if (comp[u] == comp[v]) continue;
            gc[comp[v]].push_back(comp[u]);
        }
    }
    for(int i = 1; i <= c; ++i) {
        sort(all(gc[i]));
        gc[i].resize(unique(all(gc[i])) - gc[i].begin());
    }
}

bool was[maxN];
void dfs3(int v) {
    was[v] = true;
    for(auto &u : gc[v]) {
        if (was[u]) continue;
        dfs3(u);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(n);
    range(i, n) cin >> s[i];
    vector<int> a(m);
    range(i, m) cin >> a[i];
    auto get = [&] (int i, int j) {
        return i * m + j;
    };
    N = n * m;
    int sub = 0;
    range(j, m) {
        range(i, n) {
            int v = get(i, j);
            if (i + 1 < n) {
                g[v].emplace_back(get(i + 1, j));
            }
            if (s[i][j] == '.') {
                continue;
            }
            if (i) {
                g[v].emplace_back(get(i - 1, j));
            }
            if (j + 1 < m) {
                g[v].emplace_back(get(i, j + 1));
            }
            if (j) {
                g[v].emplace_back(get(i, j - 1));
            }
        }
    }
    compress();
    vector<pair<int, int>> have;
    range(j, m) {
        if (a[j] == 0) continue;
        int x = 0;
        for(int i = n - 1; i >= 0; --i) {
            if (s[i][j] == '#') {
                x++;
                if (x == a[j]) {
                    int v = comp[get(i, j)];
                    have.emplace_back(v, j);
                    break;
                }
            }
        }
    }
    sort(rall(have));
    vector<pair<int, int>> need;
    vector<int> l(c + 1, INFi);
    vector<int> r(c + 1, -INFi);
    for(auto &[v, j] : have) {
        if (was[v]) continue;
        dfs3(v);
        need.emplace_back(j, v);
    }
    sort(all(need));
    range(i, (int)need.size()) {
        int v = need[i].second;
        l[v] = min(l[v], i);
        r[v] = max(r[v], i);
    }
    int sz = (int)need.size();
    vector<pair<int, int>> can;
    for(int i = 1; i <= c; ++i) {
        for(auto &u : gc[i]) {
            l[i] = min(l[i], l[u]);
            r[i] = max(r[i], r[u]);
        }
        if (l[i] == INFi) continue;
        can.emplace_back(l[i], r[i]);
    }
    sort(all(can));
    int nxt = 0;
    int mxR = -1;
    int ans = 0;
    for(auto &[l, r] : can) {
        if (l > nxt) {
            nxt = mxR + 1;
            ans++;
        }
        if (l <= nxt) {
            mxR = max(mxR, r);
            continue;
        }
    }
    if (nxt != sz) {
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}