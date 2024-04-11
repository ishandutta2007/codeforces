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
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", dbgout(__VA_ARGS__);
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

vector<vector<int>> petlya;
struct edge {
    int v;
    bool used;
    int rev;
    int ind;
};
vector<vector<edge>> G;
vector<int> ptr, ans;

bool flag;

void build(int v) {
    if (sz(G[v]) % 2 == 1) flag = true;
    while (true) {
        while (ptr[v] < sz(G[v]) && G[v][ptr[v]].used)
            ++ptr[v];
        if (ptr[v] == sz(G[v])) break;
        auto &e = G[v][ptr[v]];
        e.used = G[e.v][e.rev].used = true;
        build(e.v);
    }
    ans.pb(v);
    for (auto i : petlya[v]) ans.pb(v);
    petlya[v].clear();
}

void build(int n, const vector<int> &a, const vector<int> &b, int m) {
    petlya = vector<vector<int>>(1 << m);
    G = vector<vector<edge>>(1 << m);
    for (int i = 0; i < n; ++i) {
        int u = a[i] % sz(G);
        int v = b[i] % sz(G);
        if (u == v) petlya[u].pb(i);
        else {
            int pu = sz(G[u]), pv = sz(G[v]);
            G[u].pb({v, false, pv, i});
            G[v].pb({u, false, pu, i});
        }
    }
    flag = false;
    for (int i = 0; i < sz(G); ++i)
        if (sz(G[i]) || sz(petlya[i])) {
            ptr.assign(sz(G), 0);
            ans.clear();
            build(i);
            break;
        }
}

signed main() {
    FAST; FIXED;
    int n;
    read(n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) read(a[i], b[i]);
    int l = 0, r = 21;
    while (r - l > 1) {
        int m = r + l >> 1;
        build(n, a, b, m);
        if (sz(ans) == n + 1 && !flag) l = m;
        else r = m;
    }
    for (auto &i : a) i %= 1 << l;
    for (auto &i : b) i %= 1 << l;
    map<pii, vector<int>> st;
    for (int i = 0; i < n; ++i) st[{a[i], b[i]}].pb(i);
    build(n, a, b, l);
    vector<int> answer;
    for (int i = 0; i + 1 < sz(ans); ++i) {
        int u = ans[i], v = ans[i + 1];
        if (sz(st[pii(u, v)]) > 0) {
            answer.pb(2 * st[{u, v}].back());
            st[{u, v}].popb();
        } else {
            answer.pb(2 * st[{v, u}].back() + 1);
            st[{v, u}].popb();
        }
        answer.pb(answer.back() ^ 1);
    }
    cout << l << '\n';
    for (auto i : answer) print(i + 1, ' ');
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}