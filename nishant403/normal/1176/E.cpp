#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second

signed main()
{
 ios_base::sync_with_stdio(0);   
 cin.tie(0);
    cout.tie(0);
    
int t;
cin >> t;
    
while(t--)
{
 int n,m,a,b;   
 cin >> n >> m;   
    
 vector<int> graph[n+1];
    
 f(i,m)    
 {
  cin >> a >> b;
  graph[a].pb(b);
  graph[b].pb(a);
 }
    
  vector<int> ans1,ans2;  
    
  queue<pair<int,int> > q;
    q.push({1,1});
    
  vector<bool> vis(n+1,0);
    
   while(!q.empty())
   {
    auto x = q.front();
    q.pop();
       
       if(vis[x.F]) continue;
       vis[x.F] = 1;
       
       if(x.S) ans1.pb(x.F);
       else ans2.pb(x.F);
       
       for(auto z : graph[x.F])
           if(!vis[z]) q.push({z,x.S^1});
   }
   
    if(ans1.size() < ans2.size() )
    {
     cout << ans1.size() << "\n";   
        
        for(auto x : ans1) cout << x << " " ;
        cout  << "\n";
    }
    else 
    {
     cout << ans2.size() << "\n";   
        
        for(auto x : ans2) cout << x << " " ;
        cout  << "\n";
    }
    
   
}
    
}