// ./d-choosing-subtree-is-fun.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

ostream& operator<<(ostream& out, const pii o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}

const int MN = 1e5 + 1, LG = 17;
int N, K;
vector<int> g[MN];

int cord = 0,
    tb[LG][MN], dep[MN], dfn[MN];

void dfs(int c, int p) {
    tb[0][c] = p;
    dfn[c] = ++cord;
    for (int to : g[c]) {
        if (to != p) {
            dep[to] = dep[c] + 1;
            dfs(to, c);
        }
    }
}

int lca(int a, int b) {
    if (a == b) return a;
    if (dep[a] > dep[b]) swap(a, b);
    int delta = dep[b] - dep[a];
    for (auto i = 0; i < LG; i++)
        if ((delta >> i) & 1)
            b = tb[i][b];
    if (a == b) return a;
    for (auto i = LG-1; i >= 0; i--) {
        if (tb[i][a] != tb[i][b]) {
            a = tb[i][a];
            b = tb[i][b];
        }
    }
    return tb[0][a];
}
int dis(int a, int b) { return dep[a] + dep[b] - 2 * dep[lca(a, b)]; }

int cans = 0, plen = 0;
set<pii> use;

void change(int x, bool ins) {
    auto nxt = use.lower_bound({dfn[x], x}), pre = nxt; pre--;
    if (!ins) nxt++;
    int mul = ins ? 1 : -1;

    if (nxt->sn != -1 && pre->sn != -1)
        plen -= dis(pre->sn, nxt->sn) * mul;
    if (pre->sn != -1) 
        plen += dis(pre->sn, x) * mul;
    if (nxt->sn != -1)
        plen += dis(x, nxt->sn) * mul;

    if (ins) use.emplace(dfn[x], x);
    else use.erase({dfn[x], x});

    int tpl = plen + dis((++use.begin())->sn, (--(--use.end()))->sn);
    cans = tpl / 2 + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (K);
    for (auto i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1, -1);
    for (auto i = 1; i < LG; i++) {
        for (auto j = 1; j <= N; j++) {
            int pp = tb[i - 1][j];
            tb[i][j] = pp == -1 ? -1 : tb[i - 1][pp];
        }
    }


    use.emplace(-INF, -1); use.emplace(INF, -1);
    int ans = 0, r = 0;
    for (auto l = 1; l <= N; l++) {
        while (r < N && cans <= K)
            change(++r, 1);
        if (cans > K)
            change(r--, 0);

        maxa(ans, r - l + 1);
        change(l, 0);
    }

    cout << (ans) << '\n';

    return 0;
}