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
    
   if(n % 2 == 0)
   {
       //if all odd ,breach loses
       int ev = 0;
       f(i,n) if(i % 2 == 1 && (s[i] - '0') % 2 == 0) ev = 1;
           
       if(ev) cout << 2 << '\n';
       else cout << 1 << '\n';
   }
   else
   {
       //if all even, raze loses
       int od = 0;
       f(i,n) if(i % 2 == 0 && (s[i] - '0') % 2 == 1) od = 1;
           
       if(od) cout << 1 << '\n';
       else cout << 2 << '\n';
   }
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}