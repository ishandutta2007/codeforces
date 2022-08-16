#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
    fast;
    int n;
    cin >> n;
    
   int a[n+1];
    
    for(int i=0;i<=n;i++) a[i] = 0;
    
    int c = 1;
    
    for(int i=2;i<=n;i++)
    {
        int flag = 0;
        
      for(int j=i;j<=n;j+=i)
      {
          if(a[j]==0) { a[j] = c; flag=1; }
      }
          
       if(flag==1) c++;   
    }
    
    
    for(int i=2;i<=n;i++)
        cout << a[i] << " ";
}