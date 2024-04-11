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

int compress() {
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
    range(i, N) {
        for(auto &u : g[i]) {
            if (comp[u] != comp[i]) has[comp[u]] = true;
        }
    }
    int res =0 ;
    for(int i = 1; i <= c; ++i) {
        if (!has[i]) res++;
    }
    return res;
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
        if (a[j] == 0) {
            sub += n;
            continue;
        }
        bool was = false;
        range(i, n) {
            int v = get(i, j);
            if (i + 1 < n) {
                g[v].emplace_back(get(i + 1, j));
            }
            if (s[i][j] == '.') {
                continue;
            }
            if (!was) {
                was = true;
                if (i) {
                    g[v].emplace_back(get(0, j));
                }
            }
            if (i) {
                g[v].emplace_back(get(i - 1, j));
            }
            if (j + 1 < m && a[j + 1]) {
                g[v].emplace_back(get(i, j + 1));
            }
            if (j && a[j - 1]) {
                g[v].emplace_back(get(i, j - 1));
            }
        }
    }
    cout << compress() - sub << '\n';
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