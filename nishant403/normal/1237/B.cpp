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
    
    int ans = 0;
    
    f(i,n) cin >> a[i].F;
    f(i,n) cin >> a[i].S;
    
    int l = 0;
    int r = 0;
    
    set<int> ss;
    
    while(r < n)
    {
      if(ss.find(a[l].F) != ss.end()) 
      {
        l++; continue;   
      }
        
      ss.insert(a[r].S);  
        
      if(a[r].S != a[l].F) 
      {
          ans++;    
          r++;
      }
      else l++,r++;      
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