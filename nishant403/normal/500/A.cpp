#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


signed main()
{
    fast;
    int n,t,i;
    cin >> n >> t;
    
    int a[n];
    
    for(i=0;i<n-1;i++) cin >> a[i+1];
    
    int x=1;
    while(x<t)
    {
      x+=a[x];  
    }
    if(x==t) cout << "YES";
    else cout << "NO";
}