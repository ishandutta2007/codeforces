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
#define mod 1000000007
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
template<class T> inline T sorted(T a) { sort(a); return a; }
 
vector<int> p, sub, ans;
vector<pii> mx;
 
void add(pii &p, int x) {
    if (!ifmax(p.f, x)) checkmax(p.s, x);
}
 
int getp(int v) {
    return v == p[v] ? v : p[v] = getp(p[v]);
}
 
void unite(int a, int b) {
    a = getp(a);
    b = getp(b);
    if (a == b) return;
    if (sub[a] > sub[b]) swap(a, b);
    p[a] = b;
    sub[b] += sub[a];
    checkmax(ans[b], (ans[b] + 1) / 2 + (ans[a] + 1) / 2 + 1);
    checkmax(ans[b], ans[a]);
}

graph G;
vector<bool> used;

pii dfsfar(int v, int p = -1) {
    pii ans = {0, v};
    for (auto i : G[v])
        if (i != p) {
            pii check = dfsfar(i, v);
            ++check.f;
            checkmax(ans, check);
        }
    return ans;
}

void dfs(int v, int start, int d) {
    used[v] = true;
    p[v] = start;
    ans[v] = d;
    for (auto i : G[v])
        if (!used[i]) dfs(i, start, d);
}
 
signed main() {
    FAST; FIXED; RANDOM;
    int n, m, q;
    cin >> n >> m >> q;
    p = sub = ans = vector<int>(n);
    mx = vector<pii>(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        sub[i] = 1;
    }
    G = graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    used = vector<bool>(n);
    for (int i = 0; i < n; ++i) 
        if (!used[i]) {
            int v = dfsfar(i).s;
            dfs(i, i, dfsfar(v).f);
        }
    while (q--) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            int x;
            cin >> x;
            cout << ans[getp(x - 1)] << '\n';
        }
        if (mode == 2) {
            int x, y;
            cin >> x >> y;
            unite(x - 1, y - 1);
        }
    }
    return 0;
}