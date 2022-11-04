#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int d[5][2]={{0,1},{1,0},{0,-1},{-1,0},{0,0}};
const ll Mod=1000000007LL;
ll dp[2][505][505];
char s[505][505];
inline bool judge(int n,int m,int x,int y)
{
    return x>=0 && x<n && y>=0 && y<m;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    memset(dp,0,sizeof(dp));
    int la=1,now=0;
    dp[now][0][m-1]=(s[0][0]==s[n-1][m-1] ? 1 : 0);
    for(int len=1;len<=(n+m-2)/2;len++)
    {
        now^=1;
        la^=1;
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                dp[now][i][j]=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
            {
                int px=len-i;
                int py=i;
                int qx=n+m-2-len-j;
                int qy=j;
                if(judge(n,m,px,py) && judge(n,m,qx,qy) && s[px][py]==s[qx][qy])
                {
                    for(int p=2;p<=3;p++)
                        for(int q=0;q<=1;q++)
                        {
                            int tpx=px+d[p][0];
                            int tpy=py+d[p][1];
                            int tqx=qx+d[q][0];
                            int tqy=qy+d[q][1];
                            if(judge(n,m,tpx,tpy) && judge(n,m,tqx,tqy) && s[tpx][tpy]==s[tqx][tqy])
                                dp[now][py][qy]=(dp[now][py][qy]+dp[la][tpy][tqy])%Mod;
                        }
                }
            }
    }
    ll ans=0LL;
    for(int i=0;i<m;i++)
        ans=(ans+dp[now][i][i])%Mod;
    if((n+m)&1)
        for(int i=0;i<m-1;i++)
            ans=(ans+dp[now][i][i+1])%Mod;
    printf("%I64d\n",ans);
    return 0;
}