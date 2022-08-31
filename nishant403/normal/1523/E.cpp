#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

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


const int N = 1e6 + 100;

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
 if(n < 0 || r < 0) return 0;   
    
 int res = fact[n];
    
 res = (res*ifact[r])%MOD;
 res = (res*ifact[n-r])%MOD;
    
  return res;
}


int npr(int n,int r)
{
 if(r>n) return 0;
 if(n < 0 || r < 0) return 0;
    
 int res = fact[n];
 res = (res*ifact[n-r])%MOD;
    
  return res;
}

//dp[v] denotes count of ways to select v places from n,
//so that each of them is atleast k distance apart
int dp[N];
int valid[N];

int get_sum(int n,int r)
{
    return ncr(n+1,r+1);
}

void solve()
{
   int n,k;
   cin >> n >> k;

   for(int i=0;i<=n+5;i++) valid[i] = dp[i] = 0; 
    
   dp[1] = n;
    
   for(int i=2;i<=n;i++)
   {
       dp[i] = get_sum((n-1) - (k*(i-1)) + (i-1) ,i-1);
   }
    
   int res = 0;
    
   for(int i=n-1;i>=1;i--)
   {
       valid[i] = (dp[i]*(n - i))%MOD;
       valid[i] = (valid[i]*fact[i])%MOD;
       
       valid[i] -= (dp[i+1]*fact[i+1]);
       valid[i] %= MOD;
       
       if(valid[i] < 0) valid[i] += MOD;
      
       int ww = ncr(n,i+1);
       ww = (ww*fact[i+1])%MOD;
       
       ww = mod_pow(ww,MOD-2);
       
       valid[i] = (valid[i]*ww)%MOD;
       
       res = (res + (valid[i]*(i+1)))%MOD;
   }
   
   cout << res << '\n';
}

signed main()
{
    init();
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}