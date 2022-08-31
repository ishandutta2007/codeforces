#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
fast; 
    int x=0;
    int n;
    int s=0;
    cin >> n;
     
    while(n--)
    {
     int a,b;
        cin >> a >> b;
        
      s-=a;
        s+=b;
        x=max(s,x);
    }
    cout << x;
}