#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back

void solve()
{
  int n;
  cin >> n ;
    
  vector<int> dd;
  
  for(int i=2;i*i<=n;i++)
  {
    if(n%i==0)
    {
       dd.pb(i);
       if(i*i!=n) dd.pb(n/i);
    }
  }
    
  int ans = n;
    
  for(auto x : dd) ans = __gcd(ans,x);  
   
    cout << ans;
}

signed main()
{
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}