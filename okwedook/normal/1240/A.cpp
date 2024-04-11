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
#include <complex>

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

ll getsum(vector<ll> &pref, int l, int r) {
    if (r < l) return 0;
    if (l == 0) return pref[r];
    return pref[r] - pref[l - 1];
}

void solve() {
    int n;
    cin >> n;
    vector<ll> p(n);
    cin >> p;
    ll x, a;
    cin >> x >> a;
    ll y, b;
    cin >> y >> b;
    ll k;
    cin >> k;
    k *= 100;
    rsort(p);
    for (int i = 1; i < sz(p); ++i) p[i] += p[i - 1];
    int ptr = 0;
    int cab = 0, ca = 0, cb = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % a == 0 && i % b == 0) {
            ++cab;
        } else if (i % a == 0) {
            ++ca;
        } else if (i % b == 0) {
            ++cb;
        }
        ll check = 0;
        check += getsum(p, 0, cab - 1) * (x + y);
        check += max(getsum(p, cab, cab + ca - 1) * x + getsum(p, cab + ca, cab + ca + cb - 1) * y,
            getsum(p, cab, cab + cb - 1) * y + getsum(p, cab + cb, cab + cb + ca - 1) * x);
        if (check >= k) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}