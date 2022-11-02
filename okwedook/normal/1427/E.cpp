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
#define ll __int128
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
#define inf (1ll << 60)
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
#ifdef DEBUG
    mt19937 gen(85720);
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
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", dbgout(__VA_ARGS__)
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
 
void read(ll &x) {
    long long trash;
    cin >> trash;
    x = trash;
}
 
string getstr(ll x) {
    string ans;
    string sign;
    if (x < 0) x = -x, sign = "-";
    do {
        ans += x % 10 + '0';
        x /= 10;
    } while (x > 0);
    reverse(ans);
    return sign + ans;
}
 
void print(const ll &x) {
    cout << getstr(x);
}
 
void println() { cout << '\n'; }
template<class T> void print(const T &x) { cout << x; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }
 
vector<string> ans;
set<ll> st;
 
void addsum(ll a, ll b) {
    if (a == 0 || b == 0) return;
    if (a + b <= 2 * inf && !st.count(a + b)) {
        ans.pb(getstr(a) + " + " + getstr(b));
        st.insert(a + b);
    }
}
 
void addxor(ll a, ll b) {
    if (a == 0 || b == 0) return;
    if ((a ^ b) <= 2 * inf && !st.count(a ^ b)) {
        ans.pb(getstr(a) + " ^ " + getstr(b));
        st.insert(a ^ b);
    }
}
 
template<class T>
T fullgcd(T a, T b, T &x, T &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    T d = fullgcd(b % a, a, y, x);
    x -= (b / a) * y;
    return d;
}
 
ll gcd(ll a, ll b) {
    return __gcd(a, b);
}
 
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
 
void multiply(ll a, ll b) {
    if (b == 0) return;
    int ptr = 0;
    ll past = a * (b & 1);
    ll sa = a;
    for (int i = 1; i < 60; ++i) {
        if (b >> i & 1) {
            while (ptr < i) {
                addsum(a, a);
                a += a;
                ++ptr;
            }
            addsum(past, a);
            past += a;
        }
    }
}
 
void get(ll vx, ll vy, ll x, ll y, ll need) {
    x *= need;
    y *= need;
    if (x < 0) {
        ll add = (-x + vy - 1) / vy;
        x += vy * add;
        y -= vx * add;
    }
    if (y < 0) {
        ll add = (-y + vx - 1) / vx;
        y += vx * add;
        x -= vy * add;
    }
    multiply(vx, x);
    multiply(vy, y);
    addsum(vx * x, vy * y);
}
 
signed main() {
    FAST; FIXED;
    ll x;
    read(x);
    st.insert(x);
    for (int i = 0; i < 23; ++i)
        addsum(x << i, x << i);
    while (true) {
        vector<ll> v(all(st));
        int ptr = sz(v) - 1;
        for (int i = 0; i < sz(v); ++i) {
            while (ptr >= 0 && v[ptr] > 0 && v[i] > inf / v[ptr]) --ptr;
            for (int j = 0; j <= ptr; ++j) {
                if (v[i] > 0 && v[j] > 0 && gcd(v[i], v[j]) == 1) {
                    ll x, y;
                    fullgcd(v[i], v[j], x, y);
                    ll need = inf;
                    ll need2 = inf + 1;
                    get(v[i], v[j], x, y, need);
                    get(v[i], v[j], x, y, need2);
                    addxor(need, need2);
                    println(sz(ans));
                    for (auto i : ans) println(i);
                    return 0;
                }
            }
        }
        auto ix = st.begin(), iy = st.begin();
        for (int i = gen() % sz(st); i > 0; --i) ++ix;
        for (int i = gen() % sz(st); i > 0; --i) ++iy;
        if (gen() % 10 == 0) addsum(*ix, *iy);
        else addxor(*ix, *iy);
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}