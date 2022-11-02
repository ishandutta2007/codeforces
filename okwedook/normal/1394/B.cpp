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

vector<int> perm;
vector<vector<vector<pii>>> banned;

int n, m, k;
int ans = 0;

void rec(int i) {
    if (i == k) {
        ++ans;
        //dbg(perm);
        return;
    }
    for (int j = 0; j <= i; ++j) {
        perm.pb(j);
        bool can = true;
        for (auto v : banned[i][j])
            if (perm[v.f] == v.s) {
                can = false;
                break;
            }
        if (can) rec(i + 1);
        perm.popb();
    }
}

signed main() {
    FAST; FIXED;
    read(n, m, k);
    vector<pair<int, pii>> edges(m);
    for (auto &i : edges) read(i.s, i.f), --i.s.f, --i.s.s;
    sort(edges);
    vector<int> out(n);
    vector<vector<pii>> in(n);
    for (auto i : edges) {
        //dbg(i.s.f + 1, i.s.s + 1, out[i.s.f]);
        in[i.s.s].pb({i.s.f, out[i.s.f]});
        out[i.s.f]++;
    }
    banned.resize(k);
    for (int i = 0; i < k; ++i) banned[i].resize(i + 1);
    for (int i = 0; i < n; ++i) {;
        vector<pii> ban;
        for (auto x : in[i]) {
            int v = out[x.f] - 1, t = x.s;
            //dbg(x.f + 1, v, t, i);
            ban.pb({v, t});
        }
        sort(ban);
        for (int i = 0; i < sz(ban) - 1; ++i) {
            if (ban[i] == ban[i + 1]) {
                banned[ban[i].f][ban[i].s].pb(ban[i]);
            }
        }
        ban.resize(unique(all(ban)) - ban.begin());
        //dbg(i, ban);
        for (int i = 0; i < sz(ban); ++i)
            for (int j = i + 1; j < sz(ban); ++j)
                banned[ban[j].f][ban[j].s].pb(ban[i]);
    }
    for (int i = 0; i < k; ++i)
        for (int j = 0; j <= i; ++j) {
            auto &v = banned[i][j];
            sort(v);
            v.resize(unique(all(v)) - v.begin());
        }
    rec(0);
    println(ans);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}