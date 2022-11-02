#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <tuple>
#include <random>
#include <bitset>
#include <queue>

using namespace std;

#define FIXED cout << fixed << setprecision(15)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RANDOM srand(85453532)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 999999677
#define inf 4000000000000000007ll
#define f first
#define s second
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { 
    if (y < x) return x = y, true;
    return false; 
}
template<class T, class U> inline bool ifmax(T &x, U y) { 
    if (y > x) return x = y, true;
    return false; 
}
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) { 
    for (auto &i : a) stream >> i;
    return stream;
}

struct maxwindow {
    deque<pll> mx;
    int k;
    void add(ll i, ll x) {
        while (sz(mx) > 0 && mx.back().f <= x) mx.popb();
        mx.pb({x, i}); 
    }
    ll get(ll i) {
        while (sz(mx) > 0 && i - mx.front().s > k) mx.popf();
        if (sz(mx) == 0) return i < k ? 0 : -inf;
        return mx.front().f;
    }
};

signed main() {
    FAST; FIXED; RANDOM;
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    cin >> arr;
    vector<vector<ll>> dp(n, vector<ll>(x + 1));
    vector<maxwindow> mx(x + 1);
    for (auto &i : mx) i.k = k;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= x; ++j) 
            dp[i][j] = mx[j - 1].get(i) + arr[i];
        for (int j = 1; j <= x; ++j) 
            mx[j].add(i, dp[i][j]);
    }
    ll ans = 0;
    for (int i = max(0, n - k); i < n; ++i) 
        checkmax(ans, dp[i][x]);
    cout << (ans == 0 ? -1 : ans);
    return 0;
}