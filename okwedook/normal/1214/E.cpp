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

int getl(int x) {
    return 2 * x - 1;
}

int getr(int x) {
    return 2 * x;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<pii> d(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i].f, d[i].s = i + 1;
    rsort(d);
    vector<int> a(d[0].f + 1);
    a.back() = getr(d[0].s);
    for (int i = 0; i < sz(a) - 1; ++i) a[i] = getl(d[i].s);
    for (int i = 0; i < sz(a) - 1; ++i) cout << a[i] << ' ' << a[i + 1] << '\n';
    vector<vector<int>> byd(sz(a));
    for (int i = 0; i < sz(a); ++i) byd[i].pb(a[i]);
    for (int i = 1; i < sz(a) - 1; ++i) {
        int link = min(sz(a) - 1, i + d[i].f - 1);
        int height = d[i].f - (link - i);
        if (sz(byd[link]) <= height) byd[link].pb(getr(d[i].s));
        cout << getr(d[i].s) << ' ' << byd[link][height - 1] << '\n';
    }
    for (int i = sz(a) - 1; i < n; ++i) {
        cout << a[0] << ' ' << getl(d[i].s) << '\n';
        if (d[i].f == 1) cout << getl(d[i].s) << ' ' << getr(d[i].s) << '\n';
        else cout << a[d[i].f - 2] << ' ' << getr(d[i].s) << '\n';
    }
    return 0;
}