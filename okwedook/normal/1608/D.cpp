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
#include <functional>

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
#define mod 998244353
#define inf 3000000000000000007ll
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

void flush() { cout << flush; }
void flushln() { cout << endl; }
void println() { cout << '\n'; }
template<class T> void print(const T &x) { cout << x; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }

#ifdef DEBUG
    template<class T> string pdbg(const T &x) { stringstream ss; ss << x; return ss.str(); }
    template<class T, class U> string pdbg(const pair<T, U> &p) { return "{" + pdbg(p.f) + "," + pdbg(p.s) + "}"; }
    string pdbg(const string &s) { return "\"" + s + "\""; }
    template<class It> string pdbg(It begin, It end, string d);
    template<class T> string pdbg(const vector<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const vector<vector<T>> &a) { return pdbg(all(a), "\n"); }
    template<class T> string pdbg(const vector<vector<vector<T>>> &a) { return pdbg(all(a), "\n\n"); }
    template<class T> string pdbg(const set<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const hashset<T> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const map<T, U> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const hashmap<T, U> &a) { return pdbg(all(a), ""); }
    template<class It> string pdbg(It begin, It end, string d) {
        string ans;
        ans += "{";
        if (begin != end) ans += pdbg(*begin++);
        while (begin != end)
            ans += "," + d + pdbg(*begin++);
        ans += "}";
        return ans;
    }
    template<class T> string dbgout(const T &x) { return pdbg(x); }
    template<class T, class... U>
    string dbgout(T const &t, const U &... u) {
        string ans = pdbg(t);
        ans += ", ";
        ans += dbgout(u...);
        return ans;
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = ", dbgout(__VA_ARGS__)), flushln()
    #define msg(...) print("[", __VA_ARGS__, "]"), flushln()
#else
    #define dbg(...) 0
    #define msg(...) 0
#endif

template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
template<class T, class U> inline bool chmax(T &x, const U& y) { return y > x ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

map<char, vector<char>> poss = {
    {'W', {'W'}},
    {'B', {'B'}},
    {'?', {'W', 'B'}}
};

struct zet {
    int val;
    explicit operator int() const { return val; }
    zet(ll x = 0) { val = (x >= -mod && x < mod ? x : x % mod); if (val < 0) val += mod; }
    zet(ll a, ll b) { *this += a; *this /= b; }

    zet& operator+=(zet const &b) { val += b.val; if (val >= mod) val -= mod; return *this; }
    zet& operator-=(zet const &b) { val -= b.val; if (val < 0) val += mod; return *this; }
    zet& operator*=(zet const &b) { val = (val * (ll)b.val) % mod; return *this; }

    friend zet mypow(zet a, ll n) {
        zet res = 1;
        while (n) { if (n & 1) res *= a; a *= a; n >>= 1; }
        return res;
    }
    friend zet inv(zet a) { return mypow(a, mod - 2); }
    zet& operator/=(zet const& b) { return *this *= inv(b); }
    friend zet operator+(zet a, const zet &b) { return a += b; }
    friend zet operator-(zet a, const zet &b) { return a -= b; }
    friend zet operator-(zet a) { return 0 - a; }
    friend zet operator*(zet a, const zet &b) { return a *= b; }
    friend zet operator/(zet a, const zet &b) { return a /= b; }
    friend istream& operator>>(istream& stream, zet &a) { return stream >> a.val; }
    friend ostream& operator<<(ostream& stream, const zet &a) { return stream << a.val; }
    friend bool operator==(zet const &a, zet const &b) { return a.val == b.val; }
    friend bool operator!=(zet const &a, zet const &b) { return a.val != b.val; }
    friend bool operator<(zet const &a, zet const &b) { return a.val < b.val; }
};

template<int md, int maxpw = 23>
struct NTT {
    int mul(int a, int b) {
        return a * (ll)b % md;
    }
    int sum(int a, int b) {
        a += b;
        if (a >= md) a -= md;
        return a;
    }
    int diff(int a, int b) {
        a -= b;
        if (a < 0) a += md;
        return a;
    }
    int mpow(int a, int n) {
        int ans = 1;
        for (; n > 0; n >>= 1, a = mul(a, a))
            if (n & 1) ans = mul(ans, a);
        return ans;
    }
    int lst(int n) const { return 31 - __builtin_clz(n); }
    vector<int> sq;
    NTT() {
        int rt = 2;
        while (mpow(rt, 1 << maxpw) != 1 || mpow(rt, 1 << maxpw - 1) == 1) ++rt;
        sq = vector<int>(maxpw + 1);
        sq[maxpw] = rt;
        for (int i = maxpw - 1; i >= 0; --i)
            sq[i] = mul(sq[i + 1], sq[i + 1]);
    }
    vector<int> ind;
    void dft(vector<int> &a, int n) {
        int LOG = lst(n);
        if (sz(ind) != n) {
            ind.resize(n);
            for (int i = 1; i < n; ++i) {
                int l = lst(i);
                ind[i] = ind[i ^ (1 << l)] | (1 << LOG - 1 - l);
            }
        }
        vector<int> cp(n);
        for (int i = 0; i < n; ++i) cp[i] = a[ind[i]];
        swap(a, cp);
        for (int len = 2; len <= n; len *= 2) {
            int w = sq[lst(len)];
            int l2 = len >> 1, msk = l2 - 1;
            for (int i = 0; i < n; i += len) {
                int c = 1;
                for (int j = 0; j < l2; ++j) {
                    int x = a[i + j], y = mul(a[i + l2 + j], c);
                    a[i + j] = sum(x, y);
                    a[i + j + l2] = diff(x, y);
                    c = mul(c, w);
                }
            }
        }
    }
    vector<int> multiply(vector<int> a, vector<int> b) {
        int n = 1;
        while (n < sz(a) || n < sz(b)) n *= 2;
        n *= 2;
        a.resize(n);
        b.resize(n);
        dft(a, n);
        dft(b, n);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = mul(a[i], b[i]);
        dft(ans, n);
        reverse(ans.begin() + 1, ans.end());
        int inv = mpow(n, md - 2);
        for (auto &i : ans) i = mul(i, inv);
        return ans;
    }
};

NTT<998244353> ntt;

vector<int> findans(vector<string> s) {
    if (sz(s) == 1) {
        vector<int> ans(3);
        for (char cl : poss[s[0][0]]) {
            for (char cr : poss[s[0][1]]) {
                if (cl == 'W' && cr == 'W') ++ans[0];
                else if (cl == 'B' && cr == 'B') ++ans[2];
                else ++ans[1];
            }
        }
        return ans;
    }
    int mid = sz(s) / 2;
    auto lft = findans(vector<string>(s.begin(), s.begin() + mid));
    auto rgt = findans(vector<string>(s.begin() + mid, s.end()));
    auto ans = ntt.multiply(lft, rgt);
    ans.resize(sz(lft) + sz(rgt) - 1);
    return ans;
}

signed main() {
    FAST; FIXED;
    int n;
    read(n);
    // map<vector<int>, zet> dp;
    // dp[{0, 0, 0, 0}] = 1;
    // for (int i = 0; i < n; ++i) {
    //     string t;
    //     read(t);
    //     map<vector<int>, zet> newdp;
    //     for (auto cl : poss[t[0]]) {
    //         for (auto cr : poss[t[1]]) {
    //             for (auto [was_state, cnt] : dp) {
    //                 auto state = was_state;
    //                 string c;
    //                 c += cl;
    //                 c += cr;
    //                 state[0] += c == "WW";
    //                 state[1] += c == "WB";
    //                 state[2] += c == "BW";
    //                 state[3] += c == "BB";
    //                 newdp[state] += cnt;
    //             }
    //         }
    //     }
    //     dp = move(newdp);
    // }
    vector<string> s(n);
    read(s);
    zet ans = findans(s)[n];
    dbg(ans);
    vector<zet> dp(1 << 4);
    dp[0] = 1;
    for (int i = 0; i < sz(s); ++i) {
        vector<int> pid;
        for (char cl : poss[s[i][0]]) {
            for (char cr : poss[s[i][1]]) {
                int id = 0;
                if (cl == 'B') id |= 1;
                if (cr == 'B') id |= 2;
                pid.pb(id);
            }
        }
        dbg(pid);
        vector<zet> newdp(1 << 4);
        for (int was = 0; was < sz(dp); ++was) {
            for (auto id : pid) {
                newdp[was | (1 << id)] += dp[was];
            }
        }
        dp = move(newdp);
    }
    ans -= dp[(1 << 1) | (1 << 2)];
    dbg(dp);
    println(ans);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}