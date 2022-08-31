#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
 int n;
 cin >> n;
    
 int ans  = ( 3*n - 1 );
    
 for(int i=0;i<n-3;i++) ans=(ans*4);
    cout << ans*3;
}