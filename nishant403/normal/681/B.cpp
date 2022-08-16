#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first
#define S second
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
 fast;   
 int i,j,n,k;
    
  cin >> n;
    
   int a=1234567,b=123456,c=1234;
    
    for(i=0;i*a<=n;i++)
    {
      for(j=0;j*b+(i*a)<=n;j++)  
    
          if( (n-(j*b)-(i*a)) % c == 0) { cout << "YES"; return 0; }
    }
    
    cout << "NO";
}