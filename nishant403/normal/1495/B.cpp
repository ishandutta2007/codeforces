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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
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
   f(i,n) cin >> a[i];
    
   vi lef(n,0),rig(n,0);
   vi lef2(n,0),rig2(n,0);
    
   for(int i=1;i<n;i++)
   {
       if(a[i-1] < a[i]) lef[i] = lef[i-1] + 1;
       else lef2[i] = lef2[i-1] + 1;
   }
    
   for(int i=n-2;i>=0;i--)
   {
       if(a[i+1] < a[i]) rig[i] = rig[i+1] + 1;
       else rig2[i] = rig2[i+1] + 1;
   }
       
   int res = 0;
   
   vector<int> fre(n+1,0);
   int mxx = 0;
   
   f(i,n) fre[lef2[i]]++;
   f(i,n) fre[rig2[i]]++;
   f(i,n) mxx = max(mxx,lef2[i]);
   f(i,n) mxx = max(mxx,rig2[i]);
    
   for(int i=0;i<n;i++)
   {
       if(lef[i] == 0 || rig[i] == 0) continue;
       
       int mx = max(lef[i],rig[i]);
       
       if(lef[i] != rig[i]) continue;
       
       if(lef[i] % 2 == 1) continue;
       
       if(mxx > mx) continue;
      
       if(fre[mx] > 2) continue;
       
       res++;
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