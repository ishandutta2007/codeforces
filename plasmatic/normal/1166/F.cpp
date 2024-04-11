// f-vickys-delivery-service.yml
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

const int MN = 1e5 + 1, MX = 5e5 + 1;
int N, M, C, Q;

set<int> adj[MX];
int dsu[MX];
void init() { iota(dsu, dsu + MX, 0); }
int rt(int x) { return x == dsu[x] ? x : dsu[x] = rt(dsu[x]); }
void unite(int x, int y) { 
    // cout<<"[un]: "; cout<<"x="<<(x)<<", "; cout<<"y="<<(y)<<", "; cout << endl; // db l:un,x,y
    x = rt(x); y = rt(y);
    if (x == y) return;
    if (SZ(adj[y]) > SZ(adj[x])) swap(adj[x], adj[y]);
    adj[x].insert(all(adj[y]));
    adj[y].clear();
    dsu[y] = x;
}
bool same(int x, int y) { return rt(x) == rt(y); }

int cnode;
int getNode() { return ++cnode; }
map<int, int> clrId[MN];

int getClrNode(int x, int clr) {
    if (!clrId[x].count(clr))
        clrId[x][clr] = getNode();
    return clrId[x][clr];
}

void addRoad(int a, int b, int c, bool SW = true) {
    int cn = getClrNode(b, c);
    adj[rt(a)].insert(b);
    unite(a, cn);
    if (SW) addRoad(b, a, c, false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M) >> (C) >> (Q);

    cnode = N;
    init();

    for (auto i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        addRoad(a, b, c);
    }

    while (Q--) {
        char T; int a, b;
        cin >> T >> a >> b;
        if (T == '?') {
            int ra = rt(a), rb = rt(b);
            if (ra == rb)
                cout << ("Yes") << '\n';
            else
                cout << (adj[ra].count(b) ? "Yes" : "No") << '\n';
        }
        else {
            int c;
            cin >> c;
            addRoad(a, b, c);
        }
    }

    return 0;
}