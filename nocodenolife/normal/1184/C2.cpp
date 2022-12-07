//#define DEBUG
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

const int shf = 2e6 + 7;
const int maxn = 2 * shf;

const ll inf = 1e9 + 7;

pii pt[maxn];
int S[4 * maxn];
int lz[4 * maxn];

void init(int x, int l, int r) {
    S[x] = lz[x] = 0;
    if (l == r) return;
    int m = (l + r) >> 1;
    init(x + x, l, m); init(x + x + 1, m + 1, r);
}

inline void push(int x) {
    if (lz[x] == 0) return;
    S[x + x] += lz[x]; lz[x + x] += lz[x];
    S[x + x + 1] += lz[x]; lz[x + x + 1] += lz[x];
    lz[x] = 0;
}

void upd(int x, int l, int r, int i, int j, int v) {
    if (j < l || r < i) return;
    if (i <= l && r <= j) {
        S[x] += v; lz[x] += v;
        return;
    }
    push(x);
    int m = (l + r) >> 1;
    upd(x + x, l, m, i, j, v); upd(x + x + 1, m + 1, r, i, j, v);
    S[x] = max(S[x + x], S[x + x + 1]);
}


int main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    
    int n; int R; cin >> n >> R; R *= 2;
    for (int j = 1; j <= n; j++) {
        int x, y; cin >> x >> y;
        pt[j].F = x + y; pt[j].S = x - y; pt[j].F += shf; pt[j].S += shf;
    }
    sort(pt + 1, pt + n + 1);
    dbg(for (int j = 1; j <= n; j++) cout << pt[j].F - shf << ", " << pt[j].S - shf << endl;);
    int l = 1; int ans = 0;
    init(1, 0, maxn);
    for (int j = 1; j <= n; j++) {
        dbg(cout << pt[j].F << " .. " << pt[j].S << endl;);
        while (pt[l].F < pt[j].F - R) {
            dbg(cout << "rem : " << l << endl;);
            upd(1, 0, maxn, max(0, pt[l].S - R), pt[l].S, -1);
            l++;
        }
        dbg(cout << " ok " << endl;);
        upd(1, 0, maxn, max(0, pt[j].S - R), pt[j].S, +1);
        dbg(cout << "?? " << endl;);
        ans = max(ans, S[1]);
    }
    cout << ans << endl;
}