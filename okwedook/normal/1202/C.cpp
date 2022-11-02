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
#include <complex>
#include <cassert>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
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
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

ll get(string s) {
    ll mn = 0, mx = 0;
    int x = 0;
    for (auto i : s) {
        if (i == 'W') ++x;
        else --x;
        checkmin(mn, x);
        checkmax(mx, x);
    }
    return mx - mn + 1;
}

bool mnmx(vector<int> d) {
    int mn = 0;
    for (int i = 0; i < sz(d); ++i)
        if (d[i] <= d[mn]) mn = i;
    int mx = sz(d) - 1;
    for (int i = sz(d) - 1; i >= 0; --i)
        if (d[i] >= d[mx]) mx = i;
    return mn < mx;
}

bool mxmn(vector<int> d) {
    int mx = 0;
    for (int i = 0; i < sz(d); ++i)
        if (d[i] >= d[mx]) mx = i;
    int mn = sz(d) - 1;
    for (int i = sz(d) - 1; i >= 0; --i)
        if (d[i] <= d[mn]) mn = i;
    return mx < mn;
}

ll apply(string s) {
    vector<int> d(1);
    int x = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == 'W') ++x;
        else --x;
        d.pb(x);
    }
    if (mnmx(d) || mxmn(d)) {
        int v = get(s);
        if (v >= 2) return max(2, v - 1);
        else return 1;
    } else return get(s);
}

void solve() {
    string s;
    cin >> s;
    string t = "", d = "";
    for (auto i : s) {
        if (i == 'W' || i == 'S') t += i;
        if (i == 'A') d += 'W';
        if (i == 'D') d += 'S';
    }
    cout << min(get(t) * apply(d), get(d) * apply(t)) << '\n';
}
 
signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}