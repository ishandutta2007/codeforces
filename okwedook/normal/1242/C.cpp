#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC optimize("fast-math")
 
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
#define ll int
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

vector<vector<pii>> dp[(1 << 15) + 5];

inline void read(int &x) {
    char c = getchar();
    if (c == '-') {
        x = 0;
        while (c = getchar(), c >= '0')
            x = (x << 3) + (x << 1) + (c - '0');
        x = -x;
    } else {
        x = (c - '0');
        while (c = getchar(), c >= '0')
            x = (x << 3) + (x << 1) + (c - '0');
    }
}

inline void print(int x) {
    for (auto c : to_string(x))
        putchar(c);
}

inline void print(string s) {
    for (auto i : s)
        putchar(i);
}
 
signed main() {
    FAST;
    int k;
    read(k);
    vector<vector<ll>> a(k);
    for (auto &i : a) {
        int n;
        read(n);
        i = vector<ll>(n);
        for (auto &j : i) read(j);
    }
    vector<long long> need(k);
    for (int i = 0; i < k; ++i)
        for (auto &j : a[i])
            need[i] += j;
    long long sum = 0;
    for (auto i : need) sum += i;
    if (sum % k != 0) {
        print("No\n");
        return 0;
    }
    sum /= k;
    hashmap<int, pii> in;
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < sz(a[i]); ++j) in[a[i][j]] = {i, j};
    for (auto &i : dp)
        i.reserve(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < sz(a[i]); ++j) {
            vector<pii> changes;
            int mask = 0;
            pii pos = {i, j};
            bool flag = true;
            do {
                if (mask >> pos.f & 1) {
                    flag = false;
                    break;
                }
                changes.pb(pos);
                mask |= 1 << pos.f;
                long long x = sum - need[pos.f] + a[pos.f][pos.s];
                if (x < -(1ll << 31) || x >= (1ll << 32) || !in.count(x)) {
                    flag = false;
                    break;
                }
                pos = in[x];
            } while (pos != pii(i, j));
            if (flag && sz(dp[mask]) == 0) dp[mask].pb(changes);
        }
    }
    for (int mask = 0; mask < (1 << k); ++mask) {
        if (sz(dp[mask]) == 0) {
            for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                if (sz(dp[sub]) && sz(dp[mask ^ sub])) {
                    for (auto i : dp[sub]) dp[mask].pb(i);
                    for (auto i : dp[sub ^ mask]) dp[mask].pb(i);
                    break;
                }
            }
        }
    }
    if (sz(dp[(1 << k) - 1]) == 0) print("No\n");
    else {
        print("Yes\n");
        vector<pii> ans(k);
        for (auto i : dp[(1 << k) - 1]) {
            for (int j = 0; j < sz(i); ++j)
                ans[i[(j + 1) % sz(i)].f] = {a[i[(j + 1) % sz(i)].f][i[(j + 1) % sz(i)].s], i[j].f};
        }
        for (auto i : ans) {
            print(i.f);
            putchar(' ');
            print(i.s + 1);
            putchar('\n');
        }
    }
    return 0;
}