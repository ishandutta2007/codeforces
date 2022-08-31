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

const int N = 2e5+10;
int a[N];
int dp[N];
int vis[N];
int n;

void solve()
{
  cin >> n;
 
  f(i,n) dp[i] = (int)1e7;  
    
  f(i,n) cin >> a[i];
    
  queue<pii> Q;
    
  vector<int> reachable[n];  
    
  f(i,n)
  {
    if(i-a[i] >= 0)
    {
         int num = a[i]^a[i-a[i]]; 
         if(num%2==0) 
        reachable[i-a[i]].pb(i);
    }
    if(i+a[i] < n)
    {
         int num = a[i]^a[i+a[i]]; 
         if(num%2==0) 
        reachable[i+a[i]].pb(i);
    }
  }
    
  f(i,n)
  {
      if(i-a[i] >= 0) 
      {
         int num = a[i]^a[i-a[i]]; 
         if(num%2==1) 
          Q.push({1,i});
      }
      
      if(i+a[i] < n)
      {
          int num = a[i]^a[i+a[i]];
          if(num%2==1)
          Q.push({1,i});
      }
  }
    
  while(!Q.empty())  
  {
     auto x = Q.front(); Q.pop();
       
     if(vis[x.S]) continue;
      
      vis[x.S] = 1;
      dp[x.S] = x.F;
     
      for(auto z : reachable[x.S]) Q.push({x.F+1,z});    
  }
    
f(i,n) if(dp[i] >= 1e7) cout << -1 <<" ";
       else cout << dp[i] <<" ";
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}