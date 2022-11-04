#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
#define clr(a) memset(a,0,sizeof(a))
typedef double db;
db dp[105][105][105];
bool vis[105][105][105];
void work(int i,int j,int k)
{
    if(i==0 && j==0 && k==0)return;
    if(vis[i][j][k])return;
    vis[i][j][k]=1;
    int cnt=0;
    if(i>0 && k>0)
    {
        work(i-1,j,k);
        cnt+=i*k;
        dp[i][j][k]+=i*k*dp[i-1][j][k];
    }
    if(j>0 && i>0)
    {
        work(i,j-1,k);
        cnt+=j*i;
        dp[i][j][k]+=j*i*dp[i][j-1][k];
    }
    if(k>0 && j>0)
    {
        work(i,j,k-1);
        cnt+=k*j;
        dp[i][j][k]+=k*j*dp[i][j][k-1];
    }
    if(cnt==0)return;
    else dp[i][j][k]/=cnt;
}
int main()
{
    int r,s,p;
    scanf("%d%d%d",&r,&s,&p);
    clr(dp);
    for(int i=1;i<=r;i++)
    {
        dp[i][0][0]=1.0;
    }
    clr(vis);
    work(r,s,p);
    printf("%.10f ",dp[r][s][p]);
    clr(dp);
    for(int j=1;j<=s;j++)
    {
        dp[0][j][0]=1.0;
    }
    clr(vis);
    work(r,s,p);
    printf("%.10f ",dp[r][s][p]);
    clr(dp);
    for(int k=1;k<=p;k++)
    {
        dp[0][0][k]=1.0;
    }
    clr(vis);
    work(r,s,p);
    printf("%.10f\n",dp[r][s][p]);
    return 0;
}