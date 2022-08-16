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
    
   string s;
   cin >> s;
    
   int col[n];
    
   col[0] = 0;
    
   for(int i=1;i<n;i++)
   {
       int flag = 0;
       int co = -1;
       
       for(int j=0;j<i;j++)
           if(s[j] > s[i])
       {
          if(co == -1) co = col[j];
          else if(co != col[j]) flag = 1;
       }
       
       if(co != -1) col[i] = 1 - co;
       else col[i] = 0;       
      
       if(flag == 1)
       {
                  cout <<"NO\n";
                  return;
       }
          
   }
    
    cout <<"YES\n";
    f(i,n) cout << col[i];
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}