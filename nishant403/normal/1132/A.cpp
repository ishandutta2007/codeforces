#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

int main()
{
    FAST;
    
    ll n,k,i,j,ans=0;
    ll c[4];
    
    f(i,4) cin >> c[i];
    
    if(c[0] == 0 && (c[2] || c[3] ) ) cout << 0;
    else if(c[0] == c[3] ) cout << 1;
    else cout << 0;
   
    
    
    
}