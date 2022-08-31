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
   int n;
    cin >> n;
    
   int a[n];
    f(i,n) cin>> a[i];
    
   int b[n];
    
   int res = 0;
    
   f(i,25)
   {
       f(j,n) b[j] = a[j] % (1LL<<(i+1));
       sort(b,b+n);
       
       int lim1 = (1LL<<i) - 1;
       int lim2 = (1LL<<(i+1)) - 1;
       int lim3 = (1LL<<(i+1)) + lim1;
       int lim4 = (1LL<<(i+2)) - 2;
       
       int cnt = 0;
       
       int l1 = n-1,r1 = n-1;
       int l2 = n-1,r2 = n-1;
       
       f(j,n)
       {
           while(l1 >= 0 && b[j] + b[l1] > lim1) l1--;
           while(r1 >= 0 && b[j] + b[r1] > lim2) r1--;
           while(l2 >= 0 && b[j] + b[l2] > lim3) l2--;
           while(r2 >= 0 && b[j] + b[r2] > lim4) r2--;
           
           if(l1 > j) cnt-=l1-j;
           if(r1 > j) cnt+=r1-j;
           if(l2 > j) cnt-=l2-j;
           if(r2 > j) cnt+=r2-j;
       }
       
       if(cnt % 2 == 1) res|=(1LL<<i);
   }
    
   cout << res;     
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}