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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int inf = 1e14;

void solve()
{
   int n,m;
    cin >> n >> m;
    
   int sx,sy,fx,fy;
    cin >> sx >> sy >> fx >> fy;
    
    pii a[m];
    f(i,m) cin >> a[i].F >> a[i].S;
    
    set<pii> gox,goy;
    f(i,m) gox.insert({a[i].F,i});
    f(i,m) goy.insert({a[i].S,i});
    
    vi dis(m,inf);
    
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    
    f(i,m) pq.push({min(abs(sx - a[i].F),abs(sy - a[i].S)),i});
    
    while(!pq.empty())
    {
        auto x = pq.top(); pq.pop();
        
        if(dis[x.S] <= x.F) continue;
        dis[x.S] = x.F;
        
        gox.erase({a[x.S].F,x.S});
        goy.erase({a[x.S].S,x.S});
       
        if(gox.size() > 0)
        {
           auto it = gox.lower_bound({a[x.S].F,-1}); 
            
           if(it != gox.end())
           {
              pii elm = (*it);
               
              if(dis[elm.S] > dis[x.S] + abs(elm.F - a[x.S].F))
              {
                  pq.push({dis[x.S] + abs(elm.F - a[x.S].F),elm.S});
              }
           }
            
           if(it != gox.begin())
           {
               --it;
               pii elm = (*it);
               
               if(dis[elm.S] > dis[x.S] + abs(a[x.S].F - elm.F))
               {
                   pq.push({dis[x.S] +abs(-elm.F + a[x.S].F),elm.S});
               }
           }
        }
        
        if(goy.size() > 0)
        {
           auto it = goy.lower_bound({a[x.S].S,-1});
            
           if(it != goy.end())
           {
              pii elm = (*it);
               
             if(dis[elm.S] > dis[x.S] + abs(-a[x.S].S + elm.F))
             { 
                    pq.push({dis[x.S] + abs(elm.F - a[x.S].S),elm.S});
             }
           }
            
           if(it != goy.begin())
           {
              --it;
              pii elm = (*it);
                 if(dis[elm.S] > dis[x.S] + abs(a[x.S].S - elm.F))
                 {
                    pq.push({dis[x.S] + abs(-elm.F + a[x.S].S),elm.S});
                 }
           
           }
        }
    }
 
    int res = abs(sx - fx) + abs(sy - fy);
 
    f(i,m) res = min(res,abs(fx - a[i].F) + abs(fy - a[i].S) + dis[i]);
    
    cout << res;  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}