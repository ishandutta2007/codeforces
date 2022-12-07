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

vector<ll> graph[100005];
map<ll,ll> vals[100005];
ll strength[100005];
bool visited[100005];
ll n;
ll ans;

void findVal(ll ver, ll depth)
{
    if(visited[ver])
        return;
    visited[ver] = true;
    
    //cout<<ver<<"???"<<endl;
    vals[depth].clear();
    vals[depth][strength[ver]]+=1ll;
    ans+= strength[ver];
    ans%=mod;
    ll x;
    for(auto i = vals[depth-1].begin(); i != vals[depth-1].end(); i++)
    {
        //cout<<i<<endl;
        x = __gcd(i->first,strength[ver]);
        //cout<<x<<" ";
        vals[depth][x]+=i->second;
        ans+=(x*i->second)%mod;
        ans%=mod;
    }
    //cout<<endl;
    for(ll i=0;i<graph[ver].size();i++)
    {
        x = graph[ver][i];
        if(!visited[x])
            findVal(x,depth+1);
    }
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
 
    IOS; 
    
    cin>>n;
    ans = 0;
    
    for(ll i=1;i<=n;i++)
        cin>>strength[i];
    ll u,v;
    for(ll i=1;i<n;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    memset(visited,false,sizeof(visited));
    findVal(1,1);
    cout<<ans<<endl;
}