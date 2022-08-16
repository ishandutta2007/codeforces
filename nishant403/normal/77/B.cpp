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
  int a,b;
  cin >> a >> b;
    
  if(b==0)
  {
      cout << 1.00000 << '\n';
      return;
  }
    
  if(a==0)
  {
      cout << 0.5000000 << '\n';
      return;
  }
    
  double res = 0.50000;
    
  b*=4;
  
  res+=(0.50000*((double)min(b,a))/b)*(a - ((double)min(b,a)/2) )/a;  
      
  cout << fixed << setprecision(6) << res << '\n';  
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}