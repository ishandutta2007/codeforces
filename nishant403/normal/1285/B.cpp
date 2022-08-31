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
    
  int a[n];
  f(i,n) cin >> a[i];
  
  int x = 0;
  f(i,n)
  {
      x+=a[i];
      if(x<=0)
      {
          cout<<"NO\n";
          return;
      }
  }
    
    reverse(a,a+n);
    x = 0;
    
   f(i,n)
  {
      x+=a[i];
      if(x<=0)
      {
          cout<<"NO\n";
          return;
      }
  }
    
  cout<<"YES\n";    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}