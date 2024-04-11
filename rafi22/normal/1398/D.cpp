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

const bool multi=0;

int DP[207][207][207];
int r[207];
int g[207];
int b[207];

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
        int rn,gn,bn,ans=-inf;
        cin>>rn>>gn>>bn;
        for(int i=1;i<=rn;i++) cin>>r[i];
        for(int i=1;i<=gn;i++) cin>>g[i];
        for(int i=1;i<=bn;i++) cin>>b[i];
        sort(r+1,r+1+rn);
        sort(g+1,g+1+gn);
        sort(b+1,b+1+bn);
        for(int i=0;i<=rn;i++)
        {
            for(int j=0;j<=gn;j++)
            {
                for(int l=0;l<=bn;l++)
                {
                    if(i>0&&j>0) DP[i][j][l]=max(DP[i][j][l],DP[i-1][j-1][l]+r[i]*g[j]);
                    if(i>0&&l>0) DP[i][j][l]=max(DP[i][j][l],DP[i-1][j][l-1]+r[i]*b[l]);
                    if(j>0&&l>0) DP[i][j][l]=max(DP[i][j][l],DP[i][j-1][l-1]+g[j]*b[l]);
                    ans=max(ans,DP[i][j][l]);
                }
            }
        }
        cout<<ans;
    }

    return 0;
}