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

const int N = 1e5 + 10;

int fact[N];
int ifact[N];

void init()
{
    fact[0] = 1;
    
    for(int i=1;i<N;i++) fact[i] = (fact[i-1]*i)%MOD;
    
    ifact[N-1] = mod_pow(fact[N-1],MOD-2);
    
    for(int i=N-2;i>=0;i--) 
        ifact[i] = (ifact[i+1]*(i+1))%MOD;
}

int ncr(int n,int r)
{
 if(r>n) return 0;
    
 int res = fact[n];
    
 res = (res*ifact[r])%MOD;
 res = (res*ifact[n-r])%MOD;
    
  return res;
}

const int K = 5006;
int dp[K];

void mult(vector<int> & a,int b)
{
    int n = a.size();
    a.pb(1);
    
    for(int i=n-1;i>=0;i--)
    {
        a[i] = (a[i]*b);
        if(i > 0) a[i]+=a[i-1];
        
        a[i]%=MOD;
        if(a[i] < 0) a[i]+=MOD;
    }
}

void solve()
{
   int n,k;
   cin >> n >> k;
    
   dp[0] = mod_pow(2,n); 
    
   int val = dp[0]; 
    
   vector<int> go = {1};
    
   for(int i=1;i<=k;i++)
   {
       val = (val*(n-i+1))%MOD;
       val = (val*ifact[2])%MOD;
       dp[i] = val;
       mult(go,1-i);
       
       for(int j=0;j<i;j++)
       {
           dp[i]-=(dp[j]*go[j]);
           dp[i]%=MOD;
           if(dp[i] < 0) dp[i]+=MOD;
       }
   }   
    
   cout << dp[k];
}

signed main()
{
    fast;
    init();
    solve();
}