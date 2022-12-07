//#define DEBUG
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

int arr[40];
int dp[41][41];
int d,m;

void solveDP()
{
    for(int i=39;i>=1;i--)
    {
        dp[i][1] = (arr[i]+dp[i+1][1])%m;
    }
    for(int siz = 2;siz<40;siz++)
    {
        for(int idx = 39;idx>=1;idx--)
        {
            dp[idx][siz] = dp[idx+1][siz] + (arr[idx]*dp[idx+1][siz-1])%m;
            dp[idx][siz]%=m;
        }
    }
}

void solve()
{
    memset(arr,0,sizeof(arr));
    memset(dp,0,sizeof(dp));
    cin>>d>>m;

    int cur = 0;
    int val = 1;
    int idx = 1;
    int nex;
    while(cur<d)
    {
        nex = val+cur;
        if(nex>d)
            val = d - cur;
        arr[idx] = val%m;
        idx++;
        cur+=val;
        val*=2;
    }

    solveDP();

    int ans = 0;
    for(int siz=1;siz<40;siz++)
    {
        ans+=dp[1][siz];
        ans%=m;
    }

    cout<<ans<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}