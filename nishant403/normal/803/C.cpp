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

void check(int sum,int n,int gc)
{
    int elms = (sum / gc);
    
    if((n+1) > (elms*2)/n) return;
    
    for(int i=1;i<n;i++)
    {
        cout << (gc*i) << ' ';
        sum-=(gc*i);
    }
    
    cout << sum; 
    
    exit(0);
}

void solve()
{
   int n,k;
    cin >> n >> k;
    
   if(n < k)
   {
       cout << -1 << '\n';
       return;
   }
    
   vi divs; 
    
   for(int i=1;(i*i) <= n;i++)
   {
       if(n % i == 0)
       {
           divs.pb(i);
           divs.pb(n/i);
       }
   }
    
   sort(divs.begin(),divs.end());
   reverse(divs.begin(),divs.end());
    
   for(auto x : divs) check(n,k,x);
   
   cout << -1; 
}

signed main()
{
    fast;
    solve();
}