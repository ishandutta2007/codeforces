////#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)));
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

const int maxn = 2e6 + 7;

const ll inf = 1e9 + 7;

void possible(int a, vector < int > &v) {
    v.pb(1);
    for (int s = 2; s <= a + 1; s++) {
        int x = (a + s - 1) / s, y = a / (s - 1);
        if (x <= y) v.pb(s);
    }
}

int a[maxn];

void solve() {
    int n; cin >> n;
    for (int j = 1; j <= n; j++) cin >> a[j];
    sort(a + 1, a + n + 1);
    vector < int > cur, poss, nx; 
    cur.clear(); poss.clear(); nx.clear();
    bool put = false;
    for (int j = 1; j <= n; ) {
        int i = j;
        while (i + 1 <= n && a[i + 1] == a[j]) i++;
        int c = i - j + 1;
        if (!put) possible(c, cur);
        else {
            poss.clear(); possible(c, poss);
            nx = cur; cur.clear(); 
            set_intersection(all(poss), all(nx), back_inserter(cur));
        }
        put = true;
        j = i + 1;
    }
    assert(cur.size() >= 0);
    int s = cur.back();
    int ans = 0;
    for (int j = 1; j <= n; ) {
        int i = j;
        while (i + 1 <= n && a[i + 1] == a[j]) i++;
        int c = i - j + 1;
        ans += (c + s - 1) / s;
        j = i + 1;
    }
    cout << ans << endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    int t; cin >> t;
    while (t--) solve();
}