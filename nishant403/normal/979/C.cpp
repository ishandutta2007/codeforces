#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
const int N =3e5 + 10;
vector<int> graph[N];
vector<bool> vis(N,0);
vector<bool> vis2(N,0);
vector<int> par(N,-1);

void dfs(int node)
{
vis[node]=1;    

    for(auto x : graph[node] )
    {
        if(!vis[x] ) { dfs(x);  par[x]=node; }   
    }
}

int bfs(int node)
{
    queue<int> q;
    q.push(node);
    
    int ans = 0;
    
    while(!q.empty())
    {
     int x = q.front();
             q.pop();
        
      if(vis2[x]) continue;
        
        vis2[x]=1;
        ans++;
        
     for(auto z  :graph[x] ) 
            if(!vis2[z]) q.push(z);
    }
    
    return  ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    int n,x,y,i,a,b;
    
    cin >> n >> x >> y;
    
    for(i=0;i<n-1;i++)
    {
      cin >> a >> b;  
        graph[a].pb(b);
        graph[b].pb(a);
    }
    
    dfs(x);
    
    int path = y;
    
    while(par[path] != x)
    {
    path = par[path];    
    vis2[path] = 1;    
    }
    
    vis2[x]=0;
    vis2[y]=1;
    
    int x1 = bfs(x);
    
    vis2[y]=0;
    
    int y1 = bfs(y);
 
   
    cout << (n*(n-1)) -(x1*y1);
}