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
   
   
   ll q;
    string s;
    
    cin >> q;
    
    while(q--)
    {
        
        ll n,a,b;
        cin >> n >> a >> b;
        
        if(2*a<b)
        {
         cout << a*n << "\n";   
        }
        else if( n%2==1)
        {
            cout << (b*(n/2))+a << "\n";
        }
        else if(n%2==0) cout << (b*n)/2 << "\n";
        
        
        
        
    }
    
    
    
    
    
    
    
    
 return 0;   
}