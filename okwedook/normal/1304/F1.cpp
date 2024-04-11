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

void makepref(vector<int> &v) {
    for (int i = 1; i < sz(v); ++i)
        v[i] += v[i - 1];
}

int get(int l, int r, const vector<int> &v) {
    return l == 0 ? v[r] : v[r] - v[l - 1];
}

pii intersect(pii a, pii b) {
    if (a.f > b.f) swap(a, b);
    return {b.f, a.s};
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    cin >> a;
    for (auto &i : a) makepref(i);
    vector<int> dp(m - k + 1);
    for (int i = 0; i < n; ++i) {
        vector<int> newdp(m - k + 1);
        for (int l = 0, r = k - 1; r < m; ++l, ++r) {
            int val = get(l, r, a[i]);
            if (i < n - 1) val += get(l, r, a[i + 1]);
            for (int wl = max(0, l - (k - 1)), wr = wl + k - 1; wl <= r && wr < m; ++wl, ++wr)
                checkmax(newdp[l], val + dp[wl] - get(max(l, wl), min(r, wr), a[i]));
        }
        vector<int> prefdp = dp, suffdp = dp;
        for (int i = 1; i < sz(prefdp); ++i) checkmax(prefdp[i], prefdp[i - 1]);
        for (int i = sz(suffdp) - 2; i >= 0; --i) checkmax(suffdp[i], suffdp[i + 1]);
        for (int t = 0; t < sz(newdp); ++t) {
            int val = get(t, t + k - 1, a[i]);
            if (i < n - 1) val += get(t, t + k - 1, a[i + 1]);
            int add = 0;
            if (t - k >= 0) checkmax(add, prefdp[t - k]);
            if (t + k < sz(suffdp)) checkmax(add, suffdp[t + k]);
            val += add;
            checkmax(newdp[t], val);
        }
        dp = newdp;
    }
    int ans = 0;
    for (auto i : dp)
        checkmax(ans, i);
    cout << ans;
    return 0;
}