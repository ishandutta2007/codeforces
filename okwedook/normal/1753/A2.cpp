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
#define by_key(...) [](const auto &a, const auto &b) { return a.__VA_ARGS__ < b.__VA_ARGS__; }

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
    // Declaration (for cross-recursion)
    template<class T>
    auto pdbg(const T&x) -> enable_if_t<!TypeTraits::NonStringIterable<T>, string>;
    string pdbg(const string &x);
    template<class T>
    auto pdbg(const T &x) -> enable_if_t<TypeTraits::NonStringIterable<T>, string>;
    template<class T, class U>
    string pdbg(const pair<T, U> &x);

    // Implementation
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

void solve() {
    int n;
    read(n);
    vector<int> a(n);
    read(a);
    int sum = 0;
    for (auto i : a) sum += i;
    if (sum < 0) {
        for (auto &i : a) {
            i = -i;
        }
        sum = -sum;
    }
    assert(sum >= 0);
    if (sum % 2 != 0) {
        println(-1);
        return;
    }
    vector<pii> ans;
    if (sum == 0) {
        for (int i = 0; i < n; ++i) {
            ans.pb({i, i});
        }
    } else {
        sum /= 2;
        // need to make exactly sum minus ones
        vector<int> ind;
        for (int i = 1; i < n; ++i) {
            if (a[i] == 1) {
                ind.pb(i);
            }
        }
        vector<int> dp(sz(ind), 1);
        vector<int> p(sz(ind), -1);
        if (sz(ind) >= 2 && ind[1] > ind[0] + 1) {
            dp[1] = 2;
            p[1] = 0;
        }
        for (int i = 2; i < sz(ind); ++i) {
            dp[i] = dp[i - 2] + 1;
            p[i] = i - 2;
            if (ind[i] > ind[i - 1] + 1 && chmax(dp[i], dp[i - 1] + 1)) {
                p[i] = i - 1;
            }
        }
        int mx = max_element(all(dp)) - dp.begin();
        if (dp[mx] < sum) {
            println(-1);
            return;
        }
        vector<bool> mark(n);
        for (int i = 0; i < sum; ++i, mx = p[mx]) {
            mark[ind[mx]] = true;
            mark[ind[mx] - 1] = true;
        }
        for (int i = 0; i < n; ++i) {
            if (!mark[i]) {
                ans.pb({i, i});
            } else {
                ans.pb({i, i + 1});
                ++i;
            }
        }
    }
    assert(sz(ans) > 0);
    assert(ans[0].f == 0);
    assert(ans.back().s == n - 1);
    for (int i = 0; i + 1 < sz(ans); ++i) {
        assert(ans[i + 1].f == ans[i].s + 1);
    }
    int x = 0;
    for (auto [l, r] : ans) {
        for (int i = l; i <= r; ++i) {
            x += a[i] * (i - l & 1 ? -1 : 1);
        }
        dbg(x);
    }
    assert(x == 0);
    println(sz(ans));
    for (auto [l, r] : ans) {
        println(l + 1, ' ', r + 1);
    }
}

signed main() {
    initIO();
    int t;
    read(t);
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}