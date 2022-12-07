#define DEBUG
// #define FASTIO

#include <cstring>
#include <cassert>
#include <utility>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <tuple>
#include <climits>
#include <limits>
#include <deque>
#include <list>
#include <array>
#include <stack>
#include <queue>
#include <random>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#define F first
#define S second 
#define pb push_back
#define endl "\n"

#ifdef FASTIO

#define pr(x) printf("%d", x)
#define ps    printf(" ")
#define endc  printf("\n")
#define pl(x) printf("%lld", x)
#define pf(x) printf("%lf", x)
#define sc(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define sf(x) scanf("%lf", &x)
#define IOS 

#endif

#ifndef FASTIO
    #define IOS { ios :: sync_with_stdio(false); cin.tie(0); }
#endif

#ifdef DEBUG
    #define dbg(s) {s;}
#endif

#ifndef DEBUG
    #define dbg(s)
#endif

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { // from [0, n-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 

const ll mod = 2e5 + 7;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 2e5 + 7;
const int lmx = 19;
const ll inf = 1e9 + 7;

int dsu[maxn];
vector < pair<pll, pii> > ed;
inline void unionS(int x, int y) {
    dsu[x] = y;
}
int findS(int x) {
    if (dsu[x] < 0) return x;
    return (dsu[x] = findS(dsu[x]));
}

vector < pll > G[maxn];
int dep[maxn];
int pi[maxn][lmx];
ll  mx[maxn][lmx]; 

void dfs(int x, int p, ll w, int d) {
    pi[x][0] = p; mx[x][0] = w;
    dep[x] = d;
    for (int j = 1; j < lmx; j++) {
        if (pi[x][j - 1] < 0) {
            pi[x][j] = pi[x][j - 1]; mx[x][j] = mx[x][j - 1];
        } else {
            pi[x][j] = pi[pi[x][j - 1]][j - 1];
            mx[x][j] = max(mx[x][j - 1], mx[pi[x][j - 1]][j - 1]);
        }
    }
    for (auto z : G[x]) {
        int y; ll w; tie(y, w) = z;
        if (y == p) continue;
        dfs(y, x, w, d + 1);
    }
}

ll pmx(int x, int y) {
    if (dep[x] > dep[y]) return pmx(y, x);
    ll ans = 0;
    for (int j = lmx - 1; j >= 0; j--) {
        if (pi[y][j] < 0 || dep[pi[y][j]] < dep[x]) continue;
        ans = max(ans, mx[y][j]); y = pi[y][j];
    }
    if (x == y) return ans;
    for (int j = lmx - 1; j >= 0; j--) {
        if (pi[x][j] < 0 || pi[y][j] < 0) continue;
        int a = pi[x][j], b = pi[y][j];
        if (a == b) continue;
        ans = max(ans, mx[x][j]); ans = max(ans, mx[y][j]);
        x = a; y = b;
    }
    if (x == y) return ans;
    ans = max(ans, mx[x][0]); ans = max(ans, mx[y][0]);
    return ans;
}

vector < pll > ans;

int main() {

    IOS;
    
    int n, m; cin >> n >> m;
    fill(dsu, dsu + maxn, -1);

    for (int j = 1; j <= m; j++) {
        int x, y; ll w; cin >> x >> y >> w;
        ed.pb({{w, j}, {x, y}});
    }
    sort(ed.begin(), ed.end());
    for (int j = 0; j < ed.size(); j++) {
        auto z = ed[j];
        ll w = z.F.F;
        int x, y; tie(x, y) = z.S;
        int a = findS(x), b = findS(y);
        if (a == b) continue; unionS(a, b);
        // cout << x << " .. " << y << endl;
        G[a].pb({b, w}); G[b].pb({a, w});
        ed[j].F.S = -1;
    }

    dfs(1, -1, 0, 0);
    
    for (auto z : ed) {
        if (z.F.S < 0) continue;
        int x, y; tie(x, y) = z.S;
        ans.pb({z.F.S, pmx(x, y)});
    }
    sort(ans.begin(), ans.end());
    for (auto z : ans) {
        cout << z.S << endl;
    }
}