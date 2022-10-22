#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+1;
const int inf = 0x7fffffff;
int n,p,k,cnt,res;
int dp[2][N][51][51],in1[2][2][N][55],in[2][N],q[2][N];

int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for(int i=0;i<2;++i)
    {
        scanf("%d",&cnt);
        for(int t=1,x;t<=cnt;++t)scanf("%d",&x),q[i][x]=1;
    }
    if(p>2*ceil(n/k))
    {
        for(int i=1;i<=n;++i)res+=(q[0][i]||q[1][i]);
        printf("%d",res);
        return 0;
    }
    int now=0;
    memset(dp,-0x3f,sizeof dp);
    memset(in1,-0x3f,sizeof in1);
    memset(in,-0x3f,sizeof in);
    in1[1][0][0][0]=in1[1][1][0][0]=in[1][0]=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=p;++j)
        {
            in[now][j]=-inf;
            for(int r=0;r<=k;++r)
            {
                in1[now][0][j][r]=in1[now][1][j][r]=-inf;
                for(int r1=0;r1<=k;++r1)dp[now][j][r][r1]=-inf;
            }
        }
        for(int j=0;j<=p;++j)
        {
            for(int r1=0;r1<=k;++r1)
            {
                for(int r2=0;r2<=k;++r2)
                {
                    int &cur=dp[now][j][r1][r2];
                    if(r1>1&&r2>1&&j>=2)
                    cur=max(cur,dp[!now][j][r1-1][r2-1]+(q[0][i]||q[1][i]));
                    if((r1==0||r1==1)&&j>=r1&&!(r2==0||r2==1))
                    cur=max(cur,in1[!now][0][j-r1][r2-1]+(q[1][i]||(q[0][i]&&r1)));
                    if((r2==0||r2==1)&&j>=r2&&!(r1==0||r1==1))
                    cur=max(cur,in1[!now][1][j-r2][r1-1]+((q[1][i]&&r2)||q[0][i]));
                    if((r1==0||r1==1)&&(r2==0||r2==1)&&j>=r1+r2)
                    cur=max(cur,in[!now][j-r1-r2]+((q[0][i]&&r1)||(q[1][i]&&r2)));
                    in[now][j]=max(in[now][j],cur);
                    in1[now][0][j][r2]=max(in1[now][0][j][r2],cur);
                    in1[now][1][j][r1]=max(in1[now][1][j][r1],cur);
                    res=max(res,cur);
                }
            }
        }
        now^=1;
    }
    printf("%d",res);
 }