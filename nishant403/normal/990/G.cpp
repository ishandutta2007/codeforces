#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<long long>
#define pii pair<int,int>

const int N = 2e5+10;
vi graph[N];
int a[N],n,u,v;

map<int,int> mp[N];
vi mpp(N,0);

void dfs(int node,int p=-1)
{    
   mp[node][a[node]]++; 
   mpp[a[node]]++;
    
for(auto x : graph[node])
{    
    if(x==p) continue; 
    
    dfs(x,node);
    
    for(auto z : mp[x])
    {
        for(auto y : mp[node])
             mpp[__gcd(y.F,z.F)]+=((long long)y.S*z.S);
        
    }        
       
    for(auto z : mp[x])
        mp[node][__gcd(z.F,a[node])]+=z.S;
 
    
    mp[x].clear();
}    
    
}


void solve()
{
  cin >> n;
    
  f(i,n) cin >> a[i+1];
    
    f(i,n-1) { cin >> u >> v; graph[u].pb(v); graph[v].pb(u); } 
  
  dfs(1);          
 
  for(int i=1;i<=2e5;i++)
  {
    if(mpp[i]==0) continue;
    cout << i <<" "<<mpp[i] << "\n";
  }
            
}

signed main()
{
    fast;
    solve();
}