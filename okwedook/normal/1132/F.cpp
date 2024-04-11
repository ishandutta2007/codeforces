#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <deque>
#include <queue>
#include <random>
#include <sstream>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(15);
#define RANDOM srand(3654765)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>> 
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define hashmap unordered_map
#define hashset unordered_set
#define f first
#define s second
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < n; ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "";
    char past(-1);
    for (auto i : s) {
        if (i != past) t += i;
        past = i;
    }
    n = sz(t);
    for (auto &i : t) i -= 'a';
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(26, mod)));
    for (int i = 0; i < n; ++i) {
        dp[i][i][t[i]] = 0;
        for (int j = 0; j < 26; ++j) checkmin(dp[i][i][j], 1);
    }   
    for (int l = 1; l < n; ++l)
        for (int i = 0; i + l < n; ++i) {
            int j = i + l;
            for (int k = i; k < j; ++k)
                for (int c = 0; c < 26; ++c)
                    checkmin(dp[i][j][c], dp[i][k][c] + dp[k + 1][j][c]);
            int mn = mod;
            for (int c = 0; c < 26; ++c)
                checkmin(mn, dp[i][j][c]);
            for (int c = 0; c < 26; ++c)
                checkmin(dp[i][j][c], mn + 1);
        }
    int ans = mod;
    for (int i = 0; i < 26; ++i)
        checkmin(ans, dp[0][n - 1][i]);
    cout << ans + 1;
    return 0;
}