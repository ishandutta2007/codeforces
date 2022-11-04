#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=55;
const int Mod=1000000007;
const int Inv=500000004;
inline void add(int &x,int y)
{
    if((x+=y)>=Mod)x-=Mod;
}
int d[MAXN],cnt[MAXN][MAXN],dp[2][MAXN][MAXN][MAXN*3];
int main()
{
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
        {
            cnt[i][j]=1;
            for(int k=1;k<=i+2*j;k++)
                cnt[i][j]=1LL*k*cnt[i][j]%Mod;
            for(int k=1;k<=j;k++)
                cnt[i][j]=1LL*Inv*cnt[i][j]%Mod;
        }
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    int now=0,la=1;
    if(d[2]==2)dp[now][1][0][d[1]-1]=1;
    else dp[now][0][1][d[1]-1]=1;
    for(int i=3;i<=n;i++)
    {
        swap(now,la);
        memset(dp[now],0,sizeof(dp[now]));
        for(int j=0;j<=i;j++)
            for(int k=0;k<=i;k++)
                for(int l=0;l<=2*i;l++)
                {
                    if(l>0)
                    {
                        if(d[i]==2)
                        {
                            //right 0
                            if(j>0)add(dp[now][j-1][k][l-1],1LL*j*dp[la][j][k][l]%Mod);
                            if(k>0)add(dp[now][j+1][k-1][l-1],1LL*k*dp[la][j][k][l]%Mod);
                            //right 1
                            add(dp[now][j+1][k][l-1],dp[la][j][k][l]);
                        }
                        else
                        {
                            //right 0
                            if(j>1)add(dp[now][j-2][k][l-1],1LL*j*(j-1)/2*dp[la][j][k][l]%Mod);
                            if(k>1)add(dp[now][j+2][k-2][l-1],1LL*k*(k-1)/2*dp[la][j][k][l]%Mod);
                            if(j>0 && k>0)add(dp[now][j][k-1][l-1],1LL*j*k*dp[la][j][k][l]%Mod);
                            //right 1
                            if(j>0)add(dp[now][j][k][l-1],1LL*j*dp[la][j][k][l]%Mod);
                            if(k>0)add(dp[now][j+2][k-1][l-1],1LL*k*dp[la][j][k][l]%Mod);
                            //right 2
                            add(dp[now][j][k+1][l-1],dp[la][j][k][l]);
                        }
                    }
                    else
                    {
                        if(j>0)add(dp[now][d[i]==2][d[i]==3][j+2*k-1],1LL*j*cnt[j-1][k]%Mod*dp[la][j][k][l]%Mod);
                        if(k>0)add(dp[now][d[i]==2][d[i]==3][j+2*k-1],1LL*k*cnt[j+1][k-1]%Mod*dp[la][j][k][l]%Mod);
                    }
                }
    }
    return 0*printf("%d",dp[now][0][0][0]);
}