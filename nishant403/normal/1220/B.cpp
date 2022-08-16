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

void solve()
{
  int n;
    cin >> n;
    
    int a[n][n];
    int ans[n];
    
    
    f(i,n) f(j,n) cin >> a[i][j];
    
    ans[0] = (a[1][0]*a[2][0])/a[1][2];
    ans[0] = sqrt(ans[0]);
    
    for(int i=1;i<n;i++) ans[i] = a[0][i]/ans[0];
    
    f(i,n) cout << ans[i] <<" ";
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}