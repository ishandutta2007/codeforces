#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


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
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int tp[maxN];
vector<int> g[maxN];
int rt[maxN];
int ans[maxN];

void dfs1(int v) {
    if (tp[v] == 4) return;
    for(auto &u : g[v]) {
        dfs1(u);
    }
    if (tp[v] == 3) {
        rt[v] = rt[g[v][0]] ^ 1;
        return;
    }
    int a = g[v][0];
    int b = g[v][1];
    if (tp[v] == 0) {
        rt[v] = rt[a] & rt[b];
    } else if (tp[v] == 1) {
        rt[v] = rt[a] | rt[b];
    } else if (tp[v] == 2) {
        rt[v] = rt[a] ^ rt[b];
    }
}

void dfs2(int v, ar<int, 2> res) {
    if (tp[v] == 4) {
        ans[v] = res[rt[v]^1];
        return;
    }
    int a = g[v][0];
    if (tp[v] == 3) {
        swap(res[0], res[1]);
        dfs2(a, res);
        return;
    }
    int b = g[v][1];
    int c = a ^ b;
    for(auto &u : g[v]) {
        ar<int, 2> res2 = {0, 0};
        if (tp[v] == 0) {
            range(r, 2) {
                res2[r] = res[r&rt[c^u]];
            }
        } else if (tp[v] == 1) {
            range(r, 2) {
                res2[r] = res[r|rt[c^u]];
            }
        } else {
            range(r, 2) {
                res2[r] = res[r^rt[c^u]];
            }
        }
        dfs2(u, res2);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        if (s[0] == 'A') {
            tp[i] = 0;
            int a, b;
            cin >> a >> b;
            g[i].push_back(a);
            g[i].push_back(b);
        } else if (s[0] == 'O') {
            tp[i] = 1;
            int a, b;
            cin >> a >> b;
            g[i].push_back(a);
            g[i].push_back(b);
        } else if (s[0] == 'X') {
            tp[i] = 2;
            int a, b;
            cin >> a >> b;
            g[i].push_back(a);
            g[i].push_back(b);
        } else if (s[0] == 'N') {
            tp[i] = 3;
            int a;
            cin >> a;
            g[i].push_back(a);
        } else {
            int value;
            cin >> value;
            tp[i] = 4;
            rt[i] = value;
        }
    }
    dfs1(1);
    ar<int, 2> res = {0, 1};
    dfs2(1, res);
    for(int i = 1; i <= n; ++i) {
        if (tp[i] == 4) {
            cout << ans[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}