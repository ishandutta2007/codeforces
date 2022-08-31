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
   int n,p;
    cin >> n >> p;
    
   int a[n];
    f(i,n) cin >> a[i];
    
   vector<int> res;
    
   for(int x=1;x<=2000;x++)
   {
       int ways = 1;
       
       vector<int> place(n,0);
       
       f(j,n)
       {
           if(a[j] <= x) place[0]++;
           else if(a[j] > x + n-1)
           {
               ways = -1;
               break;
           }
           else
           {
               place[a[j] - x]++;
           }
       }
       
       if(ways == -1) continue;
       
       int places = 0;
       
       for(int j=n-1;j>=0;j--)
       {
           places++;
           
           for(int k=0;k<place[j];k++)
           {
               ways = (ways*(places - k))%p;
               ways = (ways*mod_pow(k+1,p-2,p))%p;
           }
           
           places -= place[j];
       }
       
       if(ways % p != 0) res.pb(x);
   }
   
    cout <<res.size() << '\n';
    for(auto x : res) cout << x << ' ';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}