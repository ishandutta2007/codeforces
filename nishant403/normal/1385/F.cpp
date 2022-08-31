#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5 + 10;
vi g[N];

void solve()
{
   int n,k;
    cin >> n >> k;
    
   f(i,n) g[i].clear(); 
    
   int u,v; 
    
   f(i,n-1)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   if(n == 2)
   {
       cout << 1 << '\n';
       return;
   }
    
   vi deg(n+1,0);
   vi val(n+1,0);
   vector<bool> leaf(n+1,0); 
   
   f(i,n) deg[i] = g[i].size();
   f(i,n) leaf[i] = (deg[i] == 1); 
   f(i,n) for(auto x : g[i]) val[i]+=leaf[x];
    
   set<pii> go;
    
   vi ff(n+1,1); 
    
   f(i,n)
   {
       if(leaf[i]) continue;
       
       if(val[i] % k == 0 && deg[i] == val[i] + 1) ff[i] = 0;
       go.insert({ff[i],i});
   }
    
   int res = 0; 
    
   while(!go.empty())
   {
       auto x = *go.begin(); go.erase(go.begin());
       res+=val[x.S]/k;
       
       if(x.F == 0)
       {
           for(auto z : g[x.S])
               if(!leaf[z])
           {
               go.erase({ff[z],z});
               
               val[z]++;
               
              if(val[z] % k == 0 && deg[z] == val[z] + 1) ff[z] = 0;
              else ff[z] = 1;
               
               go.insert({ff[z],z});
          }
           
           leaf[x.S] = 1;
       }
   }
    
   cout << res << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}