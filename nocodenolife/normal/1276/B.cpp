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

const int maxn = 2e5 + 7;

const ll inf = 1e9 + 7;

int parent[maxn];
int siz[maxn];
int iscona[maxn];
int isconb[maxn];

int find_dsu(int x)
{
    if(parent[x]==-1)
        return x;
    parent[x] = find_dsu(parent[x]);
    return parent[x];
}

void union_dsu(int x, int y)
{
    x = find_dsu(x);
    y = find_dsu(y);
    if(x==y)
        return;
    if(siz[x]<siz[y])
    {
        siz[y]+=siz[x];
        parent[x] = y;
    }
    else
    {
        parent[y]=x;
        siz[x] += siz[y];
    }
}

map<pii,int> mp;
vector<int> edga;
vector<int> edgb;
 
void solve()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;

    for(int i=1;i<=n;i++)
    {
        siz[i] = 1;
        parent[i] = -1;
        iscona[i] = 0;
        isconb[i] = 0;
    }
    siz[a] = 0;
    siz[b] = 0;
   
    edga.clear();
    edgb.clear();
    mp.clear();
    int u,v,t,y;
    for(int i=0;i<m;i++)
    {
        cin>>t>>y;
        u = min(t,y);
        v = max(t,y);

        if(mp[{u,v}]==1)
            continue;
        mp[{u,v}] = 1;
        if(u==a || v==a)
        {
            edga.pb(u+v-a);
            continue;
        }
        if(u==b||v==b)
        {
            edgb.pb(u+v-b);
            continue;
        }
        union_dsu(u,v);    
    }

    for(auto ver : edga)
    {
        if(ver==b)
            continue;
        u = find_dsu(ver);
        iscona[u]=1;
    }
    for(auto ver : edgb)
    {
        if(ver==a)
            continue;
        u = find_dsu(ver);
        isconb[u]=1;
    }
    
    int siza = 0;
    int sizb = 0;

    for(int i=1;i<=n;i++)
    {
        if(parent[i]!=-1)
            continue;
        if(i==a || i==b)
            continue;
        if(iscona[i]>0 && isconb[i]>0)
            continue;
        if(iscona[i]>0)
            siza+=siz[i];
        if(isconb[i]>0)
            sizb+=siz[i];
    }

    int ans = 0;
    ans = siza*sizb;

    cout<<ans<<endl;
    return;
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