#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


void solve()
{
   int n,m;
    cin >> n >> m;
    
   pii a[m];
    f(i,m) cin >> a[i].F >> a[i].S;
    f(i,m) swap(a[i].F,a[i].S);
    sort(a,a+m);
    
   int ptr = 0;
   int x = 0,y = 0;
    
   while(ptr < m)
   {
       int xx = a[ptr].F;
       int yy = a[ptr].S;
       
       if(ptr < m-1 && xx == a[ptr+1].F)
       {
           if(x != 0 || y != 0)
           {
               cout <<"NO\n";
               return;
           }
           
           ptr++;
       }
       else 
       {
           int dis = xx;
           if(ptr > 0) dis -= a[ptr-1].F;
           
           if(x == 0 && y == 0) 
           {
               if(yy == 1) x = 0, y = 1;
               else x = 1, y = 0;
           }
           else if(x == 0 && y == 1)
           {
               if(yy == 2 && dis % 2 == 1)
               {
                   cout <<"NO\n";
                   return;
               }
               else if(yy == 2) x = 0, y = 0;
               else if(yy == 1 && dis % 2 == 0)
               {
                   cout <<"NO\n";
                   return;
               }
               else x = 0,y = 0;
           }
           else 
           {
               if(yy == 1 && dis % 2 == 1)
               {
                   cout <<"NO\n";
                   return;
               }
               else if(yy == 1) x = 0, y = 0;
               else if(yy == 2 && dis % 2 == 0)
               {
                   cout <<"NO\n";
                   return;
               }
               else x = 0,y = 0;
           }
       }
       
       ptr++;
   }
    
   if(x == 0 && y == 0) cout << "YES\n"; 
   else cout <<"NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}