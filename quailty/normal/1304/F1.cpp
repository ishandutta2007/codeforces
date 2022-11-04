#include<bits/stdc++.h>
using namespace std;
const int MAXM=20005;
const int INF=0x3f3f3f3f;
int a[MAXM],dp[MAXM],tmp[2][MAXM];
typedef function<int(int,int)> CostFunc;
void solve0(int l,int r,int tl,int tr,const CostFunc& cost)
{
    if(l>r)return;
    int m=(l+r)/2,tm=tl;
    int& res=tmp[0][m];
    for(int i=tl;i<=tr && i<=m;i++)
    {
        int val=dp[i]+cost(i,m);
        if(res<val)res=val,tm=i;
    }
    solve0(l,m-1,tl,tm,cost);
    solve0(m+1,r,tm,tr,cost);
}
void solve1(int l,int r,int tl,int tr,const CostFunc& cost)
{
    if(l>r)return;
    int m=(l+r)/2,tm=tr;
    int& res=tmp[1][m];
    for(int i=max(m,tl);i<=tr;i++)
    {
        int val=dp[i]+cost(m,i);
        if(res<val)res=val,tm=i;
    }
    solve1(l,m-1,tl,tm,cost);
    solve1(m+1,r,tm,tr,cost);
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    /// i=1
    {
        for(int j=1;j<=m;j++)
            scanf("%d",&a[j]),a[j]+=a[j-1];
        for(int j=1;j<=m-k+1;j++)
            dp[j]=a[j+k-1]-a[j-1];
    }
    CostFunc cost=[&](int i,int j)
    {
        int res=a[i+k-1]-a[i-1]+a[j+k-1]-a[j-1];
        int l=max(i,j),r=min(i+k-1,j+k-1);
        res-=(l<=r ? a[r]-a[l-1] : 0);
        return res;
    };
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            scanf("%d",&a[j]),a[j]+=a[j-1];
        for(int j=1;j<=m;j++)
            tmp[0][j]=tmp[1][j]=-INF;
        solve0(1,m-k+1,1,m-k+1,cost);
        solve1(1,m-k+1,1,m-k+1,cost);
        for(int j=1;j<=m;j++)
            dp[j]=max(tmp[0][j],tmp[1][j]);
    }
    int res=-INF;
    for(int j=1;j<=m;j++)
        res=max(res,dp[j]);
    return 0*printf("%d\n",res);
}