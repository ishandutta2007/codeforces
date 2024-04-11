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
 
int get(int x, int k) {
    if (x == 0) return 1001;
    int ans = 0;
    while (x % k == 0) ++ans, x /= k;
    return ans;
}
 
pair<int, string> solve(vector<vector<int>> a, int n, int m, int k) {
    vector<vector<int>> dp(n, vector<int>(m));
    vector<vector<char>> p(n, vector<char>(m));
    int curr = 0;
    for (int i = 0; i < m; ++i) {
        curr += get(a[0][i], k);
        dp[0][i] = curr;
        p[0][i] = 'R';
    }
    curr = 0;
    for (int i = 0; i < m; ++i) {
        curr += get(a[i][0], k);
        dp[i][0] = curr;
        p[i][0] = 'D';
    }
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
                if (dp[i - 1][j] < dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j] + get(a[i][j], k);
                    p[i][j] = 'D';
                } else {
                    dp[i][j] = dp[i][j - 1] + get(a[i][j], k);
                    p[i][j] = 'R';
                }
    int y = n - 1, x = m - 1;
    string ans = "";
    while (x > 0 || y > 0) {
        ans += p[y][x];
        if (p[y][x] == 'D') --y;
        else --x;
    }
    reverse(ans);
    return {dp[n - 1][m - 1], ans};
}
 
signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    cin >> a;
    pair<int, string> ans = solve(a, n, n, 2);
    checkmin(ans, solve(a, n, n, 5));
    if (ans.f != 0) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (a[i][j] == 0) {
                    ans.f = 1;
                    ans.s = "";
                    for (int t = 0; t < i; ++t) ans.s += 'D';
                    for (int t = 0; t < j; ++t) ans.s += 'R';
                    for (int t = i; t < n - 1; ++t) ans.s += 'D';
                    for (int t = j; t < n - 1; ++t) ans.s += 'R';
                }
    }
    cout << ans.f << '\n' << ans.s;
    return 0;
}