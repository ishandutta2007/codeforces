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

const int INFi = 1e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g[maxN];
int col[maxN];

int d = -1;
int f = -1;

void find_d(int v, int p, int c) {
    if (c > d) {
        d = c;
        f = v;
    }
    for (auto &u : g[v]) {
        if (u == p) continue;
        find_d(u, v, c + 1);
    }
}

vector<int> path;
vector<int> stk;

void find_path(int v, int p) {
    stk.push_back(v);
    if (v == f) {
        path = stk;
    }
    for (auto &u : g[v]) {
        if (u == p) continue;
        find_path(u, v);
    }
    stk.pop_back();
}

vector<int> was;

int max_h(int v, int p) {
    int r = 0;
    was.push_back(v);
    for (auto &u : g[v]) {
        if (u == p) continue;
        r = max(r, max_h(u, v) + 1);
    }
    return r;
}

void color(int v, int p, int c, int step, int k) {
    c += step;
    if (c < 0) c += k;
    if (c == k) c = 0;
    col[v] = c;
    for (auto &u : g[v]) {
        if (u == p) continue;
        color(u, v, c, step, k);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    find_d(1, -1, 0);
    int a = f;
    d = f = -1;
    find_d(a, -1, 0);
    int b = f;
    int dia = d;
    if (dia + 1 < k || k == 1) {
        cout << "YES\n";
        range(_, n) cout << "1 ";
        cout << '\n';
        return;
    }
    if (k == 2) {
        color(1, -1, 0, 1, k);
        cout << "YES\n";
        for(int i = 1; i <= n; ++i) {
            cout << col[i] + 1 << ' ';
        }
        cout << '\n';
        return;
    }
    f = b;
    find_path(a, -1);
    assert(path.size() == dia + 1);
    range(i, dia + 1) {
        col[path[i]] = i % k;
    }
    range(i, dia + 1) {
        was.clear();
        int v = path[i];
        vector<int> ch;
        int H = 0;
        for (auto &u : g[v]) {
            if (i != dia && u == path[i + 1]) continue;
            if (i != 0 && u == path[i - 1]) continue;
            ch.push_back(u);
            H = max(H, max_h(u, v) + 1);
        }
        if (ch.empty()) continue;
        int d1 = H + i + 1;
        int d2 = H + dia - i + 1;
        if (min(d2, d1) >= k) {
            cout << "NO\n";
            return;
        }
        if (max(d2, d1) < k) {
            for (auto &kek : was) {
                col[kek] = 0;
            }
            continue;
        }
        if (d1 < d2) {
            for (auto &u : ch) {
                color(u, v, col[v], -1, k);
            }
        } else {
            for(auto &u : ch) {
                color(u, v, col[v], 1, k);
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i) cout << col[i] + 1 << ' ';
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