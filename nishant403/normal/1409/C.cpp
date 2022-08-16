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
  int n,x,y;
    cin >> n >> x >> y;
    
  vi res(n,-1);  
    
    res[n-1] = 2e18;
    
  int dif = y - x;
    
   for(int i=1;i<=dif;i++)
   {
       if(i+1 > n) break;
       
       if(dif % i == 0)
       {
           int dd = dif/i;
           
           //x at position j
           
           for(int j=0;j<n-i;j++)
           {
               vi go(n,-1);
               
               go[j] = x;
               
               for(int k=j+1;k<n;k++) go[k] = go[k-1] + dd;
               for(int k=j-1;k>=0;k--) go[k] = go[k+1] - dd;
               
               if(go[0] <= 0) continue;
               
               int f1 = 0;
               
               f(k,n) if(go[k] == y) f1 = 1;
               
               if(f1 == 0) continue;
                   
               if(res.back() > go.back()) res=  go;   
           }
       }
   }
    
    
  f(i,n) cout << res[i] << ' ';
  cout << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}