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

const int maxn = 2e6 + 7;

const ll inf = 1e9 + 7;
int n;
int coun[maxn];
int maxVal,minVal;
int k;

void solve()
{
    cin>>n>>k;

    memset(coun,0, sizeof(coun));
    maxVal = 0;
    minVal = inf;
    int u,v;
    for(int i=0;i<n;i++)
    {
        cin>>u;
        coun[u]++;
        maxVal = max(maxVal,u);
        minVal = min(minVal,u);
    }

    for(int i=1;i<maxn;i++)
    {
        coun[i] += coun[i-1];
    }

    if(minVal < k + 2)
    {
        cout<<minVal<<endl;
        return;
    }

    //k+1 is always possible.
    //Check all answers from maxVal to k+1;
    int maxa, l,r,sum;

    for(int val = maxVal; val>=1;val--)
    {
        //check number of values in [a*val , a*val+ k] for all a;
        sum = 0;
        maxa = maxVal/val;
//        cout<<maxa<<endl;
        for(int i=1;i<=maxa;i++)
        {
            l = i*val;
            r = l+k;
            //sum count in l:r
//            cout<<l<<" "<<r<<endl;
            sum += coun[r] - coun[l-1];
//            cout<<coun[r]-coun[l-1]<<endl;
        }

        if(sum==n)
        {
            cout<<val<<endl;
            return;
        }
    }
//    assert(false);
//    cout<<"Impossible"<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    PRELUDE;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}