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

template<class T, class U> inline bool chmax(T &x, U y) { return x < y ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

signed main() {
    FAST; FIXED;
    int n;
    read(n);
    vector<int> a(n);
    read(a);
    a.pb(0);
    vector<int> ind(sz(a));
    iota(all(ind), 0);
    sort(all(ind), [&](int i, int j) { return a[i] > a[j]; });
    vector<int> ans = {-1, -1, -1};
    vector<int> answer = {0, 0, 0};
    for (int sum12 = 2; sum12 < n; ++sum12) {
        vector<int> val(n - sum12 + 1, -mod);
        for (int c3 = 1; sum12 + c3 <= n; ++c3)
            val[c3] = a[ind[sum12 + c3 - 1]] - a[ind[sum12 + c3]];
        vector<int> v12(n, -mod);
        vector<pii> segm(n), c1c2(n);
        for (int c1 = 1; c1 < sum12; ++c1) {
            int c2 = sum12 - c1;
            int l = (max(c1, c2) + 1) / 2, r = (min(c1, c2) * 2);
            chmax(l, 1);
            chmin(r, n - sum12);
            if (l <= r && min(c1, c2) * 2 >= max(c1, c2)) {
                segm[r - l] = {l, r};
                //dbg(c1, c2, l, r);
                if (chmax(v12[r - l], a[ind[c1 - 1]] - a[ind[c1]]))
                    c1c2[r - l] = {c1, c2};
            }
        }
        int pt = 0;
        while (pt < sz(v12) && v12[pt] < 0) ++pt;
        if (pt == sz(v12)) continue;
        int l = segm[pt].s + 1, r = segm[pt].s;
        int mx = r;
        for (int i = pt; i < sz(v12); ++i)
            if (v12[i] >= 0) {
                while (l > segm[i].f) {
                    --l;
                    if (val[mx] < val[l]) mx = l;
                }
                while (r < segm[i].s) {
                    ++r;
                    if (val[mx] < val[r]) mx = r;
                }
                if (val[mx] >= 0) {
                    if (chmax(ans, vector<int>{v12[i], a[ind[sum12 - 1]] - a[ind[sum12]], val[mx]}))
                        answer = {c1c2[i].f, c1c2[i].s, mx};
                }
            } 
    }
    vector<int> x(n, -1);
    answer[1] += answer[0];
    answer[2] += answer[1];
    for (int i = 0; i < answer[0]; ++i)
        x[ind[i]] = 1;
    for (int i = answer[0]; i < answer[1]; ++i)
        x[ind[i]] = 2;
    for (int i = answer[1]; i < answer[2]; ++i)
        x[ind[i]] = 3;
    for (auto i : x) print(i, ' ');
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}