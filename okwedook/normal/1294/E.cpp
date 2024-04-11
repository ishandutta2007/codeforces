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

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    cin >> a;
    for (auto &i : a)
        for (auto &j : i)
            --j;
    vector<vector<int>> d = a, md = a;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            d[i][j] /= m;
            md[i][j] %= m;
        }
    int ans = 0;
    for (int j = 0; j < m; ++j) {
        vector<int> cnt(n);
        for (int i = 0; i < n; ++i)
            if (md[i][j] == j && d[i][j] < n) {
                cnt[(i - d[i][j] + n) % n]++;
            }
        int start = 0;
        for (int i = 0; i < n; ++i)
            if (cnt[i] > cnt[start] && cnt[i] > i) start = i;
        ans += start;
        vector<int> newa(n);
        for (int i = 0; i < n; ++i)
            newa[i] = a[(i + start) % n][j];
        for (int i = 0; i < n; ++i) a[i][j] = newa[i];
    }
    int ptr = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != ptr) ++ans;
            ++ptr;
        }
    cout << ans;
    return 0;
}