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

const ll mod = 1e9 + 7;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 1e6 + 7;
const ll inf = 1e9;

int n;

int u[maxn];
int v[maxn];
ll w[maxn];
int dsu[maxn]; 

inline void init() {
    for (int j = 1; j <= n; j++) dsu[j] = -1;
}
int findS(int x) {
    if (dsu[x] < 0) return x;
    return (dsu[x] = findS(dsu[x]));
}
inline void unionS(int x, int y) {
    if (findS(x) == findS(y)) return;
    dsu[x] = y;
} 

vector < pair<pll, pii> > ed;

int main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    
    int E; cin >> n >> E;
    for (int j = 1; j <= E; j++) {
        cin >> u[j] >> v[j] >> w[j];
    }
    ll l = 0, r = inf;
    while (l < r) {
        ll m = (l + r + 1) / 2;
        w[1] = m;
        ed.clear();
        ed.pb({{w[1], 0}, {u[1], v[1]}});
        for (int j = 2; j <= E; j++) {
            ed.pb({{w[j], inf} , {u[j], v[j]}});
        }
        sort(ed.begin(), ed.end());
        init();
        for (auto z : ed) {
            int id = z.F.S, x, y; tie(x, y) = z.S;
            if (id == 0) {
                if (findS(x) != findS(y)) {
                    l = m;
                } else {
                    r = m - 1;
                }
                break;
            } else {
                if (findS(x) != findS(y)) unionS(findS(x), findS(y));
            }
        }
    }
    cout << l << endl;
}