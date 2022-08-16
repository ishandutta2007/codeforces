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
   int n;
    cin >> n;
    
   int a[n];
    f(i,n) cin >> a[i];
    
   int dif = 0;
   
   vi b(n-1,0);
    f(i,n-1) b[i] = a[i+1] - a[i];
    
   int res = a[0];
    f(i,n-1) if(b[i] >= 0) res+=b[i];
    
   if(res % 2 == 0) cout << (res/2) << '\n';
   else cout << ((res+1)/2) << '\n';

   int q,l,r,x;
    cin >> q;
    
   while(q--)
   {
       cin >> l >> r >> x;
       l--; r--;
       
       if(l == 0) res+=x;
       
       if(l > 0)
       {
           if(b[l-1] >= 0) res-=b[l-1];
           b[l-1]+=x;
           if(b[l-1] >= 0) res+=b[l-1];
       }
       
       if(r < n-1)
       {
           if(b[r] >= 0) res-=b[r];
           b[r]-=x;
           if(b[r] >= 0) res+=b[r];
       }
       
   if(res % 2 == 0) cout << (res/2) << '\n';
   else cout << ((res+1)/2) << '\n';

   }
  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}