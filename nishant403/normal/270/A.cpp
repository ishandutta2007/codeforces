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
 int t;
    cin >>t;
    
    while(t--)
    {
     int a;
        cin >> a;
        //angle of n-regular polygon is (n-2)/n * 180
        //(n-2)*180 = n*a
        //180n - 360 = na
        //n(180-a) = 360
        //n = 360/(180 - a)
        
        
        if(360 % (180-a) == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}