#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

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
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

#ifdef DEBUG
    template<class T> T to_dbg(T x) { return x; }
    template<class T, class U> string to_dbg(pair<T, U> p) {
        stringstream ss;
        ss << '{' << p.f << ',' << p.s << '}';
        return ss.str();
    }
    string to_dbg(string s) { return "\"" + s + "\""; }
    template<class It> string to_dbg(It begin, It end, string d = "") {
        stringstream ss;
        ss << '{';
        if (begin != end) ss << to_dbg(*begin++);
        while (begin != end)
            ss << "," << d << to_dbg(*begin++);
        ss << '}';
        return ss.str();
    }
    template<class T> string to_dbg(vector<T> a) { return to_dbg(all(a)); }
    template<class T> string to_dbg(set<T> a) { return to_dbg(all(a)); }
    template<class T> string to_dbg(hashset<T> a) { return to_dbg(all(a)); }
    template<class T, class U> string to_dbg(map<T, U> a) { return to_dbg(all(a), "\n"); }
    template<class T, class U> string to_dbg(hashmap<T, U> a) { return to_dbg(all(a), "\n"); }
    template<class T> void dbgout(T x) { cout << to_dbg(x) << endl; }
    template<class T, class... U>
    void dbgout(T t, U... u) {
        cout << to_dbg(t) << ", ";
        dbgout(u...);
    }
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", dbgout(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif

template<class T, class U> inline bool chmax(T &x, U y) { return x < y ? x = y, 1 : 0; }
template<class T, class U> inline bool chmin(T &x, U y) { return x > y ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }
void read() {} void print() {} void println() { cout << '\n'; }
template<class T, class ...U> void read(T &x, U& ... u) { cin >> x; read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { cout << x; print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { cout << x; println(u...); }

signed main() {
    FAST; FIXED;
    int n, m;
    read(n, m);
    vector<int> a(n);
    read(a);
    map<int, int> cnt;
    for (auto i : a) cnt[i]++;
    vector<pii> b(all(cnt));
    if (sz(b) == 1) {
        println(b[0].s / 3);
        return 0;
    }
    int ans = 0;
    for (auto &i : b) {
        while (i.s - 3 >= 5) {
            ++ans;
            i.s -= 3;
        }
    }
    n = sz(b);
    vector<int> mx(n);
    for (int i = 0; i < n; ++i)
        mx[i] = b[i].s + 1;
    vector<vector<vector<int>>> dp(n);
    for (int i = 1; i < n; ++i)
        dp[i] = vector<vector<int>>(mx[i - 1], vector<int>(mx[i], -mod));
    dp[1][b[0].s][b[1].s] = 0;
    for (int i = 1; i < n; ++i) {
        if (i >= 2) {
            for (int c2 = 0; c2 < mx[i - 2]; ++c2)
                for (int c1 = 0; c1 < mx[i - 1]; ++c1) {
                    int c0 = b[i].s;
                    if (b[i - 2].f + 2 == b[i].f && b[i - 1].f + 1 == b[i].f) {
                        for (int d = 0; d <= c2 && d <= c1 && d <= c0; ++d)
                            chmax(dp[i][c1 - d][c0 - d], dp[i - 1][c2][c1] + d);
                    } else {
                        chmax(dp[i][c1][c0], dp[i - 1][c2][c1]);
                    }
                }
        }
        for (int c1 = 0; c1 < mx[i - 1]; ++c1)
            for (int c0 = 0; c0 < mx[i]; ++c0) 
                for (int d1 = 0; d1 * 3 <= c1; ++d1) 
                    for (int d0 = 0; d0 * 3 <= c0; ++d0) {
                        chmax(dp[i][c1 - d1 * 3][c0], dp[i][c1][c0] + d1);
                        chmax(dp[i][c1][c0 - d0 * 3], dp[i][c1][c0] + d0);
                        chmax(dp[i][c1 - d1 * 3][c0 - d0 * 3], dp[i][c1][c0] + d0 + d1);
                    }
    }
    int add = 0;
    for (int i = 0; i < mx[n - 2]; ++i)
        for (int j = 0; j < mx[n - 1]; ++j)
            chmax(add, dp[n - 1][i][j]);
    println(add + ans);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}