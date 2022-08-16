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
    
    ll n,k,i,ans=0;
    cin >> n;
    
    ll a[n];
    ll maxm=0;
    ll id=0;
    
   f(n) cin >> a[i];
   
   f(n)
   {
       if(a[i] > maxm) maxm=a[i];
       id=i;
       
   }
   ll temp=0;
   
   f(n)
   {
    if(a[i]==maxm) temp++;
    else {
        (ans=max(ans,temp));
    temp=0;
}
   }
    
    ans=max(ans,temp);
    
    cout << ans;
    return 0;
}