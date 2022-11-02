// , [05.09.21 15:49]
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

struct RecSolver {
    vector<ll> a;
    vector<ll> ans;
    RecSolver() {}
    void rec(int i, ll curr) {
        if (i == sz(a)) {
            ++ans[__builtin_popcountll(curr)];
            return;
        }
        rec(i + 1, curr);
        rec(i + 1, curr ^ a[i]);
    }
    vector<ll> solve(vector<ll> _a, int m) {
        a = _a;
        ans = vector<ll>(m + 1);
        rec(0, 0);
        return ans;
    }
};

signed main() {
    FAST; FIXED;
    int n, m;
    read(n, m);
    vector<ll> a(n);
    read(a);
    int ptr = 0;
    auto getbit = [](ll a, int ind) {
        return a >> ind & 1;
    };
    for (int bit = 0; bit < m && ptr < m; ++bit) {
        int ind = -1;
        while (ind == -1 && ptr < m) {
            for (int i = bit; i < n; ++i)
                if (getbit(a[i], ptr)) {
                    ind = i;
                    break;
                }
            if (ind == -1) {
                ++ptr;
            } else {
                break;
            }
        }
        if (ind == -1) {
            break;
        }
        swap(a[bit], a[ind]);
        for (int i = 0; i < n; ++i)
            if (i != bit && getbit(a[i], ptr))
                a[i] ^= a[bit];
    }
    while (sz(a) && a.back() == 0) {
        a.popb();
    }
    auto swapbits = [&](ll &x, int i, int j) {
        ll vi = getbit(x, i);
        ll vj = getbit(x, j);
        x = x ^ (vi << i) ^ (vj << j) ^ (vi << j) ^ (vj << i);
    };
    for (int i = 0; i < sz(a); ++i) {
        int firstbit = __builtin_ctzll(a[i]);
        for (auto &v : a)
            swapbits(v, i, firstbit);
    }
    int k = sz(a);
    dbg(a);
    #ifdef DEBUG
    for (int i = 0; i < sz(a); ++i) {
        for (int j = 0; j < m; ++j) {
            print(getbit(a[i], j));
        }
        println();
    }
    #endif
    zet x = mypow(zet(2), n - k);
    vector<ll> ans(m + 1);
    if (k <= 29) {
        ans = RecSolver().solve(a, m);
    } else {
        assert(m - k <= 15);
        ll rest = 1ll << (m - k);
        vector<vector<ll>> dp(k + 1, vector<ll>(rest));
        dp[0][0] = 1;
        ll maskrest = (rest - 1) << k;
        for (auto x : a) {
            auto newdp = dp;
            ll restx = (x & maskrest) >> k;
            dbg(restx);
            for (int wascnt = 0; wascnt < k; ++wascnt)
                for (ll wasrest = 0; wasrest < rest; ++wasrest) {
                    ll nowrest = wasrest ^ restx;
                    newdp[wascnt + 1][nowrest] += dp[wascnt][wasrest];
                }
            dp = move(newdp);
        }
        for (int cnt = 0; cnt <= k; ++cnt)
            for (int mask = 0; mask < rest; ++mask)
                ans[cnt + __builtin_popcountll(mask)] += dp[cnt][mask];
    }
    for (int i = 0; i < sz(ans); ++i)
        print(ans[i] * x, ' ');
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}