#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e5 + 10;
vi g[N];

void solve()
{
   int n,x,y;
    cin >> n >> x >> y;
    
   int xx = x;
   int yy = y;
    
   for(int i=1;i<=n+1;i++) g[i].clear();  
    
   int a[n];
    f(i,n) cin >> a[i];
    f(i,n) g[a[i]].pb(i);
    
    int elm = -1;
    
    for(int i=1;i<=n+1;i++) 
        if(g[i].empty()) elm = i;
    
   priority_queue<pii> pq;
    f(i,n+2) if(g[i].size() > 0) pq.push({g[i].size(),i});
    
   vi res(n,-1);
    
   int tot = n; 
    
   while(x > 0)
   {
       auto v = pq.top(); pq.pop();
       
       int id = g[v.S].back(); g[v.S].pop_back();
       res[id] = a[id];
       
       if(v.F > 1) pq.push({v.F-1,v.S});
       x--;
       y--;
       tot--;
   }
     
   if(pq.size() > 0)
   {
       int sz = pq.top().F;
       int cap = 2*(tot - sz);
       
       if(y > cap)
       {
           cout << "NO\n";
           return;
       }
       
       vector<pii> ids;
       
       while(!pq.empty())
       {
          auto v = pq.top(); pq.pop();
           
          f(i,v.F) 
          {
              ids.pb({g[v.S].back(),v.S});
              g[v.S].pop_back();
          }
       }
       
       if(sz + sz <= tot)
       {
       f(i,y)
          res[ids[i].F] = ids[(i + sz)%tot].S; 
       }
       else
       {
         int id = sz - (tot - sz);
           
         f(i,y) res[ids[(i+id)%tot].F] = ids[(i + sz)%tot].S;
           
       }
   }
    
   f(i,n) if(res[i] == -1) res[i] = elm; 
       
   cout <<"YES\n";
    
   f(i,n) cout << res[i] << ' ';
    
   cout << '\n';    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}