#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define ll long long
#define pii pair<int, int>
#define graph vector<vector<int>>
#define pb push_back
#define f first
#define s second
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()

void flush() { cout << flush; }
void flushln() { cout << endl; }
void println() { cout << '\n'; }
template<class T> void print(const T &x) { cout << x; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }

graph G;
vector<vector<int>> up;
vector<int> h;
int LOG;

void orient(int v, int p, int he = 0) {
    up[0][v] = p;
    h[v] = he;
    for (auto i : G[v])
        if (i != p) {
            orient(i, v, he + 1);
        }
}

int lca(int u, int v) {
    if (h[u] > h[v]) swap(u, v);
    int d = h[v] - h[u];
    for (int l = 0; l < LOG; ++l)
        if (d >> l & 1)
            v = up[l][v];
    if (u == v) {
        return u;
    }
    for (int l = LOG - 1; l >= 0; --l) {
        if (up[l][u] != up[l][v]) {
            u = up[l][u];
            v = up[l][v];
        }
    }
    return up[0][u];
}

int getup(int v, int dist) {
    for (int l = 0; l < LOG; ++l)
        if (dist >> l & 1)
            v = up[l][v];
    return v;
}

vector<pii> paths;
vector<map<pii, vector<int>>> samelca;
vector<vector<int>> bylca;
vector<vector<int>> addvertex;

vector<set<int>> sets;
vector<int> link;

set<int>& at(int v) {
    return sets[link[v]];
}

bool count(const vector<int> &v, int x) {
    return binary_search(all(v), x);
}

ll ans = 0;

template<class T, class U> U get(map<T, U> &mp, T k) {
    auto it = mp.find(k);
    if (it != mp.end()) return it->s;
    return T();
}

void process(int v, int p = -1) {
    int bigson = -1;
    map<int, int> sonvert, sonhere;
    for (auto i : G[v])
        if (i != p) {
            process(i, v);
            if (bigson == -1 || sz(at(bigson)) < sz(at(i))) {
                bigson = i;
            }
            sonvert[i] = sz(at(i));
            // number of paths that cross v and i both, but lca is not i
        }
    for (auto &p : samelca[v]) {
        sonvert[p.f.f] -= sz(p.s);
        sonvert[p.f.s] -= sz(p.s);
        sonhere[p.f.f] += sz(p.s);
        sonhere[p.f.s] += sz(p.s);
    }
    sonvert.erase(-1);
    sonhere.erase(-1);
    if (bigson != -1) {
        link[v] = link[bigson];
    }
    for (auto i : G[v])
        if (i != bigson) {
            for (auto path : at(i))
                at(v).insert(path);
        }
    for (auto path : addvertex[v])
        at(v).insert(path);
    // at(v) - all paths that cross v
    // bylca[v] - all paths that have v as lca
    ll vertical = sz(at(v)) - sz(bylca[v]);
    ll here = sz(bylca[v]);
    ans += vertical * here + here * (here - 1) / 2;
    ll add1 = 0, add2 = 0;
    for (auto &p : samelca[v]) {
        add1 += sz(p.s) * (ll)(get(sonvert, p.f.f) + get(sonvert, p.f.s));
        if (p.f.f >= 0) {
            add2 += sz(p.s) * (ll)(get(sonhere, p.f.f) + get(sonhere, p.f.s));
            add2 -= (sz(p.s) * (ll)(sz(p.s) + 1) / 2) * 2;
        } else if (p.f.s >= 0) {
            add2 += sz(p.s) * (ll)(get(sonhere, p.f.s));
            add2 -= sz(p.s);
        }
    }
    ans -= add1 + add2 / 2;
    for (auto path : bylca[v])
        at(v).erase(path);
}

signed main() {
    FAST; FIXED;
    int n;
    read(n);
    G = graph(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        read(u, v);
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    LOG = ceil(log2(max(2, n)));
    up = vector<vector<int>>(LOG, vector<int>(n));
    h = vector<int>(n);
    orient(0, 0);
    for (int l = 1; l < LOG; ++l) {
        for (int i = 0; i < n; ++i)
            up[l][i] = up[l - 1][up[l - 1][i]];
    }
    int m;
    read(m);
    auto getsub = [&](int v, int l) {
        if (v == l) return -1;
        return getup(v, h[v] - h[l] - 1);
    };
    paths.resize(m);
    samelca.resize(n);
    bylca.resize(n);
    addvertex.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        read(u, v);
        --u, --v;
        paths[i] = {u, v};
        int l = lca(u, v);
        pii sons;
        sons.f = getsub(u, l);
        sons.s = getsub(v, l);
        if (sons.f > sons.s)
            swap(sons.f, sons.s);
        samelca[l][sons].pb(i);
        bylca[l].pb(i);
        addvertex[u].pb(i);
        addvertex[v].pb(i);
    }
    sets.resize(n);
    link.resize(n);
    iota(all(link), 0);
    process(0);
    println(ans);
    return 0;
}