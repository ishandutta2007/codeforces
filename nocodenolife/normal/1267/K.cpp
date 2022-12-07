//////#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)))
#define BREM(a, p) (BCHK(a, p)?(BXOR(a, p)):(a))
#define BSHO(a, N) (bitset<N>(a))

#define fi first
#define sc second 
#define pb push_back


#ifdef DEBUG
    #define dbg(s) {s;}
    #define PRELUDE
#endif

#ifndef DEBUG 
    #define PRELUDE { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
    #define dbg(s)
    #define endl "\n"
#endif

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int ri(int x) { // from [0, n-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

inline ld rf() { // from [0, 1]
    return uniform_real_distribution<ld>(0, 1)(rng);
}

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

const int maxn = 21;

const ll inf = 1e9 + 7;

int a[maxn];
int m;
int t;
int dp[1 << maxn];
i32 ds[1 << maxn];

int calc(int msk) {
    if (msk == 0) return 1;
    if (ds[msk] == t) return dp[msk];
    ds[msk] = t; dp[msk] = 0;
    int k = 2;
    int last = -1;
    for (int j = 0; j < m; j++) {
        k += !BCHK(msk, j);
        if (BCHK(msk, j)) last = a[j];
    }
    if (last == 0) {
        dp[msk] = 0; return 0;
    }
    last = -1;
    for (int j = 0; j < m; j++) {
        if (!BCHK(msk, j)) continue;
        if (a[j] < k && last != a[j]) dp[msk] += calc(BXOR(msk, j));
        last = a[j];
    }
    return dp[msk];
}

int c2(int m) {
    int ans = 1;
    for (int j = 0; j < m; j++) {
        int k = j + 2;
        int i = -1;
        while (i + 1 < m && a[i + 1] < k) i++;
        ans *= (i + 1 - j);
    }
    for (int j = 0; j < m;) {
        int i = j;
        int f = 1;
        while (i + 1 < m && a[i + 1] == a[j]) i++, f *= i-j+1;
        ans /= f;
        j = i + 1;
    }
    return ans;
}

int c3(int m) {
    int x = c2(m);
    if (a[0] == 0) {
        for (int j = 0; j < m - 1; j++) a[j] = a[j + 1];
        x -= c2(m - 1);
    }
    return x;
}

void solve() {
    int n; cin >> n; m = 0;
    for (int j = 2; ;j++) {
        a[m++] = n % j;
        n /= j;
        if (n == 0) break;
    }
    sort(a, a + m);
    cout << c3(m)-1 << endl;
    //cout << calc((1 << m) - 1) - 1 << endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
   
    fill(ds, ds + (1 << maxn), -1);
    cin >> t; while (t--) solve();
}