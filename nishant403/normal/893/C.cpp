#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 1e5+5;
vector<int> g[N];
vector<int> gold(N,0);

vector<bool>vis(N,0);
#define pb push_back

int dfs(int n)
{
vis[n]=1;

int p=gold[n];   
    
for(auto x : g[n])
{
if(vis[x]==0)  p=min(p,dfs(x));     
}
    
 return p;   
}

signed main()
{
    int n,m,i,j;
    cin >> n >> m;
    
    int a,b;
    
    for(i=0;i<n;i++) cin >> gold[i+1];
    
    for(i=0;i<m;i++)
    {
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);    
    }
    
    int ans = 0;
    
    for(i=1;i<=n;i++)
    {
      if(!vis[i]) ans+=dfs(i);  
    }
    cout << ans;
}