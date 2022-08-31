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
    
  int x,y;
  int mx=0,my=1e10;
    
  f(i,n)
  {
      cin >> x >> y;
      mx = max(mx,x);
      my = min(my,y);
  }
      
    
  cout << max((int)0,mx-my) << '\n';
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}