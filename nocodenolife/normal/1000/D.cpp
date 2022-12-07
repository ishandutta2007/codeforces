#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 998244353 
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll arr[n];
    ForA1(n)
    {
        cin>>arr[i];
    }
    
    ll fact[1005];
    fact[0]=1;
    ll factinv[1005];
    factinv[0]=1;
    for(ll i=1;i<1004;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
        factinv[i] = modInverse(fact[i], mod);
    }
    
    ll dp[n+1] = {0};
    dp[n]=1;
    ll start;
    ll con,mul;
    for(ll i=n-1;i>=0;i--)
    {
        if(arr[i]<=0)
        {
            dp[i]=0;
            continue;
        }
        if(arr[i]+i>=n)
        {
            dp[i]=0;
            continue;
        }
        // dp[i]++;
        start = arr[i]+i+1;
        con = arr[i];
        
        while(start<=n)
        {
            mul = fact[con];
            mul*=factinv[arr[i]];
            mul%=mod;
            mul*=factinv[con-arr[i]];
            mul%=mod;
            dp[i] += mul*dp[start];
            dp[i]%=mod;
            con++;
            start++;
        }
    }
    
    ll ans = 0;
    ForA1(n)
    {
        ans+=dp[i];
        ans %= mod;
        // cout<<dp[i]<<" ";
    }
    
    cout<<ans<<endl;
    

    return 0;
}