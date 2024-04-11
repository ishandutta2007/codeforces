#define DEBUG
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
#define F first
#define S second 
#define pb push_back
 
#define endl "\n"
 
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
 
#ifdef DEBUG
    #define dbg(s) {s;}
#endif
 
#ifndef DEBUG
    #define dbg(s)
#endif
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { // from [0, x-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}
 
#define i32 int32_t
 
#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 
 
#define all(v) (v).begin(),(v).end()
 
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

ll indeg[100005];
ll outdeg[100005];
vector<ll> inedg[100005];
ll n,ans;

void update(ll ver)
{
    ans -= indeg[ver]*outdeg[ver];
    outdeg[ver]+=indeg[ver];
    indeg[ver] = 0;
    
    ll x;
    for(ll i=0;i<inedg[ver].size();i++)
    {
        x = inedg[ver][i];
        inedg[x].pb(ver);
        ans-= indeg[x]*outdeg[x];
        indeg[x]++;
        outdeg[x]--;
        ans+= indeg[x]*outdeg[x];
    }
    inedg[ver].clear();
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
 
    IOS; 
    cin>>n;
    ll m;
    cin>>m;
    ans = 0;
    
    memset(indeg,0,sizeof(indeg));
    memset(outdeg,0,sizeof(outdeg));
    
    ll u,v,x,y;
    for(ll i=0;i<m;i++)
    {
        cin>>u>>v;
        x = min(u,v);
        y = max(u,v);
        inedg[x].pb(y);
        indeg[x]++;
        outdeg[y]++;
    }
    for(ll i=1;i<=n;i++)
        ans+=indeg[i]*outdeg[i];
    
    cout<<ans<<endl;
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++)
    {
        cin>>x;
        update(x);
        cout<<ans<<endl;
    }
    
}