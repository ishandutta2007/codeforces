#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

int main()
{
    FAST;
    
    ll n,k,m,i,j,ans=0;
    ll sum=0;
    
    cin >> n;
    ll a[n];
    
    f(i,n) { cin >> a[i]; sum+=a[i]; }
    
   cin >> m;
    ll b[m];
    
    sort(a,a+n);
    
    f(i,m) cin >> b[i];
    
    
    f(i,m)
    {
        cout << sum - a[ n-b[i]] <<"\n";
        
        
        
    }
}