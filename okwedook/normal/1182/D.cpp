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
#include <random>
#include <cassert>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
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
#define mod 998244353
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)]);
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
 
graph G;
vector<int> vert;

pii dfsfar(int v, int p = -1) {
    pii ans = {0, v};
    for (auto i : G[v])
        if (i != p) {
            auto a = dfsfar(i, v);
            ++a.f;
            checkmax(ans, a);
        }
    return ans;
}

bool add(int v, int u, int p = -1) {
    if (v == u) {
        vert.pb(v);
        return true;
    }
    for (auto i : G[v])
        if (i != p) {
            if (add(i, u, v)) {
                vert.pb(v);
                return true;
            }
        }
    return false;
}

bool check(int v, int p) {
    if (sz(G[v]) > 2) return false;
    for (auto i : G[v])
        if (i != p) return check(i, v);
    return true;
}

map<int, int> st;

bool mirror(int v, int p = -1, int d = 0) {
    if (st.count(d)) 
        if (st[d] != sz(G[v])) return false;
    st[d] = sz(G[v]);
    for (auto i : G[v])
        if (i != p && !mirror(i, v, d + 1))
            return false;
    return true;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    G = graph(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    int u = dfsfar(0).s;
    int v = dfsfar(u).s;
    add(u, v);
    v = vert[sz(vert) / 2];
    if (mirror(v)) {
        cout << v + 1 << '\n';
        return 0;
    } 
    st.clear();
    map<int, vector<int>> mp;
    for (auto i : G[v])
        if (check(i, v)) {
            auto ans = dfsfar(i, v);
            mp[ans.f].pb(ans.s);
        }
    if (sz(mp) > 2) {
        cout << -1;
        return 0;
    }
    for (auto i : mp)
        if (sz(i.s) == 1) {
            if (mirror(i.s[0])) {
                cout << i.s[0] + 1;
                return 0;
            }
        }
    cout << -1;
    return 0;
}