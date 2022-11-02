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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; ++i) a[i] = {s[i], i};
    sort(all(a), [](const pair<char, int> &a, const pair<char, int> &b) {
        if (a.f != b.f) return a.f < b.f;
        return a.s > b.s;
    });
    vector<int> ans(n, 2);
    int past = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && a[i].f != a[i - 1].f) past = mx;
        if (a[i].s < past) break;
        checkmax(mx, a[i].s);
        ans[a[i].s] = 1;
    }
    string check;
    for (int i = 0; i < n; ++i)
        if (ans[i] == 1) check += s[i];
    for (int i = 0; i < n; ++i)
        if (ans[i] == 2) check += s[i];
    for (int i = 1; i < n; ++i)
        if (check[i] < check[i - 1]) {
            cout << "-" << '\n';
            return;
        }
    for (auto i : ans) cout << i;
    cout << '\n';
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}