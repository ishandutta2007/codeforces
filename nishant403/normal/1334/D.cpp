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
   int n,l,r;
    cin >> n >> l >> r;
    
   int starter = 1;
   int cnt = 0;
    
   while(cnt + 2*(n-starter) < l)
   {
       cnt+=2*(n-starter);
       starter++;
       
       if(starter == n) 
       {
           starter = 1;
           break;
       }
   }
   
   l--; r--;
   
   int done = (l-cnt)/2;
   int nex = starter + done + 1;
   int flag = 0;
    
   if((l-cnt)%2 == 1) flag = 1;
    
   for(int i=l;i<=r;i++)
   {
      if(flag == 0) 
      {
          cout << starter << ' ';
          flag = 1;
      }
      else
      {
          cout << nex << ' ';
          flag = 0;
          
          if(nex == n) 
          {
              starter++;
              nex = (starter + 1);
             
              if(starter == n) starter = 1;
          }
          else nex++;
      }
   }
   
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