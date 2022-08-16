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
    
    int x,y,z;
    
    cin >> x >> y >> z;
    
    if(z==0)
    {
     if(x>y) cout << '+';
     else if(x<y) cout << '-';
     else cout<< '0';
    }
    
    else
    {
        
     if(x > y+z) cout << '+';   
     else if ( y > x+z ) cout << '-';
         else cout << '?';
        
    }
    
    
    
}