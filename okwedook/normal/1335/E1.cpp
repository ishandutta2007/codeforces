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

void makepref(vector<int> &a) {
    for (int i = 1; i < sz(a); ++i)
        a[i] += a[i - 1];
}

int get(const vector<int> &a, int l, int r) {
    if (l > r) return 0;
    return l == 0 ? a[l] : a[r] - a[l - 1];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    for (auto &i : a) --i;
    int mx = 0;
    for (auto i : a) checkmax(mx, i + 1);
    vector<vector<int>> pref(mx, vector<int>(n));
    for (int i = 0; i < n; ++i)
        pref[a[i]][i] += 1;
    for (int i = 0; i < mx; ++i)
        makepref(pref[i]);
    vector<vector<int>> occ(mx);
    for (int i = 0; i < mx; ++i) occ[i].pb(-1);
    for (int i = 0; i < n; ++i)
        occ[a[i]].pb(i);
    for (int i = 0; i < mx; ++i) occ[i].pb(n);
    int ans = 0;
    for (int was = 0; was < mx; ++was) {
        for (int l = 0, r = sz(occ[was]) - 1; l < r; ++l, --r) {
            for (int mid = 0; mid < mx; ++mid)
                checkmax(ans, l + (sz(occ[was]) - r - 1) + get(pref[mid], occ[was][l] + 1, occ[was][r] - 1));
        }
    }
    cout << ans << '\n';
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