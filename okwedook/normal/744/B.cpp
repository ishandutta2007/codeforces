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

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    int d = 1;
    vector<int> ans(n, mod);
    while (d < n) {
        vector<int> a, b;
        for (int i = 0; i < n; i += 2 * d)
            for (int j = i; j < i + d && j < n; ++j)
                a.pb(j);
        for (int i = d; i < n; i += 2 * d)
            for (int j = i; j < i + d && j < n; ++j)
                b.pb(j);
        vector<int> ansa(n, mod);
        if (sz(a)) {
            cout << sz(a) << '\n';
            for (auto i : a) cout << i + 1 << ' ';
            cout << endl;
            cin >> ansa;
        }
        vector<int> ansb(n, mod);
        if (sz(b)) {
            cout << sz(b) << '\n';
            for (auto i : b) cout << i + 1 << ' ';
            cout << endl;
            cin >> ansb;
        }
        for (int i = 0; i < n; ++i)
            for (auto j : a)
                if (i / d % 2 != j / d % 2)
                    checkmin(ans[i], ansa[i]);
        for (int i = 0; i < n; ++i)
            for (auto j : b)
                if (i / d % 2 != j / d % 2)
                    checkmin(ans[i], ansb[i]);
        d *= 2;
    }
    cout << -1 << endl;
    for (auto i : ans) cout << i << ' ';
    cout << endl;
    return 0;
}