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

//#define int ll
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

const int maxn = 1e5 + 7;

const ll inf = 1e9 + 7;

int n,m;
set<int> tre[maxn];
//vector<int> centroidTre[maxn];
//int centroidRoot;
int centroidPar[maxn];
int siz[maxn];
map<pii,int> dist;
int treesiz;

void storeDistances(int root,int ver, int par, int distance)
{
    dist[{ver,root}] = distance;
    dist[{root,ver}] = distance;
    dbg(cout<<root<<" "<<ver<<" "<<distance<<endl;);
    for(auto x: tre[ver])
    {
        if(x==par)
            continue;
        storeDistances(root,x,ver,distance+1);
    }
}

void dfs1(int ver,int par)
{
    siz[ver] = 1;
    treesiz++;
    for(auto x:tre[ver])
    {
        if(x==par)
            continue;
        dfs1(x,ver);
        siz[ver]+=siz[x];
    }
}

int dfs2(int ver,int par)
{
    for(auto x:tre[ver])
    {
        if(x!=par && siz[x]*2>treesiz)
            return dfs2(x,ver);
    }
    return ver;
}

void centroidDecomposition(int root, int par)
{
    treesiz = 0;
    dfs1(root,-1);
    int centroid = dfs2(root,-1);
    dbg(cout<<centroid<<" "<<par<<endl;);
    storeDistances(centroid,centroid,par,0);
    centroidPar[centroid] = par;
    /*if(par!=-1)
        centroidTre[par].pb(centroid);
    else
        centroidRoot = centroid;*/
    for(auto x: tre[centroid])
    {
        tre[x].erase(centroid);
        centroidDecomposition(x,centroid);
    }
    tre[centroid].clear();
}

int ans[maxn];

void makeRed(int ver)
{
    int distance = 0;
    int par = ver;
    while(par!=-1)
    {
        distance = dist[{par,ver}];
        ans[par] = min(distance,ans[par]);
        par = centroidPar[par];
    }
}

int nearestRed(int ver)
{
    int nearest = ans[ver];

    int distance;
    int par = ver;
    while(par!=-1)
    {
        distance = dist[{par,ver}] + ans[par];
        nearest = min(distance,nearest);
        par = centroidPar[par];
    }
    return nearest;
}

void solve()
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        tre[u].insert(v);
        tre[v].insert(u);
        ans[i] = inf;
    }
    ans[n] = inf;
    centroidDecomposition(1,-1);
    dbg(for(int i=1;i<=10;i++)
        cout<<centroidPar[i]<<" "<<endl;);
    makeRed(1);

    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        if(u==1)
        {
            makeRed(v);
        } else{
            cout<<nearestRed(v)<<endl;
        }
    }

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