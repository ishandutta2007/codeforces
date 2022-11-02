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
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) int(a.size())
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
 
struct Fenv {
    static const int n = 4e5 + 100;
    ll fenv[n];
    Fenv() {
        for (int i = 0; i < n; ++i) fenv[i] = 0;
    }
    void add(int r, ll x) {
        for (; r < n; r |= r + 1) fenv[r] += x;
    }
    ll get(int r) {
        ll ans = 0;
        for (; r >= 0; r = (r & r + 1) - 1)
            ans += fenv[r];
        return ans;
    }
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<pll> a(n);
    cin >> a;
    map<ll, ll> st;
    for (auto i : a) st[i.f], st[i.s];
    ll cnt = 0;
    for (auto &i : st) i.s = cnt++;
    for (auto &i : a) {
        i.f = st[i.f];
        i.s = st[i.s];
    }
    sort(all(a), [](pll a, pll b) {
        if (a.s == b.s) return a.f < b.f;
        return a.s > b.s;
    });
    Fenv f;
    ll ans = 0;
    vector<int> x(4e5 + 100);
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[j].s == a[i].s) {
            if (x[a[j].f] == 0) {
                x[a[j].f] = 1;
                f.add(a[j].f, 1);
            }
            ++j;
        }
        int past = 0;
        for (int t = i; t < j; ++t) {
            ll left = f.get(past, a[t].f - 1);
            ll right = f.get(a[t].f + 1, 4e5);
            ans += (left + 1) * (right + 1);
            checkmax(past, a[t].f + 1);
        }
        i = j;
    }
    cout << ans << '\n';
    return 0;
}