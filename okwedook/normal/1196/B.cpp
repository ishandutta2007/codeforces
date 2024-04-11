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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> st(2);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum ^= a[i];
        sum &= 1;
        st[sum].pb(i);
    }
    if (sum % 2 != k % 2) {
        cout << "NO\n";
        return;
    }
    int cnt = k;
    int curr = k % 2;
    vector<int> ans;
    int past = n;
    while (cnt > 0) {
        while (sz(st[curr]) && st[curr].back() >= past) st[curr].popb();
        if (sz(st[curr]) == 0) {
            cout << "NO\n";
            return;
        }
        past = st[curr].back();
        ans.pb(past);
        curr ^= 1;
        --cnt;
    }
    reverse(ans);
    cout << "YES\n";
    for (auto i : ans) cout << i + 1 << ' ';
    cout << '\n';
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}