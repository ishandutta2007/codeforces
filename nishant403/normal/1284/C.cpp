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
  int n,m;
  cin >> n >> m;
    
  int fact[n+1];
  fact[0] = 1;
    
  for(int i=1;i<=n;i++) fact[i] = (fact[i-1]*i)%m;
    
  int ans = 0;
    
  for(int i=1;i<=n;i++)
  {
      int temp = (n-i+1);
      temp*=(n-i+1);
      temp%=m;
      
      temp*=fact[i];
      temp%=m;
      
      temp*=fact[n-i];
      temp%=m;
      
      ans=(ans+temp)%m;
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