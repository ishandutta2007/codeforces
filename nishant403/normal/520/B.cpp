#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
vector<int> graph[20001];
vector<int> dis(20001,9999999);
vector<bool> vis(20001,0);

void bfs(int n)
{
dis[n]=0;
vis[n]=1; 
    
queue<int> q;
    q.push(n);
    
    while(!q.empty())
    {
     int x = q.front();
        q.pop();
        
        
        for(auto z : graph[x])
        {
        
         if(!vis[z])
         {
          dis[z]=min(dis[z],dis[x]+1);   
          q.push(z);
             vis[z]=1;
         }
         
            
        }
    
    }
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i;
    
    for(i=1;i<=10000;i++)
    {
     graph[i].pb(i-1);
     graph[i].pb(2*i);
    }
    
    int n,m;
    cin >> n>> m;
   
    bfs(n);
    cout << dis[m];
}