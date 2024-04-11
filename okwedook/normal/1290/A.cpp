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

template<class T, const T& (*cmp)(const T&, const T&) = min>
struct sparse {
    int N, LOG;
    vector<int> mx;
    vector<vector<T>> val;
    //array a must not be empty
    sparse(const vector<T> &a) {
        N = sz(a), LOG = log2(N) + 1;
        mx = vector<int>(N + 1);
        for (int i = 2; i < sz(mx); ++i) mx[i] = mx[i >> 1] + 1;
        val = vector<vector<T>>(LOG, vector<T>(N));
        for (int i = 0; i < N; ++i) val[0][i] = a[i];
        for (int l = 1; l < LOG; ++l)
            for (int i = 0, next = 1 << (l - 1); next < N; ++i, ++next)
                val[l][i] = cmp(val[l - 1][i], val[l - 1][next]);
    }
    //[l, r] range query
    T get(int l, int r) {
        ++r;
        int len = mx[r - l];
        return cmp(val[len][l], val[len][r - (1 << len)]);
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    checkmin(k, m - 1);
    vector<int> a(n);
    cin >> a;
    int ans = -1;
    for (int l = 0; l <= k; ++l) {
        int r = k - l;
        int v = mod;
        for (int lm = 0; lm < m - k; ++lm) {
            int rm = (m - k - 1) - lm;
            int x = a[l + lm];
            checkmax(x, a[n - 1 - (r + rm)]);
            checkmin(v, x);
        }
        checkmax(ans, v);
    }
    cout << ans << '\n';
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}