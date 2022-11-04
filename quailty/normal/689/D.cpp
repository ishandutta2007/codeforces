#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int mm[MAXN];
struct ST
{
    int dp[MAXN][20],ty;
    void build(int n,int b[],int _ty)
    {
        ty=_ty;
        for(int i=1;i<=n;i++)
            dp[i][0]=ty*b[i];
        for(int j=1;j<=mm[n];j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    }
    int query(int x,int y)
    {
        int k=mm[y-x+1];
        return ty*max(dp[x][k],dp[y-(1<<k)+1][k]);
    }
}rmq_a,rmq_b;
int a[MAXN],b[MAXN];
int main()
{
    for(int i=-(mm[0]=-1);i<MAXN;i++)
        mm[i]=mm[i-1]+((i&(i-1))==0);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    rmq_a.build(n,a,1);
    rmq_b.build(n,b,-1);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n+1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(rmq_a.query(i,m)>=rmq_b.query(i,m))r=m;
            else l=m+1;
        }
        res-=l;
        l=i,r=n+1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(rmq_a.query(i,m)>rmq_b.query(i,m))r=m;
            else l=m+1;
        }
        res+=l;
    }
    return 0*printf("%I64d",res);
}