#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
    fast;
    
    int n;
    cin >> n;
    
    if(n%2==1) cout << 0;
    else cout << (1LL<<(n/2));
    
    
}