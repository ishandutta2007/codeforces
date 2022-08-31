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

const int N = 3e5 + 10;
const int BLK = 500;

int arr[N];
int a[N];
vector<pii> qq[N];
int res[N];

void solve()
{
   int n;
   cin >> n;
   f(i,n) cin >> a[i];
   
   int x,y;
   
   int q;
   cin >> q;
  
   f(i,q)
   {
       cin >> x >> y;
       qq[y].pb({x-1,i});
   }
    
   for(int i=1;i<=n;i++)
   {
       if(i <= BLK)
       {
           for(int j=n-1;j>=0;j--)
           {
               arr[j] = a[j];
               if(j + i < n) arr[j] += arr[j+i];
           }
           
           for(auto x : qq[i])
               res[x.S] = arr[x.F];
       }
       else
       {
           for(auto x : qq[i])
           {
               for(int j=x.F;j<n;j+=i)
                   res[x.S] += a[j];
           }
       }
    }
 
   f(i,q) cout << res[i] << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}