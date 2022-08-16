#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int M = 1e9+7;

void solve()
{
 int n,k;
    cin >> n >> k;
    
 int a[4];
    
    a[0] = 1;
    a[1] = (n*(n-1))/2;
    a[2] = (a[1]*(n-2))/3;
    a[2]*=2;
    a[3] = (((a[2]*(n-3))/8)*9) ;
    int ans=0;
    
   f(i,k) ans+=a[i];
    
    cout << ans;     
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}