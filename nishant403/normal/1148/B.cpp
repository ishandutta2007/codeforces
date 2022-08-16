#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define f(i,n) for(int i=0;i<n;i++)

signed main()
{
 int n,m,ta,tb,k;
    
  cin >> n >> m >> ta >> tb >> k;
    
  vector<int> a(n),b(m);  
    
  f(i,n) cin >> a[i];  
  f(i,m) cin >> b[i];
    
  int ans = 0;
    
    if(k>=m || k>=n) { cout << -1; return 0; }
    
    f(i,k+1)
    {
     auto reach = lower_bound(b.begin(),b.end(),a[i]+ta); 
        
     if(reach==b.end()) { cout << -1; return 0; }
        
     int index = distance(b.begin(),reach);   
        
     int left = m-index;
        
     if(left <= (k-i) )   {cout << -1; return 0; }
        
     ans = max(ans,b[index+k-i]+tb);
        
    }
    
    cout << ans;
}