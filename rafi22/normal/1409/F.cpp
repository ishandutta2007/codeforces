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
        int n,k,ans=0;
        cin>>n>>k;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int l=0;l<=n;l++)
                {
                    DP[i][j][l]=-inf;
                }
            }
        }
        string str,s;
        cin>>str>>s;
        str='#'+str;
        if(s[0]==s[1])
        {
            int cnt=0;
            for(int i=1;i<=n;i++) cnt+=(str[i]==s[0]);
            cnt=min(n,cnt+k);
            cout<<cnt*(cnt-1)/2;
            return 0;
        }
        DP[0][0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                for(int l=0;l<=n;l++)
                {
                    if(str[i]==s[0])
                    {
                        if(l!=0) DP[i][j][l]=DP[i-1][j][l-1];
                        if(j!=0)DP[i][j][l]=max(DP[i][j][l],DP[i-1][j-1][l]+l);
                    }
                    else if(str[i]==s[1])
                    {
                        DP[i][j][l]=DP[i-1][j][l]+l;
                        if(j!=0) DP[i][j][l]=max(DP[i][j][l],DP[i-1][j-1][l-1]);
                    }
                    else
                    {
                        DP[i][j][l]=DP[i-1][j][l];
                        if(l!=0&&j!=0) DP[i][j][l]=max(DP[i][j][l],DP[i-1][j-1][l-1]);
                        if(j!=0) DP[i][j][l]=max(DP[i][j][l],DP[i-1][j-1][l]+l);
                    }
                    ans=max(ans,DP[i][j][l]);
                }
            }
        }
        cout<<ans;
    }
    return 0;
}