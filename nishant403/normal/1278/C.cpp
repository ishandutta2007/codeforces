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

void solve()
{
  int n;
  cin >> n;
    
  int a[2*n];
  f(i,2*n) cin >> a[i];
    
  map<int,int> mp;
    
  int diff = 0;
    
  mp[0] = n;  
    
  f(i,n)
  {
      if(a[i] == 1) diff++;
      else diff--;
      
      mp[diff] = n-i-1;
  }
    
  diff = 0;
    
  int ans = 2*n;  
    
  ans = min(ans, n + mp[0]);  
    
  for(int i=(2*n)-1;i>=n;i--)
  {
      if(a[i] == 1) diff--;
      else diff++;
      
      if(mp.find(diff) != mp.end())
      {
         ans=min(ans,mp[diff] + i-n);   
      }   
  }
    
  cout << ans << "\n";  
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}