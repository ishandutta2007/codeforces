// d-graph-and-queries.yml
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
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

struct qu {
    int t, v;

    int rep;
};
istream& operator>>(istream &in, qu &o) {
    return in >> o.t >> o.v;
}

const int MN = 2e5 + 1, MM = 3e5 + 1, MQ = 5e5 + 1;
int N, M, Q,
    P[MN], A[MM], B[MM];
vector<qu> qus;

// tree stuff
bool vis[MN*2];
int in[MN*2], out[MN*2], epos = 0;
vector<int> g[MN*2];
void dfs(int c, int p) {
    vis[c] = true;
    in[c] = ++epos;
    for (int to : g[c])
        if (to != p)
            dfs(to, c);
    out[c] = epos;
}

// dsu
int dsu[MN], rep[MN], cpos;
int rt(int x) { return dsu[x] == x ? x : dsu[x] = rt(dsu[x]); }
void unite(int x, int y) {
    x = rt(x); y = rt(y);
    if (x == y) return;
    int nr = ++cpos;
    g[rep[x]].pb(nr); g[nr].pb(rep[x]);
    g[rep[y]].pb(nr); g[nr].pb(rep[y]);
    rep[x] = nr;
    dsu[y] = x;
}

// segtree
const int MS = 524288;
pii seg[MS*2];
void update(int i, pii v) {
    if (i == 0) return; // trying to update with 0
    seg[i += MS] = v;
    for (i >>= 1; i; i >>= 1)
        seg[i] = max(seg[i*2], seg[i*2+1]);
}
pii query(int l, int r) {
    pii res;
    for (l += MS, r += MS; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) maxa(res, seg[l]), l++;
        if (!(r & 1)) maxa(res, seg[r]), r--;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M) >> (Q);
    for (auto i = 1; i <= N; i++)
        cin >> (P[i]);
    for (auto i = 0; i < M; i++)
        cin >> (A[i]) >> (B[i]);

    // add extra queries at the end so everything has been removed
    vector<bool> rem(MM);
    for (auto i = 0; i < Q; i++) {
        qu q;
        cin >> q;
        if (q.t == 2) {
            q.v--;
            rem[q.v] = true;
        }
        qus.pb(q);
    }
    for (auto i = 0; i < M; i++)
        if (!rem[i])
            qus.pb({2, i, -1});
    
    // init dsu
    iota(dsu, dsu + MN, 0);
    iota(rep, rep + MN, 0);
    cpos = N;
    // build "DSU Tree"
    for (auto it = qus.rbegin(); it != qus.rend(); it++) {
        auto &q = *it;
        // cout<<"q.t="<<(q.t)<<", "; cout<<"q.v="<<(q.v)<<", "; cout << endl; // db q.t,q.v
        if (q.t == 2) {
            unite(A[q.v], B[q.v]);
            // cout<<"[un]: "; cout<<"A[q.v]="<<(A[q.v])<<", "; cout<<"B[q.v]="<<(B[q.v])<<", "; cout << endl; // db l:un,A[q.v],B[q.v]
        }
        else {
            // cout<<"rt(q.v)="<<(rt(q.v))<<", "; cout<<"rep[rt(q.v)]="<<(rep[rt(q.v)])<<", "; cout << endl; // db rt(q.v), rep[rt(q.v)]
            q.rep = rep[rt(q.v)];
        }
    }
    // for (auto i = 1; i <= cpos; i++)
    //     for (auto j : g[i])
    //         if (i<j)
    //             cout << (i) << ' ' << (j) << '\n';
    // do dfs to get euler tour stuff
    epos = 0;
    for (auto i = cpos; i >= 1; i--) // start from latest nodes because those are garunteed to be more "root" (they're added later when merging bigger components, so that means node #cpos is garunteed to be merging the last two components for example)
        if (!vis[i])
            dfs(i, -1);
    // init segtree
    for (auto i = 1; i <= N; i++)
        update(in[i], mpr(P[i], in[i]));

    // answer queries
    for (auto &q : qus) {
        if (q.t == 1) {
            pii ans = query(in[q.rep], out[q.rep]);
            cout << (ans.fs) << '\n';
            update(ans.sn, mpr(0, 0));
        }
    }

    return 0;
}