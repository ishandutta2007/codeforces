#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i,n) for(i=0;i<n;i++)

signed main()
{
 fast;
 int n,k,i,j;
    
    int a,b,c;
    
    cin >> a >> b >> c;
    
    if(a==b) cout << (2*c + a + b);
    else 
    {
     if(a>b) cout << (2*c + 2*b+1);   
        else cout << (2*c + 2*a+ 1);
    }
    
}