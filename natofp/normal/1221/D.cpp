#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=3e5+5;
ll inf=(ll)1e18+5;
ll dp[nax][3];
ll wys[nax];
ll koszt[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>>q;
    while(q--)
    {
        int n; cin>>n;
        for(int i=1;i<=n;i++)
        {
            ll a,b; cin>>a>>b;
            wys[i]=a;
            koszt[i]=b;
        }
        dp[1][0]=0;
        dp[1][1]=koszt[1];
        dp[1][2]=koszt[1]*2;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<3;j++) dp[i][j]=inf;
            for(int j=0;j<3;j++)
            {
                for(int p=0;p<3;p++)
                {
                    if(wys[i]+j==wys[i-1]+p) continue;
                    dp[i][j]=min(dp[i][j],dp[i-1][p]+koszt[i]*j);
                }
            }
        }
        ll res=dp[n][0];
        res=min(res,dp[n][1]);
        res=min(res,dp[n][2]);
        cout<<res<<"\n";
    }
    return 0;
}