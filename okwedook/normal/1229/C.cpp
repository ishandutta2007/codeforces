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
#include <random>
#include <cassert>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
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
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)]);
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
 
template<class T> struct myarr {
    T *a;
    int sz = 0;
    void reserve(int n) {
        a = new T[n];
    }
    size_t size() {
        return sz;
    }
    void push_back(T x) {
        a[sz++] = x;
    }
    void clear() {
        sz = 0;
    }
    T operator[](int ind) const {
        return a[ind];
    }
};

void read(int &x) {
    static char c;
    while ((c = getchar()) >= '0')
        x = (x << 3) + (x << 1) + (c - '0');
}

myarr<int> in[100000];
int cnt[100000];
pair<int, int> edge[100000];
ll ans = 0;
 
ll count(int v) {
    return sz(in[v]) * (ll)(cnt[v] - sz(in[v]));
}

void print(ll x) {
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    FAST; FIXED; RANDOM;
    int n = 0, m = 0;
    read(n); read(m);
    for (int i = 0; i < m; ++i) {
        read(edge[i].f), read(edge[i].s);
        --edge[i].f, --edge[i].s;
        if (edge[i].f > edge[i].s) swap(edge[i].f, edge[i].s);
        ++cnt[edge[i].f];
        ++cnt[edge[i].s];
    }
    for (int i = 0; i < n; ++i) in[i].reserve(cnt[i]);
    for (int i = 0; i < m; ++i) 
        in[edge[i].f].pb(edge[i].s);
    for (int i = 0; i < n; ++i) ans += count(i);
    print(ans);
    putchar('\n');
    int q = 0;
    read(q);
    while (q--) {
        int v = 0;
        read(v);
        --v;
        ans -= count(v);
        for (int i = 0; i < sz(in[v]); ++i) {
            ans += cnt[in[v][i]] - 2 * sz(in[in[v][i]]) - 1;
            in[in[v][i]].pb(v);
        }
        in[v].clear();
        print(ans);
        putchar('\n');
    }
    return 0;
}