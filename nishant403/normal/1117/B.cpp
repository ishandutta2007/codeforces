#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define f(n) for(i=0;i<n;i++)
#define ll long long 


ll power(ll x,ll y) 
{ 
    ll res = 1;     
    while (y>0) 
    { 
        if (y & 1) 
            res = (res*x)%M; 
   
        y = y>>1; 
        x = (x*x)%M;  
    } 
    return res; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n,m,k,i,ans=0;
    cin >> n >> m >> k;
    
    ll a[n];
  
  f(n) cin >> a[i];
  
  sort(a,a+n);
  
  ll maxm=a[n-1];
  ll axm=a[n-2];
  
  ans=(m/(k+1))*maxm*k;
  ans+=(m/(k+1))*axm;
  
  
  ans+=(m%(k+1))*maxm;
  
  cout << ans;
  
    return 0;
}