#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
fast; 
    int n;
    string a;
    
    cin >> n;
    while(n--)
    {
     cin >> a;
        if(a.length() > 10)
        {
         cout << a[0] ;
            cout << a.length()-2;
            cout << a[a.length()-1] << "\n";
        }
        else cout << a << "\n";
        
    }
}