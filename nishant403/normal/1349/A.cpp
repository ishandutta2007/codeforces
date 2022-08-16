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

const int N = 2e5 + 10;
vi lprime(N,-1);

void sieve()
{
    lprime[0] = lprime[1] = 0;
    
    for(int i=2;i*i<N;i++)
        if(lprime[i] == -1)
         for(int j=i*i;j<N;j+=i) lprime[j] = i;
}

int occ[N];

void solve()
{
   int n;
    cin >> n;
    
   int a[n];
    f(i,n) cin >> a[i];
    
   int res = 1; 
    
   for(int i=0;i<n;i++)
   {
       int v = a[i];
       
       while(v > 1 && lprime[v] != -1)
       {
           int tt = lprime[v];
           occ[tt]++;
           while(v%tt == 0) v/=tt;
       }
       
       occ[v]++;
   }
    
   for(int i=2;i<N;i++)
   {
       if(occ[i] >= n-1 && lprime[i] == -1)
       {
           int mn = 100;
           int smn = 100;
           
           f(j,n)
           {
               int cn = 0;
               int v = a[j];
               
               while(v % i == 0) v/=i,cn++;
               
               if(cn < mn)
               {
                   smn = mn;
                   mn = cn;
               }
               else if(cn >= mn)
               {
                   if(cn < smn) smn = cn;
               }
           }
           
           while(smn--) res*=i;
       }
   }
  
    cout << res;
}

signed main()
{
    sieve();
    
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}