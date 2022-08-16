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
    
  pii a[n];
  f(i,n) cin >> a[i].F >> a[i].S;
   
  sort(a,a+n);
    
  int flag = 0;
    
  f(i,n-1) if(a[i+1].S < a[i].S) flag = 1;
      
  if(flag)
  {
      cout <<"NO\n";
      return;
  }
    
  cout <<"YES\n";  
    
  pii cur = {0,0};  
    
  f(i,n)
  {
      while(cur.F < a[i].F)
      {
          cur.F++;
          cout<<"R";
      }
      
      while(cur.S < a[i].S)
      {
          cur.S++;
          cout<<"U";
      }
  }
    
    cout << '\n';
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}