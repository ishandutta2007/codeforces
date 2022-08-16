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
    
    if(n == 2)
    {
        if(a[0] == a[1]) cout <<"YES\n";
        else cout << "NO\n";
        return;
    }
    
   int b[n];
   int s1 = 0,s2 = 0;
   
   for(int i=0;i<n;i++)
   {
      if(i % 2 == 0)
      {
          s2+=a[i];
          b[i] = s2;
      }
      else
      {
          s1+=a[i];
          b[i] = s1;
      }
   }
    
   vector<int> d(n-1,0);
   vector<int> mn(n-1,0);
    
   f(i,n-1) d[i] = b[i+1] - b[i];
   
   for(int i=n-2;i>=0;i--)
   {
       if(i >= n-3) mn[i] = d[i];
       else mn[i] = min(d[i],mn[i+2]);
   }
    
   if(mn[0] >= 0 && mn[1] >= 0 && mn[n-2] == 0) 
   {
       cout <<"YES\n";
       return;
   }
    
   for(int i=0;i<n-1;i++)
   {
       //swap a[i] and a[i+1]
       int dif = a[i+1] - a[i];
       int dd = s2 - s1;
       
       if(i % 2 == 0) dd += (dif + dif);
       else dd -= (dif + dif);
       
       if(i > 1 && d[i-2] < 0) break;
       
       if(dd != 0) continue;
       
       if(i > 0)
       {
           if(d[i-1] + dif < 0) continue;
       }
       
       if(i+1 < n-1 && mn[i+1] + (2*dif) < 0) continue;
       
       if(mn[i] - (2*dif) < 0) continue;
       
       cout <<"YES\n";
       return;
   }
   
   cout <<"NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}