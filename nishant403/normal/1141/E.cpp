#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push
int main()
{
 fast;   
 ll h,n,i,j,an=0;
    
    cin >> h >> n;
    
   ll a[n];
   ll sum = 0; 
   ll mi = 9999999999;
    
    f(i,n) cin >> a[i];
    
    f(i,n)
    {
    sum+=a[i];
    mi=min(mi,sum);    
    }
    
    
    if( h + mi > 0 && sum >= 0 ) cout << -1;
    else
    {
    if(h + mi <= 0 ) an = 0;
    else 
    {
        an = ceil ( ( h - abs(mi) )/(long double) abs(sum) ) ;
        
        h = h + an*sum;
        
        an=an*n;
    }
      f(i,n) 
      {
       if(h<=0) break;
          
        h = h + a[i];
        an++;
      }
        
        cout << an;
        
    
        
        
    }
    
    return 0;
}