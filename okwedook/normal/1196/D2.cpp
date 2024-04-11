#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("avx2")

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

string check = "RGB";

int prefs(vector<int> &pref, int l, int r) {
    if (r < l) return 0;
    if (l == 0) return pref[r];
    return pref[r] - pref[l - 1];
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;   
    cin >> s;
    vector<vector<vector<int>>> dp(sz(check), vector<vector<int>>(sz(check), vector<int>(n)));
    for (int c = 0; c < sz(check); ++c)
        for (int start = 0; start < sz(check); ++start)
            for (int i = start; i < n; i += sz(check))
                dp[c][start][i] = s[i] != check[c];
    for (int c = 0; c < sz(check); ++c)
        for (int start = 0; start < sz(check); ++start)
            for (int i = 1; i < n; ++i)
                dp[c][start][i] += dp[c][start][i - 1];
    int ans = n;
    for (int i = 0; i + k <= n; ++i) {
        for (int c = 0; c < sz(check); ++c) {
            int check = 0;
            check += prefs(dp[c][i % 3], i, i + k - 1);
            check += prefs(dp[(c + 1) % 3][(i + 1) % 3], i + 1, i + k - 1);
            check += prefs(dp[(c + 2) % 3][(i + 2) % 3], i + 2, i + k - 1);
            checkmin(ans, check);
        }
    }
    cout << ans << '\n';
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}