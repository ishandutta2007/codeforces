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
   string s;
    cin >> s;
    
   int n = s.length(); 
    
   int x;
    cin >> x;
    
   string res;
    
   f(i,n) res+= '1';
    
   int id; 
    
   f(i,n)
       if(s[i] == '0')
   {
       id = i-x;
       
       if(id >= 0 && id < n)
       {
           res[id] = '0';
       }
       
       id = i + x;
        
       if(id >= 0 && id < n)
       {
           res[id] = '0';
       }
   }
    
   //now verify
   int flag = 1; 
    
   f(i,n)
       if(s[i] == '0')
   {
       if((i-x) >= 0)
       {
           if( res[i-x] == '1') flag = 0;
       }
       
       if((i+x) < n)
       {
           if( res[i+x] == '1') flag = 0;
       }
   }
    else
    {
        int ff = 0;
        
        if((i-x)>=0 && res[i-x] == '1') ff = 1;
        if((i+x)<n && res[i+x] == '1') ff = 1;
        
        if(ff == 0) flag = 0;
    }
    
   if(flag == 0) cout << -1 << '\n'; 
   else cout << res << '\n';
       
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}