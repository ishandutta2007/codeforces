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
#include <chrono>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
#define ll int
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

graph G;
vector<int> sub;
int cnt = 0;

int leftasks;

int ask(int u, int v) {
    --leftasks;
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    int ans;
    cin >> ans;
    --ans;
    return ans;
}

void answer(int x) {
    cout << "! " << x + 1 << endl;
    exit(0);
}

void orient(int v, int p = -1) {
    sub[v] = 1;
    for (auto i : G[v])
        if (i != p) {
            orient(i, v);
            sub[v] += sub[i];
        }
}

int findcentroid(int v, int sb, int p = -1) {
    for (auto i : G[v])
        if (i != p && sub[i] * 2 >= sb)
            return findcentroid(i, sb, v);
    return v;
}

int dfs(int v) {
    int p = -1;
    while (true) {
        vector<int> sons;
        for (auto i : G[v])
            if (i != p) sons.pb(i);
        if (sz(sons) == 0) return v;
        sort(all(sons), [&](int i, int j) {
            return sub[i] > sub[j];
        });
        for (int i = 0; i + 1 < sz(sons); i += 2) {
            int x = ask(sons[i], sons[i + 1]);
            if (x != v) {
                p = v;
                v = x;
                goto go;
            }
        }
        if (sz(sons) % 2 == 1 && ask(v, sons.back()) == sons.back()) {
            p = v;
            v = sons.back();
            goto go;
        }
        return v;
        go:;
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    leftasks = n / 2;
    vector<bool> used(n);
    G = graph(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    sub = vector<int>(n);
    orient(0);
    int v = findcentroid(0, sub[0]);
    orient(v);
    answer(dfs(v));
    return 0;
}