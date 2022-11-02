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

signed main() {
    FAST; FIXED;
    int zero = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 4) | (1 << 5) | (1 << 6);
    int one = (1 << 2) | (1 << 5);
    int two = (1 << 0) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 6);
    int three = (1 << 0) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6);
    int four = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 5);
    int five = (1 << 0) | (1 << 1) | (1 << 3) | (1 << 5) | (1 << 6);
    int six = (1 << 0) | (1 << 1) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
    int seven = (1 << 0) | (1 << 2) | (1 << 5);
    int eight = (1 << 7) - 1;
    int nine = eight ^ (1 << 4);
    vector<int> masks = { zero, one, two, three, four, five, six, seven, eight, nine };
    vector<vector<pii>> edge(1 << 7);
    for (int mask = 0; mask < (1 << 7); ++mask)
        for (int j = 9; j >= 0; --j) {
            if ((masks[j] & mask) == mask)
                edge[mask].pb({j, __builtin_popcount(masks[j] - mask)});
        }
    int n, k;
    cin >> n >> k;
    vector<int> msk(n);
    for (auto &i : msk) {
        string s;
        cin >> s;
        for (int j = 0; j < sz(s); ++j)
            if (s[j] == '1') i |= 1 << j;
    }
    vector<bitset<2001>> dp(n + 1, bitset<2001>());
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; --i)
        for (auto x : edge[msk[i]])
            dp[i] |= dp[i + 1] << x.s;
    if (!dp[0][k]) cout << -1;
    else {
        for (int i = 0; i < n; ++i) {
            for (auto x : edge[msk[i]]) {
                if (k >= x.s && dp[i + 1][k - x.s]) {
                    cout << x.f;
                    k -= x.s;
                    break;
                }
            }
        }
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}