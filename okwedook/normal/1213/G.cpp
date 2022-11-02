#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
 
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
 
vector<ll> p, sub;
ll sum = 0;

int getp(int v) {
    return v == p[v] ? v : p[v] = getp(p[v]);
}

ll get(ll x) {
    return x * (x - 1) / 2;
}

void unite(int a, int b) {
    a = getp(a);
    b = getp(b);
    if (a == b) return;
    if (sub[a] > sub[b]) swap(a, b);
    sum -= get(sub[a]);
    sum -= get(sub[b]);
    p[a] = b;
    sub[b] += sub[a];
    sum += get(sub[b]);
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    vector<pair<int, pii>> edge(n - 1);
    for (auto &i : edge) cin >> i.s.f >> i.s.s >> i.f, --i.s.f, --i.s.s;
    sort(all(edge));
    p = sub = vector<ll>(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        sub[i] = 1;
    }
    vector<ll> ans(m);
    vector<pii> query(m);
    for (int i = 0; i < m; ++i)
        cin >> query[i].f, query[i].s = i;
    sort(query);
    int ptr = 0;
    for (auto i : query) {
        while (ptr < sz(edge) && edge[ptr].f <= i.f) {
            unite(edge[ptr].s.f, edge[ptr].s.s);
            ++ptr;
        }
        ans[i.s] = sum;
    }
    for (auto i : ans) cout << i << ' ';
    return 0;
}