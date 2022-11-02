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

vector<int> getmult(vector<int> p) {
    auto prev = p;
    reverse(prev);
    auto mult = ntt.multiply(p, prev);
    return mult;
}

void solve() {
    int n;
    read(n);
    string(s);
    read(s);
    vector<int> v(n), k(n), vq(n), kq(n), q(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'V') {
            v[i] = 1;
            vq[i] = 1;
        }
        if (s[i] == 'K') {
            k[i] = 1;
            kq[i] = 1;
        }
        if (s[i] == '?') {
            vq[i] = kq[i] = q[i] = 1;
        }
    }
    auto multv = getmult(vq);
    auto multk = getmult(kq);
    auto multq = getmult(q);
    reverse(vq);
    reverse(kq);
    reverse(q);
    auto multvrev = getmult(vq);
    auto multkrev = getmult(kq);
    auto multqrev = getmult(q);
    vector<bool> ans(n + 1);
    for (int d = 1; d < n; ++d) {
        int check = multv[n - d - 1] + multk[n - d - 1] - multq[n - d - 1];
        int checkrev = multvrev[n - d - 1] + multkrev[n - d - 1] - multqrev[n - d - 1];
        if (check == n - d && checkrev == n - d) {
            ans[d] = 1;
        }
    }
    ans[n] = 1;
    for (int i = n; i > 0; --i)
        for (int j = i; j <= n; j += i)
            if (ans[j] == 0)
                ans[i] = 0;
    vector<int> answer;
    for (int i = 0; i <= n; ++i)
        if (ans[i]) answer.pb(i);
    println(sz(answer));
    for (auto i : answer) print(i, ' ');
    println();
}

signed main() {
    FAST; FIXED;
    int t;
    read(t);
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}