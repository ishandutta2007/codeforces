#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=100005;
int a[MAXN],mm[MAXN];
int dp[MAXN][20],up[MAXN][20];
void initRMQ(int n,int b[])
{
    mm[0]=-1;
    for(int i=1;i<=n;i++)
    {
        mm[i]=((i&(i-1))==0) ? mm[i-1]+1 : mm[i-1];
        dp[i][0]=b[i];
        up[i][0]=b[i];
    }
    for(int j=1;j<=mm[n];j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
            up[i][j]=max(up[i][j-1],up[i+(1<<(j-1))][j-1]);
        }
}
int rmq(int x,int y,int op)
{
    int k=mm[y-x+1];
    if(op)return min(dp[x][k],dp[y-(1<<k)+1][k]);
    else return max(up[x][k],up[y-(1<<k)+1][k]);
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    initRMQ(n,a);
    int len=0,r=1;
    vector<pair<int,int> >res;
    for(int l=1;l<=n;l++)
    {
        while(r<=n && rmq(l,r,0)-rmq(l,r,1)<=k)r++;
        if(r-l>len)len=r-l,res.clear();
        if(r-l==len)res.push_back(make_pair(l,r-1));
    }
    printf("%d %d\n",len,(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d %d\n",res[i].first,res[i].second);
    return 0;
}