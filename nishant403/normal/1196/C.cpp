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
    
  int val[6];
  
  
  int l1 = -1e5;
  int r1 = -1e5;
  int l2 = 1e5;
  int r2 = 1e5;
      
  f(i,n) 
  {
      f(j,6) cin >> val[j];
      
      if(val[2] == 0) l1 = max(l1,val[0]);
      if(val[3] == 0) r2 = min(r2,val[1]); 
      if(val[4] == 0) l2 = min(l2,val[0]);
      if(val[5] == 0) r1 = max(r1,val[1]);
    
  }   
    
  if(l2>=l1 && r2>=r1)
  {
    cout << 1 << " " << l1 << " " << r1 << "\n";    
  }
  else cout << "0\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}