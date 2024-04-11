#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }
 
int n, m;
int getind(int r, int c) {
    return r * m + c;
}
 
graph G, rev;
 
vector<int> oncycle;
vector<int> md;
vector<int> cycle;
 
void findcycle(int v) {
    cycle.clear();
    set<int> st;
    vector<int> path;
    while (!st.count(v)) {
        path.pb(v);
        st.insert(v);
        v = G[v][0];
    }
    bool flag = false;
    for (int i = 0; i < sz(path); ++i) {
        if (path[i] == v) flag = true;
        if (flag) cycle.pb(path[i]);
    }
}
 
void updtree(int v, int cmd, int amd, int c) {
    if (cmd < 0) cmd += amd;
    md[v] = cmd;
    oncycle[v] = c;
    for (auto i : rev[v])
        if (oncycle[i] == -1)
            updtree(i, cmd - 1, amd, c);
}
 
void solve() {
    cin >> n >> m;
    vector<string> c(n);
    vector<string> dir(n);
    cin >> c >> dir;
    G = rev = graph(n * m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int ni = i, nj = j;
            if (dir[i][j] == 'U') --ni;
            if (dir[i][j] == 'D') ++ni;
            if (dir[i][j] == 'L') --nj;
            if (dir[i][j] == 'R') ++nj;
            int u = getind(i, j), v = getind(ni, nj);
            G[u].pb(v);
            rev[v].pb(u);
        }
    oncycle = md = vector<int>(sz(G), -1);
    int mx = 0;
    for (int i = 0; i < sz(G); ++i) {
        if (oncycle[i] == -1) {
            findcycle(i);
            for (int j = 0; j < sz(cycle); ++j) {
                md[cycle[j]] = j;
                oncycle[cycle[j]] = cycle[0];
            }
            for (auto i : cycle) updtree(i, md[i], sz(cycle), cycle[0]);
            mx += sz(cycle);
        }
    }
    int colored = 0;
    vector<set<int>> st(sz(G));
    for (int i = 0; i < sz(G); ++i) {
        if (c[i / m][i % m] == '0')
            st[oncycle[i]].insert(md[i]);
    }
    for (const auto &i : st)
        colored += sz(i);
    cout << mx << ' ' << colored << '\n';
}
 
signed main() {
    FAST; FIXED;
    int t;
    cin >> t;
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}