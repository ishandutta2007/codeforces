#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int c[16],r[16],b[16],dp[1<<16][200];
inline void checkMin(int &x,int y)
{
    if(x>y)x=y;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char ty[5];
        scanf("%s%d%d",ty,&r[i],&b[i]);
        c[i]=(*ty=='B');
    }
    memset(dp,INF,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<(1<<n);i++)
    {
        int A=0,B=0;
        for(int j=0;j<n;j++)if(i>>j&1)
        {
            if(!c[j])A++;
            else B++;
        }
        for(int j=0;j<n;j++)if(~i>>j&1)
        {
            int dk=min(A,r[j]);
            for(int k=0;k+dk<200;k++)
                checkMin(dp[i|(1<<j)][k+dk],dp[i][k]+max(b[j]-B,0));
        }
    }
    int res=INF,sum=0;
    for(int i=0;i<n;i++)
        sum+=r[i];
    for(int j=0;j<200;j++)
        checkMin(res,max(sum-j,dp[(1<<n)-1][j]));
    printf("%d\n",res+n);
    return 0;
}