//#define DEBUG
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
// Ordered set docs:
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

// To remove randomization use 0 below:
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
    x = x%mod;
    ex = ex % (mod-1);
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
int n;
int h[maxn];
int r[maxn];
int R[maxn];

ld totHeights[maxn];

ld getDiff(int fir, int toAdd)
{
    ld del = 0;
    if(r[toAdd] >= R[fir])
        return (h[fir]+0.0);
    if(R[toAdd] <= r[fir])
    {
        return 0.0;
    }
    //r[toAdd] < R[fir] && R[toadd] > r[fir]
    if(r[toAdd]>r[fir])
    {
        //bottom of toAdd is greater then gets stuck in between.
        //find height of upper that equal the top radius of lower one
        ld he = (r[toAdd] - r[fir]+0.0)*(h[fir]+0.0)/(R[fir] - r[fir]+0.0);
        del = max(del,he);
    }
    if(R[toAdd]<=R[fir])
    {
        //top of the bowl gets stuck
        ld he = (R[toAdd]-r[fir]+0.0)*(h[fir]+0.0)/(R[fir]-r[fir]+0.0);
        he = he - h[toAdd];
        del = max(del,he);
    } else{
        //new bowl is bulging out.
        ld he = h[fir] - ((R[fir]-r[toAdd]+0.0)*(h[toAdd]+0.0)/(R[toAdd]-r[toAdd]+0.0));
        del = max(del,he);
    }
    return del;
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>h[i]>>r[i]>>R[i];
    }

    totHeights[1] = 0.0;

    ld x;
    ld ans = h[1]+0.0;
    for(int i=2;i<=n;i++)
    {
        x = 0.0;
        for(int j=1;j<i;j++)
        {
            x = max(x,totHeights[j]+getDiff(j,i));
        }
        //cout<<x<<endl;
        totHeights[i] = x;
        ans = max(ans, totHeights[i] + h[i]+0.0);
    }
    cout<<setprecision(15);
    cout<<ans<<endl;
}
//New comment
i32 main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //PRELUDE;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}