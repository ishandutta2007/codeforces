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

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

graph G, tree;
vector<pii> deep;
int ans = 0;
vector<int> answer = {0, 1, 2};

void orient(int v, int p = -1) {
    deep[v] = {0, v};
    for (auto i : G[v])
        if (i != p) {
            orient(i, v);
            tree[v].pb(i);
            checkmax(deep[v], pii(deep[i].f + 1, deep[i].s));
        }
}

void dfsdp(int v, pii past) {
    vector<pii> mx;
    for (auto i : tree[v])
        mx.pb(deep[i]);
    rsort(mx);
    if (sz(mx) >= 1 && v != past.s) {
        if (ifmax(ans, past.f + mx[0].f + 1))
            answer = {past.s, v, mx[0].s};
    }
    if (sz(mx) >= 2) {
        if (ifmax(ans, past.f + mx[0].f + 1 + mx[1].f + 1))
            answer = {past.s, mx[0].s, mx[1].s};
    }
    if (sz(mx) >= 3) {
        if (ifmax(ans, mx[0].f + mx[1].f + mx[2].f + 3))
            answer = {mx[0].s, mx[1].s, mx[2].s};
    }
    set<pii> st;
    for (auto i : tree[v])
        st.insert(deep[i]);
    for (auto i : tree[v]) {
        st.erase(deep[i]);
        pii newpast = past;
        if (sz(st)) {
            auto val = *--st.end();
            ++val.f;
            checkmax(newpast, val);
        }
        dfsdp(i, {newpast.f + 1, newpast.s});
        st.insert(deep[i]);
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    G = tree = graph(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    deep = vector<pii>(n);
    orient(0);
    dfsdp(0, {0, 0});
    cout << ans << '\n';
    for (auto i : answer) cout << i + 1 << ' ';
    set<int> st(all(answer));
    assert(sz(st) == 3);
    return 0;
}