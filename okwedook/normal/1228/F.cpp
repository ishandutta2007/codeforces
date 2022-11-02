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
#define chmin(a, b) (a > b ? a = b, 1 : 0)
#define chmax(a, b) (a < b ? a = b, 1 : 0)

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
    template<class T> void pdbg(const T &x) { print(x); }
    template<class T, class U> void pdbg(const pair<T, U> &p) {
        print('{');
        pdbg(p.f);
        print(',');
        pdbg(p.s); 
        print('}');
    }
    void pdbg(const string &s) { print("\"" + s + "\""); }
    template<class It> void pdbg(It begin, It end, string d);
    template<class T> void pdbg(const vector<T> &a) { pdbg(all(a), ""); }
    template<class T> void pdbg(const vector<vector<T>> &a) { pdbg(all(a), "\n"); }
    template<class T> void pdbg(const vector<vector<vector<T>>> &a) { pdbg(all(a), "\n\n"); }
    template<class T> void pdbg(const set<T> &a) { pdbg(all(a), ""); }
    template<class T> void pdbg(const hashset<T> &a) { pdbg(all(a), ""); }
    template<class T, class U> void pdbg(const map<T, U> &a) { pdbg(all(a), ""); }
    template<class T, class U> void pdbg(const hashmap<T, U> &a) { pdbg(all(a), ""); }
    template<class It> void pdbg(It begin, It end, string d) {
        print('{');
        if (begin != end) pdbg(*begin++);
        while (begin != end)
            print(",", d), pdbg(*begin++);
        print('}');
    }
    template<class T> void dbgout(const T &x) { pdbg(x); }
    template<class T, class... U>
    void dbgout(T const &t, const U &... u) {
        pdbg(t);
        print(", ");
        dbgout(u...);
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = "), dbgout(__VA_ARGS__), flushln()
#else
    #define dbg(...) 0
#endif

template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

graph G;
vector<int> sub;

void countsub(int v, int p = -1) {
    sub[v] = 1;
    for (auto i : G[v])
        if (i != p) {
            countsub(i, v);
            sub[v] += sub[i];
        }
}

int findcentroid(int v, int had, int p = -1) {
    for (auto i : G[v])
        if (i != p && sub[i] * 2 >= had)
            return findcentroid(i, had, v);
    return v;
}

vector<int> h;
int n;

void dfsh(int v, int he = 0, int p = -1) {
    h[v] = he;
    for (auto i : G[v])
        if (i != p)
            dfsh(i, he + 1, v);
}

vector<int> need;

graph tree;

void orient(int v, int p = -1) {
    for (auto i : G[v])
        if (i != p) {
            tree[v].pb(i);
            orient(i, v);
        }
}

set<int> ans;

void solve(int v) {
    h = vector<int>(sz(G));
    dfsh(v);
    if (*max_element(all(h)) >= sz(need)) return;
    vector<int> cnt(sz(need));
    for (auto i : h) ++cnt[i];
    //dbg(v);
    tree = graph(sz(G));
    orient(v);
    //dbg(v);
    //for (int i = 0; i < sz(G); ++i) dbg(sz(tree[v]));
    vector<int> poss;
    for (int i = 0; i < sz(G); ++i)
        if (sz(tree[i]) % 2 != 0) poss.pb(i);
    if (sz(poss) == 1) {
        int x = poss[0];
        dbg(x);
        dbg(h[x]);
        if (!((sz(tree[x]) == 1) && (h[x] == sz(need) - 2) || (sz(tree[x]) == 3) && (h[x] < sz(need) - 2))) return;
        int now = h[poss[0]] + 1;
        //dbg(cnt);
        for (int add = 1, sub = 2; now < sz(need); ++now, add *= 2, sub *= 2) {
            cnt[now] += add;
            if (now < sz(need) - 1) cnt[now] -= sub;
        }
        if (cnt == need) ans.insert(poss[0]);
    }
}

signed main() {
    FAST; FIXED;
    int n;
    read(n);
    need = vector<int>(n);
    for (int i = 0; i < n; ++i) need[i] = pow(2, i);
    G = graph(pow(2, n) - 2);
    for (int i = 1; i < sz(G); ++i) {
        int u, v;
        read(u, v);
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    for (auto i : G)
        if (sz(i) > 4) {
            dbg(i);
            println(0);
            return 0;
        }
    sub = vector<int>(sz(G));
    countsub(0);
    int v = findcentroid(0, sz(G));
    vector<int> tries = {v};
    for (auto i : G[v]) tries.pb(i);
    for (auto i : tries)
        solve(i);
    println(sz(ans));
    for (auto i : ans) print(i + 1, ' ');
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}