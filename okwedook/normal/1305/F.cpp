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
#include <chrono>

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

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    vector<ll> x;
    for (auto i : a) {
        if (i > 1) x.pb(i - 1);
        x.pb(i);
        x.pb(i + 1);
    }
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(all(x), gen);
    set<ll> st;
    for (auto i : x) {
        if (clock() > 1.5 * CLOCKS_PER_SEC || sz(st) > 50) break;
        ll v = i;
        for (ll d = 2; d * d <= v; ++d)
            if (v % d == 0) {
                st.insert(d);
                while (v % d == 0) v /= d;
            }
        if (v > 1) st.insert(v);
    }
    ll ans = n;
    for (auto i : st) {
        ll check = 0;
        for (auto j : a) {
            if (j < i) check += i - j;
            else {
                ll add = j % i;
                checkmin(add, i - add);
                check += add;
            }
        }
        checkmin(ans, check);
    }
    cout << ans;
    return 0;
}