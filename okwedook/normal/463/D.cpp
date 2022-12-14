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
#include <complex>
#include <random>
#include <cassert>
#include <chrono>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
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

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

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

bool check(const vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < sz(a); ++i)
        if (a[i] > b[i]) return false;
    return true;
}

signed main() {
    FAST; FIXED;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> p(k, vector<int>(n));
    cin >> p;
    for (auto &i : p)
        for (auto &j : i)
            --j;
    vector<vector<int>> pos(n, vector<int>(k));
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < n; ++j)
            pos[p[i][j]][i] = j;
    vector<int> ind(n);
    for (int i = 0; i < n; ++i) ind[i] = i;
    sort(all(ind), [&](int i, int j) {
        return pos[i] < pos[j];
    });
    vector<int> dp(n, 1);
    for (auto i : ind)
        for (auto j : ind)
            if (i != j && check(pos[j], pos[i]))
                checkmax(dp[i], dp[j] + 1);
    int ans = 0;
    for (auto i : dp) checkmax(ans, i);
    cout << ans;
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}