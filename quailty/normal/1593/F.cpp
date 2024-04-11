#include<bits/stdc++.h>
using namespace std;
const int MAXN=41;
bool dp[MAXN][MAXN][MAXN][MAXN];
tuple<int,int,int> pre[MAXN][MAXN][MAXN][MAXN];
void solve()
{
    int n,A,B;
    char x[MAXN];
    scanf("%d%d%d%s",&n,&A,&B,x+1);
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0]=1;
    for(int i=1;i<=n;i++)
    for(int j=0;j<A;j++)
    for(int k=0;k<B;k++)
    for(int r=0;r<i;r++)
    if(dp[i-1][j][k][r]){
        int c=x[i]-'0';
        dp[i][(j*10+c)%A][k][r+1]=1;
        dp[i][j][(k*10+c)%B][r]=1;
        pre[i][(j*10+c)%A][k][r+1]={1,j,k};
        pre[i][j][(k*10+c)%B][r]={0,j,k};
    }
    int res=n,loc=0;
    for(int r=0;r<=n;r++)
        if(dp[n][0][0][r] && res>abs(n-2*r))
            res=abs(n-2*r),loc=r;
    if(res>=n)printf("-1\n");
    else
    {
        vector<int> ans(n);
        int tj=0,tk=0,tr=loc;
        for(int ti=n;ti>=1;ti--)
        {
            int sr,sj,sk;
            tie(sr,sj,sk)=pre[ti][tj][tk][tr];
            ans[ti-1]=sr;
            tj=sj,tk=sk,tr-=sr;
        }
        for(int i=0;i<n;i++)
            printf("%c","BR"[ans[i]]);
        printf("\n");
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}