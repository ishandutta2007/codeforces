#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int tab[207];
int DP[207][407];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,ans=inf;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>tab[i];
        sort(tab+1,tab+n+1);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=2*n;j++)
            {
                DP[i][j]=inf;
            }
        }
        DP[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n;j++)
            {
                for(int l=i-1;l<j;l++)
                {
                    DP[i][j]=min(DP[i][j],DP[i-1][l]);
                }
                DP[i][j]+=abs(tab[i]-j);
                //cout<<DP[i][j]<<" ";
            }
           // cout<<endl;

        }
        for(int j=1;j<=2*n;j++)
        {
            ans=min(ans,DP[n][j]);
        }
        cout<<ans<<endl;
    }

    return 0;
}