#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int l[105],r[105];
int cal(int x,int yl,int yr,int c)
{
    int res=0;
    for(int y=yl;y<=yr;y++)
        res+=abs(x-c)+abs(y-c);
    return res;
}
void work(int m,int k)
{
    int mi=INF,x,yl,yr;
    for(int i=1;i<=k;i++)
    {
        if(!r[i])
        {
            int t=cal(  i,(k-m)/2+1,(k+m)/2,(k+1)/2);
            if(t<mi)mi=t,x=i,yl=(k-m)/2+1,yr=(k+m)/2;
        }
        else
        {
            if(l[i]>=m+1)
            {
                int t=cal(i,l[i]-m,l[i]-1,(k+1)/2);
                if(t<mi)mi=t,x=i,yl=l[i]-m,yr=l[i]-1;
            }
            if(r[i]<=k-m)
            {
                int t=cal(i,r[i]+1,r[i]+m,(k+1)/2);
                if(t<mi)mi=t,x=i,yl=r[i]+1,yr=r[i]+m;
            }
        }
    }
    if(mi==INF)printf("-1\n");
    else
    {
        printf("%d %d %d\n",x,yl,yr);
        l[x]=min(l[x],yl);
        r[x]=max(r[x],yr);
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        l[i]=k+1,r[i]=0;
    for(int i=1;i<=n;i++)
    {
        int m;
        scanf("%d",&m);
        work(m,k);
    }
    return 0;
}