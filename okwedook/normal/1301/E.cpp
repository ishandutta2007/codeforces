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
 
const int N = 502;
 
struct pref {
    int p[N][N];
    void add(int i, int j) {
        p[i][j]++;
    }
    void countpref() {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                if (i > 0) p[i][j] += p[i - 1][j];
                if (j > 0) p[i][j] += p[i][j - 1];
                if (i > 0 && j > 0) p[i][j] -= p[i - 1][j - 1];
            }
    }
    int get(int i, int j) {
        if (i < 0 || j < 0) return 0;
        return p[i][j];
    }
    int get(int i1, int j1, int i2, int j2) {
        --i1, --j1;
        return get(i2, j2) - get(i1, j2) - get(i2, j1) + get(i1, j1);
    }
};
 
int16_t dp[N][N][N];
pref R, G, B, Y;
 
signed main() {
    FAST; FIXED; RANDOM;
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'R') R.add(i, j);
            if (s[j] == 'G') G.add(i, j);
            if (s[j] == 'B') B.add(i, j);
            if (s[j] == 'Y') Y.add(i, j);
        }
    }
    R.countpref();
    G.countpref();
    B.countpref();
    Y.countpref();
    #pragma omp parallel for
    for (int i = 0; i < n - 1; ++i)
        #pragma omp parallel for
        for (int j = 0; j < m - 1; ++j) {
            int i1 = i, i2 = i + 1, j1 = j, j2 = j + 1;
            while (i1 >= 0 && i2 < n && j1 >= 0 && j2 < m) {
                int val = 0;
                val += R.get(i1, j1, i, j);
                val += G.get(i1, j + 1, i, j2);
                val += Y.get(i + 1, j1, i2, j);
                val += B.get(i + 1, j + 1, i2, j2);
                if (val == (i2 - i1 + 1) * (j2 - j1 + 1)) {
                    checkmax(dp[i1][j1][i2 - i1 + 1], (i2 - i1 + 1) >> 1);
                } else break;
                --i1, ++i2, --j1, ++j2;
            }
        }
    for (int len = 1; len <= 10000; ++len)
        #pragma omp parallel for
        for (int i = 0; i <= n - len; ++i)
            #pragma omp parallel for
            for (int j = 0; j <= m - len; ++j) {
                checkmax(dp[i][j][len], dp[i][j][len - 1]);
                checkmax(dp[i][j][len], dp[i + 1][j][len - 1]);
                checkmax(dp[i][j][len], dp[i][j + 1][len - 1]);
                checkmax(dp[i][j][len], dp[i + 1][j + 1][len - 1]);
            }
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1, --c1, --r2, --c2;
        int ans = 0;
        if (r2 - r1 < c2 - c1) {
            int len = r2 - r1 + 1;
            #pragma omp parallel for
            for (int i = c1; i <= c2 + 1 - len; ++i)
                checkmax(ans, dp[r1][i][len]);
        } else {
            int len = c2 - c1 + 1;
            #pragma omp parallel for
            for (int i = r1; i <= r2 + 1 - len; ++i)
                checkmax(ans, dp[i][c1][len]);
        }
        ans *= 2;
        cout << ans * ans << '\n';
    }
    return 0;
}