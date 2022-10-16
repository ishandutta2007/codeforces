#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 5005;

int dp[nax][nax];

char a[nax];
char b[nax];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    string x,y; cin>>x>>y;
    for(int i=1;i<=n;i++) a[i] = x[i - 1];
    for(int i=1;i<=m;i++) b[i] = y[i - 1];

    for(int i=0;i<nax;i++)
    {
        for(int j=0;j<nax;j++)
        {
            dp[i][j] = -1e9;
        }
    }

    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }

    for(int i=0;i<=m;i++)
    {
        dp[0][i] = 0;
    }


    int ans = -1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = max(dp[i][j],2 + dp[i - 1][j - 1]);
                ans = max(ans,dp[i][j]);
            }
            else
            {
                dp[i][j] = max(dp[i][j], max(dp[i-1][j],dp[i][j-1]) - 1);
                ans = max(ans,dp[i][j]);
            }

            dp[i][j] = max(dp[i][j],0);
        }
    }
    ans = max(ans,0);
    cout<<ans;

    return 0;
}