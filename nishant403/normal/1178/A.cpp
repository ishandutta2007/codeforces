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
    
  int sum = a[0];
  int tot = 0;
    
  f(i,n) tot+=a[i];
    
  vi ans;  
  
  ans.pb(1);  
    
  for(int i=1;i<n;i++)
      if(a[i]*2 <= a[0] ) { sum+=a[i]; ans.pb(i+1); }
     
 
    if(sum > tot/2 )
    {
     cout << (ans.size()) << "\n";
      for(auto x : ans) cout << x << " ";
        
    }
    else cout << 0;  
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}