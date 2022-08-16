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

bool check(vi & a,int step)
{
    int n = a.size();
    
    for(int i=0;i<step;i++)
    {
      int flag = 1;
     
       for(int j=i;j<n;j+=step)   
           if(a[j] != a[i]) flag = 0;
           
     if(flag == 1) return 1;
    }
    
    return 0;
}

int go(vi & a)
{
    int n = a.size();
    int res = n;
    
    for(int i=1;(i*i) <= n;i++)
    {
       if(n%i == 0)
       {
           if(check(a,i)) res = min(res,i);
           if(check(a,n/i)) res = min(res,n/i);
       }
    }
    
    return res;
}

void solve()
{
   int n;
   cin >> n;
   
   int a[n];
   int b[n];
    
   f(i,n) cin >> a[i];
   f(i,n) a[i]--;
    
   f(i,n) cin >> b[i];    
    
   vi vis(n,0);
    
   int res = n; 
    
   vi cyc; 
    
   f(i,n)
   {
       if(vis[i] == 1) continue;
       
       cyc.clear();
       vis[i] = 1;
       int cur = i;
       
       cyc.pb(b[i]);
       
       while(vis[a[cur]] == 0)
       {
           vis[a[cur]] = 1;
           cur = a[cur];
           cyc.pb(b[cur]);
       }
       
       res = min(res,go(cyc));
   }
    
   cout << res << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}