#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

void solve()
{
   int n,x,m;
    cin >> n >> x >> m;
    
   pii a[m];
   f(i,m) cin >> a[i].F >> a[i].S;
   
   pii cur = {x,x};
   
   f(i,m)
   {
       if(a[i].S < cur.F) continue;
       if(a[i].F > cur.S) continue;
       
       if(a[i].F <= cur.F && cur.F <= a[i].S) 
       {
           cur.F = a[i].F;
           cur.S = max(cur.S,a[i].S);
       }
       else if(a[i].F <= cur.S && cur.S <= a[i].S)
       {
           cur.S = a[i].S;
           cur.F = min(cur.F,a[i].F);
       }
   }
    
   cout << cur.S - cur.F + 1 << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}