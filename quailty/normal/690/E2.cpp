#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
typedef double db;
const int MAXK=1;
const db INF=1e10;
const db sig=5.0;
const db PI=acos(-1.0);
db a[605][605],b[605][605];
db c[16][16],dp[1<<16][16];
int pre[1<<16][16],res[16];
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int h,w,t;
        scanf("%d%d%d",&h,&w,&t);
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
                scanf("%lf",&b[i][j]);
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
            {
                a[i][j]=0;
                int cnt=0,bk=(i-1)/(h/t);
                for(int p=max(bk*h/t+1,i-MAXK);p<=min((bk+1)*h/t,i+MAXK);p++)
                    for(int q=max(1,j-MAXK);q<=min(w,j+MAXK);q++)
                    {
                        a[i][j]+=b[p][q];
                        cnt++;
                    }
                a[i][j]/=cnt;
            }
        for(int i=0;i<t;i++)
            for(int j=0;j<t;j++)
            {
                c[i][j]=0;
                for(int k=1;k<=w;k++)
                    c[i][j]+=fabs(a[(i+1)*h/t][k]-a[j*h/t+1][k]);
            }
        for(int i=0;i<(1<<t);i++)
            for(int j=0;j<t;j++)
                dp[i][j]=INF;
        for(int i=0;i<t;i++)
            dp[1<<i][i]=0;
        for(int i=1;i<(1<<t);i++)
            for(int j=0;j<t;j++)
            {
                if(~i&(1<<j))continue;
                for(int k=0;k<t;k++)
                {
                    if(i&(1<<k))continue;
                    if(dp[i|(1<<k)][k]>dp[i][j]+c[j][k])
                    {
                        dp[i|(1<<k)][k]=dp[i][j]+c[j][k];
                        pre[i|(1<<k)][k]=j;
                    }
                }
            }
        int now=(1<<t)-1,loc=0;
        for(int i=0;i<t;i++)
            if(dp[now][i]<dp[now][loc])loc=i;
        vector<int>tmp;
        while(now)
        {
            tmp.push_back(loc);
            int t_loc=pre[now][loc];
            now^=1<<loc;
            loc=t_loc;
        }
        reverse(tmp.begin(),tmp.end());
        for(int i=0;i<t;i++)
            res[tmp[i]]=i;
        for(int i=0;i<t;i++)
            printf("%d ",res[i]+1);
        printf("\n");
    }
    return 0;
}