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
#include <cstring>
 
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
 
const int N = 1e5 + 100;
graph G;
bool used[N];
int h[N];
int need;
int start;
 
vector<int> vert;
 
void rnddfs(int v, int he = 0) {
    shuffle(all(G[v]), gen);
    vert.pb(v);
    h[v] = he;
    used[v] = true;
    for (auto i : G[v]) {
        if (used[i] && h[v] - h[i] + 1 >= need) {
            cout << 2 << '\n' << h[v] - h[i] + 1 << '\n';
            for (int j = h[i]; j <= h[v]; ++j) cout << vert[j] + 1 << ' ';
            exit(0);
        }
        if (!used[i]) rnddfs(i, he + 1);
    }
    vert.popb();
}
 
signed main() {
    FAST; FIXED;
    int n, m;
    cin >> n >> m;
    need = ceil(sqrt(n));
    G = graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i;
    for (int t = 0; t < 20; ++t) {
        shuffle(all(perm), gen);
        vector<int> ans;
        memset(used, 0, sizeof(used));
        for (auto i : perm) {
            for (auto j : G[i])
                if (used[j]) {
                    goto go;
                }
            ans.pb(i);
            used[i] = true;
            if (sz(ans) == need) {
                cout << 1 << '\n';
                for (auto i : ans) cout << i + 1 << ' ';
                return 0;
            }
            go:;
        }
    }
    while (clock() < 0.9 * CLOCKS_PER_SEC) {
        memset(used, 0, sizeof(used));
        start = gen() % n;
        rnddfs(start);
        break;
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}