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
   int n,k;
    cin >> n >> k;
    
   int a[n];
    f(i,n) cin >> a[i];
    
   pii last_range = {a[0],a[0]};
    
   for(int i=1;i<n-1;i++)
   {
       pii nex = {a[i],a[i]+k-1};
   
       nex.F = max(nex.F,last_range.F-(k-1));
       nex.S = min(nex.S,last_range.S+(k-1));
       
       if(nex.F > nex.S)
       {
           cout << "NO\n";
           return;
       }
    
       swap(nex,last_range);
   }
   
   if(last_range.F > a[n-1]+k-1 || last_range.S < a[n-1]-(k-1))
   {
       cout << "NO\n";
       return;
   }
    
   cout <<"YES\n";    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}