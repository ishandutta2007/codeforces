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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    cin >> a;
    vector<vector<bool>> from(n, vector<bool>(m)), to(n, vector<bool>(m));
    from[0][0] = to[n - 1][m - 1] = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '.') {
                if (i > 0 && from[i - 1][j]) from[i][j] = true;
                if (j > 0 && from[i][j - 1]) from[i][j] = true;
            }
    for (int i = n - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j)
            if (a[i][j] == '.') {
                if (i < n - 1 && to[i + 1][j]) to[i][j] = true;
                if (j < m - 1 && to[i][j + 1]) to[i][j] = true;
                to[i][j] = to[i][j] && from[i][j];
            }
    if (!from[n - 1][m - 1]) {
        cout << 0;
        return 0;
    }
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for (int i = 0; i < n + m - 3; ++i) {
        if (x1 < n - 1 && to[x1 + 1][y1]) ++x1;
        else ++y1;
        if (y2 < m - 1 && to[x2][y2 + 1]) ++y2;
        else ++x2;
        if (x1 == x2 && y1 == y2) {
            cout << 1;
            return 0;
        }
    }
    cout << 2;
    return 0;
}