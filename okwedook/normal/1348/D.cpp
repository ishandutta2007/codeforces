#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

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

ll process(vector<ll> cnt) {
    ll mass = 1;
    for (int i = 1; i < sz(cnt); ++i)
        mass += cnt[i];
    return mass;
}

vector<ll> buildcnt(const vector<ll> &add) {
    vector<ll> cnt(1, 1);
    for (auto i : add)
        cnt.pb(cnt.back() + min(cnt.back(), i));
    return cnt;
}

void changeadd(vector<ll> &add) {
    vector<ll> cnt(1, 1);
    vector<ll> newadd;
    for (auto i : add) {
        newadd.pb(min(cnt.back(), i));
        cnt.pb(cnt.back() + newadd.back());
    }
    add = newadd;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> cnt(1, 1), mass(1, 1), add;
    while (mass.back() < n) {
        add.pb(cnt.back());
        cnt.pb(cnt.back() * 2);
        mass.pb(mass.back() + cnt.back());
    }
    auto mxadd = add;
    while (process(buildcnt(add)) != n) {
        for (int i = sz(add) - 1; i >= 0; --i) {
            int l = 0, r = mxadd[i] + 1;
            while (r - l > 1) {
                vector<ll> checkadd = add;
                ll mid = r + l >> 1;
                checkadd[i] = mid;
                changeadd(checkadd);
                if (process(buildcnt(checkadd)) > n) r = mid;
                else l = mid;
            }
            add[i] = l;
            changeadd(add);
        }
    }
    assert(process(buildcnt(add)) == n);
    cout << sz(add) << '\n';
    for (auto i : add) cout << i << ' ';
    cout << '\n';
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