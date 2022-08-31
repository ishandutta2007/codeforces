 #include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define f(n) for(i=0;i<n;i++)
typedef long long ll;


ll mexp(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}


int main()
{
   ios_base:: sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   
   ll n,k,i,q;
    string s;
    
    cin >> n;
    
    ll a[n];
    
    f(n) cin >> a[i];
    
    ll ans=0;
    ll oddsum=0;
    ll evensum=0;
    ll o=0;
    ll e=0;
    
    f(n)
    {
        if(i%2)
    oddsum+=a[i];
else    evensum+=a[i];
    }
    
    
    for(int i=0;i<n;i++)
    {
      if(i%2==0) evensum-=a[i];
      else oddsum-=a[i];
      
      
      if(o+evensum==e+oddsum) ans++;  
        
    if(i%2)    
     o+= a[i];
     else e+=a[i];
    }
    
    
    
    cout << ans;
 return 0;   
}