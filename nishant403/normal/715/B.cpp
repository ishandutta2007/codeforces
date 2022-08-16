#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 1e3 + 10;
const int inf = 1e18;

vector<pii> g[N];
vector<pair<int,pii> > ed1,ed2;

int n,m,L,s,t;

int dijk()
{
    vector<int> dis(n,inf);
    
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,s});
    
    while(!pq.empty())
    {
        auto z = pq.top(); pq.pop();
        
        if(z.F >= dis[z.S]) continue;
        
        dis[z.S] = z.F;
        
        for(auto x : g[z.S])
        {
            if(dis[x.S] > z.F + x.F)
            {
                pq.push({z.F + x.F,x.S});
            }
        }
    }
    
    return dis[t];
}

int check()
{
    for(int i=0;i<n;i++) g[i].clear();
   
    for(auto x : ed1) 
    {
        g[x.S.F].pb({x.F,x.S.S});
        g[x.S.S].pb({x.F,x.S.F});
    }
    
    for(auto x : ed2) 
    {
        g[x.S.F].pb({x.F,x.S.S});
        g[x.S.S].pb({x.F,x.S.F});
    }
    
    return dijk();
}

void solve()
{
   cin >> n >> m >> L >> s >> t;
    
   int u,v,w;
    
   f(i,m)
   {
       cin >> u >> v >> w;
       
       if(w > 0) ed1.pb({w,{u,v}});
       else ed2.pb({inf,{u,v}});
   }
    
   //Initial check with inf weight
   for(auto & x : ed2) x.F = inf;
   
   int vv = check(); 
    
   if(vv < L)
   {
       cout <<"NO\n";
       return;
   }
   else if(vv == L)
   {
       cout <<"YES\n";
       for(auto x : ed1) cout << x.S.F << ' ' << x.S.S << ' ' << x.F <<'\n';
       for(auto x : ed2) cout << x.S.F << ' ' << x.S.S << ' ' << x.F <<'\n'; 
       return;
   }
    
   //Final check with 1 weight
   for(auto & x : ed2) x.F = 1;
   
   if(check() > L)
   {
       cout <<"NO\n";
       return;
   }
    
   int l = 0;
   int r = ed2.size();
   int res = 0;
    
   //maximum edges to set to 1, so that shortest distance > L
   while(l <= r)
   {
       int mid = (l + r)/2;
       
       f(i,ed2.size())
           if(i < mid) ed2[i].F = 1;
           else ed2[i].F = inf;
           
       if(check() <= L)
       {
           r = mid - 1;
       }
       else
       {
           res = mid;
           l = mid + 1;
       }
   }
    
   f(i,ed2.size())
       if(i <= res) ed2[i].F = 1;
       else ed2[i].F = inf;
       
   int cur_dis = check();
   ed2[res].F = 1 + L - cur_dis;
   
   cout <<"YES\n";
   for(auto x : ed1) cout << x.S.F << ' ' << x.S.S << ' ' << x.F <<'\n';
   for(auto x : ed2) cout << x.S.F << ' ' << x.S.S << ' ' << x.F <<'\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}