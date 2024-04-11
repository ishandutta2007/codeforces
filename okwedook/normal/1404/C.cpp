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

template<class T> struct Fenv {
    int N, LOG;
    T *fenv;
    Fenv(int N) {
        this->N = N;
        LOG = log2(N);
        fenv = new T[N];
        for (int i = 0; i < N; ++i) fenv[i] = 0;
    }
    ~Fenv() { delete [] fenv; }
    void add(int r, T x) { //adds x to a[r]
        for (; r < N; r |= r + 1) fenv[r] += x;
    }
    T get(int r) { //sum of [0, r]
        T ans = 0;
        for (; r >= 0; r = (r & r + 1) - 1) 
            ans += fenv[r];
        return ans;
    }
    T get(int l, int r) { //sum of [l, r]
        return get(r) - get(l - 1);
    }
    int lb(T k) { //first index which sum is >= k
        int ans = -1;
        for (int l = LOG; l >= 0; --l) {
            int next = ans + (1 << l);
            if (next < N && k > fenv[next]) {
                ans = next;
                k -= fenv[next];
            }
        }
        return ans + 1;
    }
};

signed main() {
    FAST; FIXED;
    int n, q;
    read(n, q);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        read(a[i]);
        a[i] = i + 1 - a[i];
        if (a[i] < 0) a[i] = n + 2;
    }
    dbg(a);
    vector<vector<int>> start(n), finish(n);
    for (int i = 0; i < q; ++i) {
        int x, y;
        read(x, y);
        start[x].pb(i);
        finish[n - y - 1].pb(i);
    }
    vector<int> ind(q, -1), ans(q, -1);
    int ptr = 0;
    Fenv<int> fenv(q + 1);
    for (int i = 0; i < n; ++i) {
        for (auto i : start[i])
            ind[i] = ptr++;
        int l = -1, r = ptr;
        while (r - l > 1) {
            int mid = r + l >> 1;
            if (fenv.get(mid, q - 1) >= a[i]) l = mid;
            else r = mid;
        }
        if (l >= 0) fenv.add(l, 1);
        for (auto i : finish[i])
            ans[i] = fenv.get(ind[i], q - 1);
    }
    for (auto i : ans) println(i);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}