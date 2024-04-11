#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
}

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using graph = vector<vector<int>>;

const ld eps = 1e-9;
const int mod = 1000000007;
const ll inf = 3000000000000000007ll;

#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
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
    namespace TypeTraits {
        template<class T> constexpr bool IsString = false;
        template<> constexpr bool IsString<string> = true;
        template<class T, class = void> struct IsIterableStruct : false_type{};
        template<class T>
        struct IsIterableStruct<
            T,
            void_t<
                decltype(begin(declval<T>())),
                decltype(end(declval<T>()))
            >
        > : true_type{};
        template<class T> constexpr bool IsIterable = IsIterableStruct<T>::value;
        template<class T> constexpr bool NonStringIterable = !IsString<T> && IsIterable<T>;
        template<class T> constexpr bool DoubleIterable = IsIterable<decltype(*begin(declval<T>()))>;
    };
    template<class T>
    auto pdbg(const T &x) -> enable_if_t<!TypeTraits::NonStringIterable<T>, string> {
        stringstream ss;
        ss << x;
        return ss.str();
    }
    template<class T, class U>
    string pdbg(const pair<T, U> &x) {
        return "{" + pdbg(x.f) + "," + pdbg(x.s) + "}";
    }
    string pdbg(const string &x) {
        return "\"" + x + "\"";
    }
    template<class T>
    auto pdbg(const T &x) -> enable_if_t<TypeTraits::NonStringIterable<T>, string> {
        auto begin = x.begin();
        auto end = x.end();
        string del = "";
        if (TypeTraits::DoubleIterable<T>) {
            del = "\n";
        }
        string ans;
        ans += "{" + del;
        if (begin != end) ans += pdbg(*begin++);
        while (begin != end) {
            ans += "," + del + pdbg(*begin++);
        }
        ans += del + "}";
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

const int N = 2e6 + 10;

zet fact[N];

zet C(int n, int k) {
    if (k > n) {
        return 0;
    }
    return fact[n] / (fact[n - k] * fact[k]);
}

void solve() {
    int n, m, k;
    read(n, m, k);
    // vector<vector<zet>> dp(n + 1, vector<zet>(n + 1));
    // for (int i = 0; i <= n; ++i) {
    //     dp[i][i] = zet(k) * i;
    // }
    // for (int i = 0; i <= n; ++i) {
    //     dp[i][0] = 0;
    // }
    // auto div2 = zet(1) / 2;
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 1; j < i; ++j) {
    //         dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) * div2;
    //     }
    // }
    if (m == 0) {
        println(0);
    } else {
        vector<zet> vals;
        for (int m = 0; m < n; ++m) {
            vals.pb(C(n, m));
        }
        // dbg(vals);
        for (int t = 0; t < 2; ++t) {
            for (int i = 1; i < sz(vals); ++i) {
                vals[i] += vals[i - 1];
            }
        }
        // dbg(n);
        // dbg(vals);
        // dbg(vals[m]);
        println(vals[m - 1] / mypow(zet(2), n - 1) * k);
    }
}

signed main() {
    initIO();
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    int t;
    read(t);
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}