#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()

const int N = 5e5 + 10;

int a[N],dp[N];
vector<int> g[N];

signed main()
{
    fast;
    
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        g[a[i]].push_back(i);
    }
   
    int res = 0;
    
    for(int i=1;i<=n;i++)
    {
        dp[i] = dp[i-1];
        
        if(i == g[a[i]].back())
        {
             int cnt = g[a[i]].size();
            
             dp[i] = max(dp[i] , dp[g[a[i]][0] - 1] + cnt);
            
             for(int j=cnt-1;j>=0;j--)
                 res = max(res , cnt - j + dp[g[a[i]][j] - 1]);
        }
    }
    
    cout << n - res << '\n';
}