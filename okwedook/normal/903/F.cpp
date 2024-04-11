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

const int MX = 4;
const int N = MX * MX;
const int all_bits = (1 << N) - 1;

inline int get_id(int i, int j) {
    return j * MX + i;
}

vector<string> get_map(int mask) {
    vector<string> ans(MX, string(MX, '.'));
    for (int i = 0; i < MX; ++i) {
        for (int j = 0; j < MX; ++j) {
            int id = get_id(i, j);
            if (mask >> id & 1) {
                ans[i][j] = '*';
            }
        }
    }
    return ans;
}

int get_mask(const vector<string> &s) {
    int mask = 0;
    for (int i = 0; i < MX; ++i) {
        for (int j = 0; j < MX; ++j) {
            int id = get_id(i, j);
            if (s[i][j] == '*') {
                mask |= 1 << id;
            }
        }
    }
    return mask;
}

signed main() {
    initIO();
    int n;
    read(n);
    vector<int> cost(MX);
    read(cost);
    vector<string> in(MX);
    read(in);
    vector<int> next(1 << N);
    for (int was = 0; was < (1 << N); ++was) {
        auto state = get_map(was);
        if (any_of(all(state), [](const string &s) { return s[MX - 1] == '*'; })) {
            next[was] = -1;
        } else {
            vector<string> new_state(MX, string(MX, '.'));
            for (int i = 0; i < MX; ++i) {
                for (int j = 0; j < MX - 1; ++j) {
                    new_state[i][j + 1] = state[i][j];
                }
            }
            next[was] = get_mask(new_state);
        }
    }
    vector<pii> moves;
    for (int len = 1; len <= MX; ++len) {
        for (int i = 0; i + len <= MX; ++i) {
            vector<string> upd_state(MX, string(MX, '*'));
            for (int j = i; j < i + len; ++j) {
                for (int d = 0; d < len; ++d) {
                    upd_state[j][d] = '.';
                }
            }
            // dbg(upd_state);
            moves.pb({get_mask(upd_state), cost[len - 1]});
        }
    }
    vector<int> dp(1 << N, mod);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int upd = 0;
        for (int j = 0; j < MX; ++j) {
            if (in[j][i] == '*') {
                upd |= 1 << j;
            }
        }
        // Add new layer
        {
            vector<int> newdp(1 << N, mod);
            for (int was = 0; was < (1 << N); ++was) {
                if (next[was] != -1) {
                    chmin(newdp[next[was] | upd], dp[was]);
                }
            }
            dp = move(newdp);
        }
        // Support moves to dot
        {
            for (int was = (1 << N) - 1; was >= 0; --was) {
                for (auto [and_mask, cost] : moves) {
                    chmin(dp[was & and_mask], dp[was] + cost);
                }
            }
        }
    }
    println(dp[0]);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}