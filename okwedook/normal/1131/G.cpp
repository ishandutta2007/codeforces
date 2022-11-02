#pragma GCC optimize("O3", "unroll-loops")
 
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
 
void solve(vector<ll> &h, vector<ll> &l) {
    vector<ll> st;
    for (int i = 0; i < sz(h); ++i) {
        l[i] = max(0ll, i - h[i] + 1);
        while (sz(st) && st.back() >= l[i]) 
            checkmin(l[i], l[st.back()]), st.popb();
        st.pb(i);
    }
}
 
signed main() {
    FAST; FIXED; RANDOM;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> height(n), cost(n);
    for (int i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        height[i] = cost[i] = vector<ll>(k);
        cin >> height[i] >> cost[i];
    }
    ll q;
    cin >> q;
    vector<ll> h(m), c(m);
    ll ptr = 0;
    while (q--) {
        ll id, mul;
        cin >> id >> mul;
        --id;
        for (int i = 0; i < sz(height[id]); ++i) {
            h[ptr] = height[id][i];
            c[ptr] = cost[id][i] * mul;
            ++ptr;
        }
    }
    vector<ll> l(m), r(m);
    solve(h, l);
    reverse(h);
    solve(h, r);
    reverse(r);
    reverse(h);
    for (auto &i : r) i = m - i - 1;
    vector<ll> st;
    vector<ll> dp(m, inf);
    for (int i = 0; i < m; ++i) {
        checkmin(dp[r[i]], (i > 0 ? dp[i - 1] : 0) + c[i]);
        checkmin(dp[i], (l[i] > 0 ? dp[l[i] - 1] : 0) + c[i]);
        ll last = -1;
        while (sz(st) && st.back() >= l[i]) {
            checkmin(dp[i], dp[st.back()] + c[i]);
            last = st.back();
            st.popb();
        }
        if (last >= 0) st.pb(last);
        while (sz(st) && dp[st.back()] >= dp[i]) st.popb();
        st.pb(i);
    }
    cout << dp.back();
    return 0;
}