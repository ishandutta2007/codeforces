#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
vector<int> graph[100001];
vector<bool> vis(100001,0);
map<pair<int,int>,int> ed;



int dfs(int x)
{
vis[x]=1;
    
int ans = 1;
    
 for(auto z : graph[x])
 {
     if(!vis[z]) { ed[{x,z}]=dfs(z); ans+=ed[{x,z}]; }   
 }
    
 return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,a,b;
    cin >> n;
   
    for(int i=0;i<n-1;i++)
    {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    
    dfs(1);
    
    int ans = 0;
    
   for(auto dp : ed) if(dp.second%2==0) ans++;
    
    
       
   if(n%2==1) ans=-1;
   cout << ans;
}