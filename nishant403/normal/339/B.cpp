#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
fast; 
    int n,m;
    string a;
    
    cin >> n >> m;
    int last = 1;
    int ans = 0;
    int x;
    for(int i=0;i<m;i++)
    {
     cin >> x;
      if(x >= last ) ans+=(x-last);  
      else ans+=(x-last+n);
        
        last = x;
    }
    cout << ans;
}