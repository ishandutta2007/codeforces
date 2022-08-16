#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
 fast;
 string A="Misha",B="Vasya",C="Tie";
    
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    int l = max( (75*a) ,250*a -(a*c));
    int r = max( (75*b) ,250*b -(b*d));
    
    
    if(l > r) cout <<A;
    else if(l<r) cout << B;
        else cout << C;
                
}