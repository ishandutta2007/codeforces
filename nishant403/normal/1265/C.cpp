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
#define bye { cout<<"0 0 0\n"; return; }

void solve()
{
  int n;
  cin >> n;
    
  vi val;  
    
  int last, occ = 1,x;  
    
  cin >> last; 
    
  f(i,n-1)
  {
      cin >> x;
      
      if(x != last)
      {
          val.pb(occ);
          occ = 0; 
      }
      
      occ++;
      last = x;
  }
    
  val.pb(occ);
    
  if(val.size() < 3) bye
           
  pii g[3];
  int sum = 0;
      
  f(i,2) g[i].F = i,g[i].S = val[i],sum+=val[i];   
    
  while(g[1].F+1 < val.size() && g[0].S >= g[1].S)
  {
      g[1].F++;  
      g[1].S+=val[g[1].F];
      sum+=val[g[1].F];
  }
    
  if(g[0].S >= g[1].S || sum > (n/2) ) bye
      
  g[2].F = g[1].F + 1;    
  g[2].S = val[g[2].F];
  sum += val[g[2].F];
    
  while(g[2].F + 1 < val.size() && sum+val[g[2].F+1] <=(n/2))
  {
      g[2].F++;
      g[2].S+=val[g[2].F]; 
      sum+=val[g[2].F]; 
  }
    
  if(g[0].S < g[1].S && g[0].S < g[2].S && sum<=(n/2)) f(i,3) cout << g[i].S <<" ";
  else f(i,3) cout <<"0 ";
    
  cout<<'\n';  
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}