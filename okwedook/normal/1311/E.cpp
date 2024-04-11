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

vector<int> l, r, p;
vector<vector<int>> has, both;

void dfsfind(int v, int h = 0) {
    if (v == -1) return;
    if (l[v] == -1 || r[v] == -1) has[h].pb(v);
    if (l[v] == -1 && r[v] == -1) both[h].pb(v);
    dfsfind(l[v], h + 1);
    dfsfind(r[v], h + 1);
}

void solve() {
    int n, d;
    cin >> n >> d;
    int mx = 0, mn = 0;
    for (int i = 0; i < n; ++i)
        mx += i;
    for (int i = 0; i < n; ++i) {
        int k = i;
        while (k > 0) {
            ++mn;
            k = (k - 1) / 2;
        }
    }
    if (d < mn || d > mx) {
        cout << "NO\n";
        return;
    }
    l = r = p = vector<int>(n, -1);
    for (int i = 1; i < n; ++i) {
        p[i] = (i - 1) / 2;
        if (i & 1) l[p[i]] = i;
        else r[p[i]] = i;
    }
    while (mn < d) {
        has = both = vector<vector<int>>(n);
        dfsfind(0);
        for (int h = n - 1; h >= 0; --h)
            if (sz(both[h]) >= 1 && sz(has[h]) >= 2) {
                int v = both[h][0];
                if (l[p[v]] == v) l[p[v]] = -1;
                else r[p[v]] = -1;
                for (auto u : has[h])
                    if (u != v) {
                        //cout << u << ' ' << v << '\n';
                        p[v] = u;
                        if (l[u] == -1) {
                            l[u] = v;
                        } else {
                            r[u] = v;
                        }
                        goto go;
                    }
            }
        go:;
        ++mn;
    }
    cout << "YES\n";
    for (int i = 1; i < n; ++i) cout << p[i] + 1 << ' ';
    cout << '\n';
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}