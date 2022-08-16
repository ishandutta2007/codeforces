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

const int MOD = 998244353;

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
    
   for(int i=1;i<=n;i++)
   {
       //case 1 no neighbours
       if(i == n)
       {
           cout << 10;
           return;
       }
       
       int res = 0;
       
       //case 2 : 1 neighbours
       int other1 = n - i - 1;
       int pos = 2;
       int temp = mod_pow(10,other1);
       temp = (temp*10)%MOD;
       temp = (temp*9)%MOD;
       temp = (temp*pos)%MOD;
       res = temp;
       
       //case 3 : 2 neighbours
       int other2 = n - i - 2;
       
       if(other2 < 0) 
       {
           cout << res <<" ";
           continue;
       }
       
       pos = (n+1) - i - 2;
       temp = 10;
       temp = (temp*pos)%MOD;
       temp = (temp*mod_pow(10,other2))%MOD;
       temp = (temp*81)%MOD;
       res = ( res + temp)%MOD;
       
       cout << res << " ";
       
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