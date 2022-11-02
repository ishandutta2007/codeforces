#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
 
#include <bits/stdc++.h>
using namespace std;
 
template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void rsort(T1 &arr) { sort(arr.rbegin(), arr.rend()); }
template<typename T1> inline void shuffle(T1 &arr) {
    for (int i = -int(arr.size()); i < arr.size(); ++i) {
        int f = ((rand() << 16) + rand()) % arr.size(), s = ((rand() << 16) + rand()) % arr.size();
        swap(arr[f], arr[s]);
    }
}
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;
 
const ll MAXN = 400000;

graph G(MAXN), dag(MAXN);
vector<ll> fup(MAXN);
vector<bool> used(MAXN), usedf(MAXN), useds(MAXN);
vector<ll> depth(MAXN);
set<pll> bridges;
map<pll, ll> edges;
map<ll, ll> color;
ll dv, maxd;
ll comp;

void dfsfup(int v, int d = 0, int p = -1) {
    used[v] = true;
    depth[v] = d;
    fup[v] = d;
    for (auto i : G[v])
        if (!used[i]) {
            dfsfup(i, d + 1, v);
            checkmin(fup[v], fup[i]);
        } else if (i != p)
            checkmin(fup[v], fup[i]);
    if (fup[v] == depth[v] && p >= 0)
        bridges.insert(mp(p, v));
}

void dfscomp(int v, int comp) {
    used[v] = true;
    color[v] = comp;
    for (auto i : G[v])
        if (!used[i] && !bridges.count(mp(v, i)) && !bridges.count(mp(i, v)))
            dfscomp(i, comp);
}

void dfsf(int v, int d = 0) {
    if (v >= comp) return;
    usedf[v] = true;
    if (d >= maxd) {
        maxd = d;
        dv = v;
    }
    for (auto i : dag[v])
        if (!usedf[i]) dfsf(i, d + 1);
}

void dfss(int v, int d = 0) {
    if (v >= comp) return;
    useds[v] = true;
    if (d >= maxd) {
        maxd = d;
        dv = v;
    }
    for (auto i : dag[v])
        if (!useds[i]) dfss(i, d + 1);
}

signed main() {
    FAST;
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
        edges[mp(u, v)]++;
        edges[mp(v, u)]++;
    }
    for (int i = 0; i < n; ++i) 
        if (!used[i]) dfsfup(i);
    for (auto i : edges)
        if (i.s > 1) bridges.erase(i.f);
    used = vector<bool>(n);
    comp = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) { 
            dfscomp(i, comp);
            if (G[i].size() > 0) ++comp;
        }
    }
    dag = graph(comp);
    for (auto i : bridges) {
        int u = color[i.f], v = color[i.s];
        dag[u].pb(v);
        dag[v].pb(u);
    }
    usedf = useds = vector<bool>(comp);
    ll maxx = 0;
    for (int i = 0; i < n; ++i) 
        if (!usedf[i]) {
            maxd = 0;
            dfsf(i);
            maxd = 0;
            dfss(dv);
            checkmax(maxx, maxd);
        }
    cout << maxx;
    return 0;
}