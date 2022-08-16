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

const int N = 3e5 + 10;

int s[N+N];
int s2[N+N];

vector<int> fact(N),ifact(N),powersum(N);

int mod_mul(int a,int b)
{
    return ((long long)a*b)%MOD;
}

void pre()
{
    //Factorial and Inverse Factorial
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = mod_mul(fact[i-1],i);
        
    ifact[N-1] = mod_pow(fact[N-1],MOD-2);
    for(int i=N-2;i>=0;i--) ifact[i] = mod_mul(ifact[i+1],i+1);
}

int ncr(int n,int k)
{
    if(k>n) return 0;
    return mod_mul(fact[n],mod_mul(ifact[n-k],ifact[k]));
}

void solve()
{
   int n,k;
    cin >> n >> k;
    
   pii a[n];
   f(i,n) cin >> a[i].F >> a[i].S;
    
   vi c;
    f(i,n) c.pb(a[i].F),c.pb(a[i].S);
    sort(c.begin(),c.end());
    
   f(i,n) a[i].F = lower_bound(c.begin(),c.end(),a[i].F) - c.begin();
   f(i,n) a[i].S = lower_bound(c.begin(),c.end(),a[i].S) - c.begin();
    
   f(i,n) s[a[i].F]++,s[a[i].S+1]--;
   
   f(i,n) 
   {
       s2[a[i].F+1]++;
       s2[a[i].S+1]--;
   }
    
   int r = n + n - 1;
    
   for(int i=1;i<=r;i++) s[i]+=s[i-1],s2[i]+=s2[i-1];
    
   int res = 0;
    
   for(int i=0;i<=r;i++)
   {
       res = (res + ncr(s[i],k))%MOD;
       res = (res + MOD - ncr(s2[i],k))%MOD;
   }
    
    cout << res;
}

signed main()
{
    pre();
    
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}