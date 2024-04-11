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
#include <complex>
 
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
#define mod 12600
#define inf 3000000000000000007ll
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

int dp[10][10][10];

signed main() {
    FAST; FIXED; RANDOM;
    for (int a = 0; a < 10; ++a)
        for (int b = 0; b < 10; ++b)
            for (int c = 0; c < 10; ++c)
                dp[a][b][c] = 21;
    for (int x = 0; x < 10; ++x)
        for (int y = 0; y < 10; ++y)
            for (int cx = 0; cx <= 10; ++cx)
                for (int cy = 0; cy <= 10; ++cy)
                    if (cx + cy > 0)
                        checkmin(dp[x][y][(cx * x + cy * y) % 10], cx + cy);
    string s;
    cin >> s;
    for (auto &i : s) i -= '0';
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            int ans = 0;
            bool flag = false;
            for (int i = 1; i < sz(s); ++i) {
                int d = int(s[i]) - int(s[i - 1]);
                if (d < 0) d += 10;
                if (dp[x][y][d] == 21) flag = true;
                ans += dp[x][y][d] - 1;
            }
            if (flag) cout << -1 << ' ';
            else cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}