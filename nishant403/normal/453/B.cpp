#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int sz = (1<<17);
const int inf = 1e4;

int pr[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int mask[61];
int dp[101][sz];
int par[101][sz];

signed main()
{
    fast;
    
    for(int i=1;i<=60;i++)
        for(int j=0;j<17;j++) if(i % pr[j] == 0) mask[i]|=(1<<j);
    
    int n;
    cin >> n;
    
    int a[n];
    f(i,n) cin >> a[i];
    
    for(int i=0;i<n;i++) 
        for(int j=0;j<sz;j++) dp[i][j] = inf,par[i][j] = -1;
    
    for(int i=1;i<=60;i++)
    {
       if(dp[0][mask[i]] > abs(a[0] - i) )
       {
        dp[0][mask[i]] = abs(a[0] - i),par[0][mask[i]] = i;
       }
    }
    
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=60;j++)
        {
            int anti_mask = (mask[j]^(sz - 1));
            
            for(int k=anti_mask;;k=(k-1)&anti_mask)
            {
                if(dp[i][k^mask[j]] > dp[i-1][k] + abs(a[i] - j))
                {
                    dp[i][k^mask[j]] = dp[i-1][k] + abs(a[i] - j);
                    par[i][k^mask[j]] = j;
                }
                
                if(k == 0) break;
            }
        }
    }
    
    int res = inf;
    int id = -1;
    
    for(int i=0;i<sz;i++)
        if(dp[n-1][i] < res)
    {
        res = dp[n-1][i];
        id = i;
    }
    
    vi seq(n);
    
    for(int i=n-1;i>=0;i--)
    {
        seq[i] = par[i][id];
        id^=mask[seq[i]];
    }
    
    f(i,n) cout << seq[i] << ' ';
}