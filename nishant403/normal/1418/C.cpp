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

const int N = 2e5 + 10;
int dp[N][2];
int a[N];

void solve()
{
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++)cin >> a[i];
    
    for(int i=0;i<=n;i++) dp[i][0] = dp[i][1] = n;
    
    dp[0][1] = 0;
    
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = min(dp[i][0],dp[i-1][1] + a[i]);
        if(i > 1) dp[i][0] = min(dp[i][0],dp[i-2][1] + a[i] + a[i-1]);
        
        dp[i][1] = min(dp[i][1],dp[i-1][0]);
        if(i > 1) dp[i][1] = min(dp[i][1],dp[i-2][0]);
    }
    
    cout << min(dp[n][0],dp[n][1]) << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}