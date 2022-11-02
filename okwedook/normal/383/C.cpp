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

struct Fenv {
    static const int n = 2e5 + 10;
    int fenv[n];
    void add(int r, int x) {
        for (; r < n; r |= r + 1)
            fenv[r] += x;
    }
    void add(int l, int r, int x) {
        add(l, x);
        add(r + 1, -x);
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ans += fenv[r];
        return ans;
    }
} fenv[2];

graph G;
vector<int> a, h, in, out;
int currt = 0;

void dfs(int v, int p = -1, int he = 0) {
    h[v] = he;
    in[v] = currt++;
    fenv[h[v]].add(in[v], in[v], a[v]);
    for (auto i : G[v])
        if (i != p) dfs(i, v, h[v] ^ 1);
    out[v] = currt - 1;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    a = h =  in = out = vector<int>(n);
    cin >> a;
    G = graph(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(0);
    for (int i = 0; i < m; ++i) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            int x, val;
            cin >> x >> val;
            --x;
            fenv[h[x]].add(in[x], out[x], val);
            fenv[h[x] ^ 1].add(in[x], out[x], -val);
        }
        if (mode == 2) {
            int x;
            cin >> x;
            --x;
            cout << fenv[h[x]].get(in[x]) << '\n';
        }
    }
    return 0;
}