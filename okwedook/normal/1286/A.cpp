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

const int N = 101;

int dp[2][N][N][N];

signed main() {
    FAST; FIXED; RANDOM;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                dp[0][i][j][k] = dp[1][i][j][k] = mod;
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int c0 = 0, c1 = 0;
    for (int i = 1; i <= n; ++i) {
        bool flag = true;
        for (auto j : a)
            if (i == j) flag = false;
        if (flag) {
            if (i & 1) ++c1;
            else ++c0;
        }
    }
    dp[0][0][c0][c1] = dp[1][0][c0][c1] = 0;
    for (int pref = 1; pref <= n; ++pref) {
        vector<int> poss;
        int d = 0;
        if (a[pref - 1] == 0) poss = {0, 1}, d = 1;
        else poss = {a[pref - 1] & 1};
        for (auto val : poss) {
            int d0 = (val + 1) % 2 * d, d1 = val % 2 * d;
            for (int past = 0; past < 2; ++past)
                for (int c0 = d0; c0 < N; ++c0)
                    for (int c1 = d1; c1 < N; ++c1)
                        checkmin(dp[val][pref][c0 - d0][c1 - d1], dp[past][pref - 1][c0][c1] + (val != past));
        }
    }
    cout << min(dp[0][n][0][0], dp[1][n][0][0]);
    return 0;
}