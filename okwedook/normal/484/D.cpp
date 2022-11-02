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
#define ld double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define lowb lower_bound
#define upb upper_bound
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 1000000007
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

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<bool> used(n);
    used[0] = used[n - 1] = true;
    used[1] = used[n - 2] = true;
    for (ll i = 1; i < n - 1; ++i) {
        if (a[i] <= a[i - 1] && a[i] <= a[i + 1]) used[i - 1] = used[i] = used[i + 1] = true;
        if (a[i] >= a[i - 1] && a[i] >= a[i + 1]) used[i - 1] = used[i] = used[i + 1] = true;
    }
    vector<int> p;
    for (int i = 0; i < n; ++i) 
        if (used[i]) p.pb(a[i]);
    vector<ll> dp(sz(p));
    for (int i = 0; i < sz(dp); ++i)
        dp[i] = abs(p[i] - p[0]);
    for (int i = 0; i < sz(dp); ++i)
        for (int j = i; j > i - 10 && j > 0; --j)
            checkmax(dp[i], dp[j - 1] + abs(p[i] - p[j]));
    cout << dp.back();
    return 0;
}