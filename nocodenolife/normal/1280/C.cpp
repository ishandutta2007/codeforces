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

#define F first
#define S second 
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

const ll inf = 1e16 + 7;
 
int n,k;
vector<pii> tre[maxn];
int dp[maxn];
int siz[maxn];
 
void preorder(int ver, int par)
{
    dp[ver] = 0;
    siz[ver] = 1;
    if(tre[ver].size()==1)
    {
        return;
    }
 
    int u,w;
    for(auto i:tre[ver])
    {
        u = i.F;
        w = i.S;
        if(u==par)
            continue;
        preorder(u,ver);
        dp[ver]+=dp[u];
        siz[ver]+=siz[u];
        if(siz[u]%2==1)
        {
            dp[ver]+=w;
        }
    }
}

void findMax(int ver, int par)
{
    dp[ver] = 0;
    if(tre[ver].size()==1)
    {
        return;
    }
 
    int u,w;
    for(auto i:tre[ver])
    {
        u = i.F;
        w = i.S;
        if(u==par)
            continue;
        findMax(u,ver);
        dp[ver]+=dp[u];
        dp[ver]+=w*(min(siz[u],n-siz[u]));
    }
}


void solve()
{
    cin>>k;
    n = k+k;
    for(int i=1;i<=n;i++)
        tre[i].clear();
    int u,v,w;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        tre[u].pb({v,w});
        tre[v].pb({u,w});
    }
    
    if(n==2)
    {
        cout<<tre[1][0].S<<" "<<tre[1][0].S<<endl;
        return;
    }
 
    for(int i=1;i<=n;i++)
    {
        if(tre[i].size()>1)
        {
            preorder(i,-1);
            dbg(cout<<i<<endl;);
            cout<<dp[i]<<" ";
            findMax(i,-1);
            cout<<dp[i]<<endl;
            return;
        }
    }
    exit(1); 
    //cout<<"fuck"<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    int t;
    cin>>t;

    while(t--)
        solve();
}