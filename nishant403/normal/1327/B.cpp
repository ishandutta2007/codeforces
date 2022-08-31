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

const int N = 1e5+10;
vi g[N];

void solve()
{
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++) g[i].clear();
    
    for(int i=1;i<=n;i++)
    {
        int k,x;
        cin >> k;
        
        for(int j=0;j<k;j++)
        {
            cin >> x;
            g[i].pb(x);
        }
    }
    
   vi used(n+1,0);
   
   int id = -1; 
    
   for(int i=1;i<=n;i++)
   {
       int flag = 1;
       
       for(auto x : g[i])
           if(used[x] == 0)
       {
           used[x] = 1;
           flag = 0;
           break;
       }
       
       if(flag == 1)
       {
           id = i;
       }
   }
    
   if(id == -1)
   {
       cout <<"OPTIMAL\n";
       return;
   }
    
   cout <<"IMPROVE\n";
    
   for(int i=1;i<=n;i++) 
   {
      if(used[i] == 0)
      {
          cout << id <<" "<<i << '\n';
          return;
      }
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