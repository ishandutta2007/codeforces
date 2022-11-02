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
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
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
 
const int N = 1e4 * 1e3 + 100;
int dist[N];
int g, r;
 
inline int getind(int v, int t) {
    return v * g + t;
}
 
inline pii getind(int v) {
    return {v / g, v % g};
}
 
struct cmp {
    bool operator()(int i, int j) const {
        return dist[i] > dist[j];
    }
};
 
signed main() {
    FAST; FIXED;
    int n, m;
    cin >> n >> m;
    vector<int> d(m);
    cin >> d;
    sort(d);
    cin >> g >> r;
    for (int i = 1; i < m; ++i)
        if (d[i] - d[i - 1] > g) {
            cout << -1;
            return 0;
        }
    for (int i = 0; i < m * g; ++i)
        dist[i] = mod;
    dist[getind(0, 0)] = 0;
    priority_queue<int, vector<int>, cmp> que;
    que.push(getind(0, 0));
    int need = getind(m - 1, 0);
    while (sz(que)) {
        int f = que.top();
        que.pop();
        int v = f / g, t = f % g;
        for (int u = max(v - 1, 0); u <= min(v + 1, m - 1); ++u) 
            if (u != v) {
                int add = abs(d[v] - d[u]);
                if (add + t < g) {
                    if (ifmin(dist[getind(u, add + t)], dist[f] + add))
                        que.push(getind(u, add + t));
                } else if (add + t == g) {
                    if (ifmin(dist[getind(u, 0)], dist[f] + add + r))
                        que.push(getind(u, 0));
                }
            }
    }
    ll ans = inf;
    for (int i = 0; i < m; ++i)
        if (d[m - 1] - d[i] <= g)
            checkmin(ans, dist[getind(i, 0)] + d[m - 1] - d[i]);
    if (ans > m * (g + r)) cout << -1;
    else cout << ans;
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}