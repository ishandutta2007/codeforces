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

const ll mod = 998244353 ;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 5e5 + 7;

const ll inf = 1e9 + 7;
int n,m,k;
vector<pair<pii,int>>qu;
vector<pii>zer;
vector<pii> on;

int arr[maxn];
int rig[maxn];
//int seg[maxn*4];
int dp[maxn];
/*int findSum(int idx, int l, int r, int ql, int qr)
{
    if(l>qr || r<ql)
        return 0;
    if(l>=ql && r<=qr)
        return seg[idx];
    int m = l+r;
    m/=2;
    int ans = 0;
    ans+= findSum(idx<<1,l,m,ql,qr);
    ans+= findSum(idx<<1|1,m+1,r,ql,qr);
    ans%=mod;
    return ans;
}

void update(int idx, int l, int r, int ind, int val)
{
    if(l>ind || r<ind)
        return;
    if(l==r)
    {
        seg[idx]=val;
        seg[idx]%=mod;
        return;
    }
    int m = l+r;
    m/=2;
    update(idx<<1,l,m,ind,val);
    update(idx<<1|1,m+1,r,ind,val);
    seg[idx] = seg[idx<<1] + seg[idx<<1|1];
    seg[idx]%=mod;
}
*/
int solveUtil()
{
    memset(arr,0,sizeof(arr));
    memset(rig,-1,sizeof(rig));
    //memset(seg,0,sizeof(seg));
    memset(dp,0,sizeof(dp));
    for(auto x:on)
    {
        arr[x.fi]++;
        arr[x.sc+1]--;
    }
    for(int i=1;i<=n;i++)
    {
        arr[i]+=arr[i-1];
    }

    for(auto x:zer)
    {
        if(rig[x.sc]==-1)
            rig[x.sc] = x.fi;
        rig[x.sc] = max(rig[x.sc],x.fi);
    }
    //update(1,1,n+1,1,1);
    dp[0] = 1;
    //int u,v,w;
    int cur = 0;
    int sum = 1;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==0)
        {
            dp[i] = sum;
            sum = (sum+dp[i])%mod;
        }
        if(rig[i]!=-1)
        {
            while(cur<rig[i])
            {
                sum = (sum + mod - dp[cur])%mod;
                dp[cur] = 0;
                cur++;
            }
        }
    }
    return sum;
    //return findSum(1,1,n+1,1,n+1);
}

void solve()
{
    cin>>n>>k>>m;
    pair<pii,int> x;
    for(int i=0;i<m;i++)
    {
        cin>>x.fi.fi>>x.fi.sc>>x.sc;
        qu.pb(x);
    }
    int ans = 1;
    for(int i=0;i<k;i++)
    {
        zer.clear();
        on.clear();
        for(int j=0;j<m;j++)
        {
            if(BCHK(qu[j].sc,i))
            {
                on.pb(qu[j].fi);
            }
            else
                zer.pb(qu[j].fi);
        }
        ans = ans * solveUtil();
        ans%=mod;
    }
    cout<<ans<<endl;
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