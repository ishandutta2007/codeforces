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

const int N = 1e6+10;
vi g[N],black(N,0);
vector<bool> vis(N,0);
vi par(N,0);

void dfs(int node,int p)
{
  par[node] = p;
  vis[node] = 1;
    
  for(auto x : g[node])
     if(!vis[x] && !black[x]) dfs(x,node);
}

void solve()
{
  int n,m;
  string s;
  cin >>n >>m;
 
  bool grid[n][m];
  
  f(i,n)
  {
    cin >> s; 
      f(j,m) grid[i][j] = (s[j]=='.');
  }
    
  f(i,n)
      f(j,m)
         if(grid[i][j])
  { 
     if(j<m-1 && grid[i][j+1]) g[(i*m)+j].pb((i*m)+j+1);
     if(i<n-1 && grid[i+1][j]) g[(i*m)+j].pb((i*m)+j+m); 
  }
    
  dfs(0,-1);  
   
  if(vis[(n*m)-1]==0) { cout << 0; return; } 
    
  int t = par[(n*m)-1];
      
  while(t!=0)
  {   
   black[t] = 1;   
   t=par[t];   
  }
    
  f(i,(n*m)) vis[i]=0;  
  
  dfs(0,-1);
    
  if(vis[(n*m)-1]==0) { cout << 1; return; }   
    
  cout << 2;
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}