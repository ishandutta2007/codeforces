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

int rec(const graph &G, vector<bool> &used, int v) {
    if (used[v]) return 0;
    int ans = sz(G[v]);
    used[v] = true;
    for (auto i : G[v])
        ans += rec(G, used, i);
    return ans;
}

vector<unordered_multiset<int>> G;

void addedge(int u, int v) {
    G[u].insert(v);
    G[v].insert(u);
}

void deledge(int u, int v) {
    G[u].erase(G[u].find(v));
    G[v].erase(G[v].find(u));
}

vector<int> findEulerCycle(int v) {
    vector<int> st;
    vector<int> ans;
    st.pb(v);
    while (sz(st)) {
        auto v = st.back();
        if (sz(G[v]) == 0) {
            ans.pb(v);
            st.popb();
        } else {
            int u = *G[v].begin();
            deledge(v, u);
            st.pb(u);
        }
    }
    return ans;
}

pair<bool, vector<int>> tryfind(int center, int cntedge) {
    vector<int> odd;
    for (int i = 0; i < sz(G); ++i)
        if (sz(G[i]) % 2 == 1)
            odd.pb(i);
    if (sz(odd) > 2) return {false, {}};
    if (sz(odd) == 2 && odd[0] != center && odd[1] != center)
        return {false, {}};
    if (sz(odd) == 2) {
        addedge(odd[0], odd[1]);
    }
    auto copy = G;
    auto ans = findEulerCycle(center);
    G = move(copy);
    if (sz(odd) == 2) {
        ans.popb();
        deledge(odd[0], odd[1]);
    }
    if (sz(ans) != cntedge + 1) return {false, {}};
    reverse(ans);
    return {true, ans};
}

void writeans(vector<int> eulerpath, vector<int> star, int center) {
    println(sz(eulerpath) + 1 + sz(star) * 2);
    for (auto i : eulerpath) print(i + 1, ' ');
    print(-1, ' ');
    for (auto i : star) {
        print(i + 1, ' ');
        print(center + 1, ' ');
    }
    println();
    exit(0);
}

signed main() {
    FAST; FIXED;
    int n, m;
    read(n, m);
    vector<int> cnt(n);
    vector<pii> edge;
    for (int i = 0; i < m; ++i) {
        int u, v;
        read(u, v);
        --u, --v;
        ++cnt[u];
        ++cnt[v];
        edge.pb({u, v});
    }
    dbg(cnt);
    G = vector<unordered_multiset<int>>(n);
    for (int center = 0; center < n; ++center) {
        auto curr = cnt;
        int v = -1;
        int cntedge = 0;
        for (int i = 0; i < n; ++i)
            G[i].clear();
        vector<int> star;
        for (auto i : edge)
            if (i.f == center && curr[i.s] % 2 == 1 ||
                i.s == center && curr[i.f] % 2 == 1) {
                --curr[i.f];
                --curr[i.s];
                star.pb(i.f ^ i.s ^ center);
            } else {
                G[i.f].insert(i.s);
                G[i.s].insert(i.f);
                cntedge++;
                v = i.f;
            }
        auto check = tryfind(center, cntedge);
        if (check.f) {
            writeans(check.s, star, center);
        } else {
            for (int i = 0; i < sz(star); ++i) {
                int v = star[i];
                star.erase(star.begin() + i);
                ++cntedge;
                G[center].insert(v);
                G[v].insert(center);
                auto check = tryfind(center, cntedge);
                if (check.f) {
                    writeans(check.s, star, center);
                }
                G[center].erase(G[center].find(v));
                G[v].erase(G[v].find(center));
                --cntedge;
                star.insert(star.begin() + i, v);
            }
        }
    }
    println(0);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}