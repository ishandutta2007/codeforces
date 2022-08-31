#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define f(i,n) for(int i=0;i<n;i++)

signed main()
{
  int t;
    cin >> t;
    
    while(t--)
    {
    
    
 int n,k;
    cin >> n >> k;
    
    
    int a[n];
    f(i,n) cin >> a[i];
    
    int ans = 1e10;
    
    int xx = 0;
    
    f(i,n-k)
    {
       int x = (a[i] + a[i+k])/2;
        
       if(max(abs(a[i]-x),abs(a[i+k]-x) ) < ans )
       {
         ans = max(abs(a[i]-x),abs(a[i+k]-x) );
          xx = x; 
       }
        
    }
     
    cout << xx << "\n";
    
    }
}