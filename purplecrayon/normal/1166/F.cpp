#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

// (node, color taken)
// still linear number of states because sum{color taken} = m
// (a, b, c) ->
//      (a*, b_c)
//      (b*, a_c)
//

int n, C, q;
ar<int, 3> e[2*MAXN];
map<int, int> me_col[MAXN];

int cur_node = 0;
int make_node() {
    return cur_node++;
}

const int N = 5*MAXN;
int p[N];
vector<int> st[N];
set<int> node_id[N]; // size n + m

void union_sets(int a, int b) {
    a = p[a], b = p[b];
    if (a == b) return;
    if (sz(st[a]) < sz(st[b])) swap(a, b);

    for (auto x : st[b]) st[a].push_back(x), p[x] = a;
    st[b].clear();

    for (auto x : node_id[b]) node_id[a].insert(x);
    node_id[b].clear();
}

void solve() {
    int m; cin >> n >> m >> C >> q;
    q += m;
    for (int i = 0; i < q; i++) {
        char t = '+';
        if (i >= m) cin >> t;
        if (t == '+') {
            int a, b, c; cin >> a >> b >> c, --a, --b, --c;
            e[i] = {a, b, c};

            me_col[a].emplace(c, -1), me_col[b].emplace(c, -1);
        } else {
            int a, b; cin >> a >> b, --a, --b;
            e[i] = {a, b, -1};
        }
    }
    // if any of b_* are connected to a*
    // store node id's when merging

    for (int i = 0; i < n; i++) {
        me_col[i][-1] = -1; // i*
        for (auto& x : me_col[i]) {
            x.second = make_node();
            node_id[x.second].insert(i);
        }
    }
    assert(cur_node <= n + 2 * q);
    for (int i = 0; i < cur_node; i++) p[i] = i, st[i].push_back(i);

    for (int i = 0; i < q; i++) {
        auto [a, b, c] = e[i];
        if (c != -1) {
            int a_star = me_col[a][-1], a_c = me_col[a][c];
            int b_star = me_col[b][-1], b_c = me_col[b][c];
            union_sets(a_star, b_c);
            union_sets(b_star, a_c);
        } else {
            int a_star = me_col[a][-1];
            bool ans = node_id[p[a_star]].count(b);
            cout << (ans ? "Yes\n" : "No\n");
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}