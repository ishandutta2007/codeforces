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
    
   string s;
   cin >> s;
    
   f(i,n)
   {
      if(s[i] == '0' && i >= (n/2))
      {
          int r1 = i;
          int r2 = (i-1);
          int l1 = r1 - (n/2) ;
          int l2 = l1;
          
          cout << l1 + 1 << ' ' << r1 + 1 << ' ' << l2 + 1 << ' ' << r2 + 1 << '\n';
          return;
      }
   }
    
   f(i,n)
   {
       if(s[i] == '0' && i + (n/2) < n)
       {
           int l1 = i;
           int l2 = i + 1;
           int r1 = i + (n/2);
           int r2 = i + (n/2);
           
           cout << l1 + 1 << ' ' << r1 + 1 << ' ' << l2 + 1 << ' ' << r2 + 1 << '\n';
           return;
       }
   }
    
   int r1 = n-1;
   int r2 = n-2;
   int l1 = r1 - (n/2) + 1;
   int l2 = r2 - (n/2) + 1;
   
   cout << l1 + 1 << ' ' << r1 + 1 << ' ' << l2 + 1 << ' ' << r2 + 1 << '\n';  
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}