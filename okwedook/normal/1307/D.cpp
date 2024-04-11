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

graph G;

vector<int> bfs(int v) {
    queue<int> que;
    vector<int> val(sz(G), -1);
    que.push(v);
    val[v] = 0;
    while (sz(que)) {
        auto f = que.front();
        que.pop();
        for (auto i : G[f])
            if (val[i] == -1) {
                val[i] = val[f] + 1;
                que.push(i);
            }
    }
    return val;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> used(k);
    cin >> used;
    for (auto &i : used) --i;
    G = graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    auto d0 = bfs(0), dn = bfs(n - 1);
    int ans = dn[0];
    sort(all(used), [&](int i, int j) {
        return d0[i] < d0[j];
    });
    int mx = dn[used.back()];
    int check = -1;
    for (int i = sz(used) - 2; i >= 0; --i) {
        checkmax(check, d0[used[i]] + 1 + mx);
        checkmax(mx, dn[used[i]]);
    }
    checkmin(ans, check);
    cout << ans;
    return 0;
}