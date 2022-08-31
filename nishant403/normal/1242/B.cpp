#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e5+10;
vi g[N];

void solve()
{
  int n,m,a,b;
  cin >> n >> m;
    
  f(i,m)
  {
      cin >> a >> b;
      g[a].pb(b);
      g[b].pb(a);
  }
    
  vi cnt(n+1,0);
    
  int ans = 0;  
    
  vector<int> nodes;
  nodes.pb(1);
    
  set<pii> mi;
  unordered_map<int,int> help;
     
  for(auto x : g[1])  
  {
      mi.insert({1,x});
      help[x] = 1;
  }
    
  for(int i=2;i<=n;i++)
      if(help.find(i) == help.end()) help[i] = 0,mi.insert({0,i});
    
  while(nodes.size() < n)
  {
         if((*mi.begin()).F == (int)nodes.size()) ans++;
      
         nodes.pb((*mi.begin()).S);
         mi.erase(mi.begin());
         help.erase(nodes.back());
          
         for(auto x : g[nodes.back()])
         {
           if(help.find(x) == help.end()) continue; 
           help[x]++;
           mi.erase({help[x]-1,x});
           mi.insert({help[x],x});  
         }
      
  }
    
  cout << ans; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}