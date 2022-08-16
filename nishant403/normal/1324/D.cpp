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
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

void solve()
{
   int n;
   cin >> n;
    
    
   int a[n];
   int b[n];
    
   f(i,n) cin >> a[i];
   f(i,n) cin >> b[i];
    
   ordered_set os; 
    
   for(int i=0;i<n;i++)
       os.insert({b[i]-a[i],i});
    
   int res = 0;
    
   for(int i=0;i<n;i++)
   {
       os.erase({b[i]-a[i],i});
       res+=os.order_of_key({a[i]-b[i],-1});
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