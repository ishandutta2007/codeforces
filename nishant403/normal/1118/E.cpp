#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=1;i<=n;i++)
#define ll long long 
   
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    ll n,k;
    cin >> n >> k;
    if(k*(k-1) < n ) {cout << "NO\n"; return 0;}
    cout <<"YES\n";
    
    ll c=0,a,b;
    ll i,j;
    ll par=0;
    
    f(i,k-1)
    {
        
     for(j=i+1;j<=k;j++)
     {
      cout << i << " " << j << "\n";
        if(++c==n) return 0;
         
      cout << j << " " << i << "\n";
        if(++c==n) return 0;
         
       }
    }
    
}