 
//AUTHOR : TIRTH JARSANIA
//COLLEGE : DAIICT

#pragma optimize("", off)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:36777216")
#include<bits/stdc++.h>
using namespace std;

#define MINF LONG_LONG_MIN
#define pi acos(-1)
#define bp __builtin_popcount
#define ll long long int
#define ld long double
#define pii pair<ll , ll>
#define For(i,a,b) for(ll i=a;i<b;i++)
#define Fori(i,a,b,p) for(ll i=a;i<b;i+=p)
#define Ror(i,a,b) for(ll i=a;i>b;i--)
#define Rori(i,a,b,p) for(ll i=a;i>b;i-=p)

#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<pii,vector<pii>,greater<pii> > 
#define maxQueue priority_queue<pii> 

#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define FILL(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL))

const ll N = 4e3+5;
ll INF = 999999999999;
map<pair<ll,ll>,ll> g;

int main()
{
    FAST;
    ll n , m ;
    cin >> n >> m;
    
    vector<pair<ll,ll> > edg;
    vector<ll> deg(n+1,0);
    
    
    while(m--)
    {
        ll u ,v;
        cin >> u >> v;
        g[{u,v}]=1;
        g[{v,u}]=1;
        deg[u]++;
        deg[v]++;
        edg.push_back({u,v}); 
    }
    
    ll ans = INF;
    
    for(auto x : edg)
    {
    for(int i=1;i<=n;i++)    
    {
        if(g.find({i,x.first})!=g.end() && g.find({i,x.second})!=g.end())
          ans=min(ans,deg[x.first]+deg[x.second]+deg[i]);
    }   
    }
    
    if(ans == INF)  cout << "-1" ;
    else cout << ans-6;
}