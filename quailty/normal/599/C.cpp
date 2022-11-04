#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
int h[MAXN];
int ma[MAXN][20],mi[MAXN][20];
int mm[MAXN];
void initRMQ(int n,int b[])
{
    mm[0]=-1;
    mi[0][0]=INF;
    for(int i=1;i<=n;i++)
    {
        mm[i]=((i&(i-1))==0) ? mm[i-1]+1 : mm[i-1];
        ma[i][0]=mi[i][0]=b[i];
    }
    for(int j=1;j<=mm[n];j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
            mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
        }
}
int get_ma(int x,int y)
{
    int k=mm[y-x+1];
    return max(ma[x][k],ma[y-(1<<k)+1][k]);
}
int get_mi(int x,int y)
{
    int k=mm[y-x+1];
    return min(mi[x][k],mi[y-(1<<k)+1][k]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    initRMQ(n,h);
    int res=1,la=1;
    for(int i=1;i<n;i++)
        if(get_ma(la,i)<=get_mi(i+1,n))
        {
            res++;
            la=i+1;
        }
    printf("%d\n",res);
    return 0;
}