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

const ll inf = 1e9 + 7;


int x[maxn];
int y[maxn];

int main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    
    int n; cin >> n; n *= 4; n++;
    for (int j = 1; j <= n; j++) cin >> x[j] >> y[j];

    for (int x1 = 0; x1 <= 50; x1++) {
        for (int y1 = 0; y1 <= 50; y1++) {
            for (int l = 0; l <= 50; l++) {
                int x2 = x1 + l, y2 = y1 + l;
                int on = 0, no = -1;
                for (int j = 1; j <= n; j++) {
                    if (x[j] < x1 || x2 < x[j]) { no = j; continue; }
                    if (y[j] < y1 || y2 < y[j]) { no = j; continue; }
                    if (x[j] == x1 || x[j] == x2 || y[j] == y1 || y[j] == y2) {
                        on++; continue;
                    }
                    no = j;
                }
                if (on == n - 1) {
                    cout << x[no] << " " << y[no] << endl;
                    return 0;
                }
            }
        }
    }
}