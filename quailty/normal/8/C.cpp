#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=24;
const int INF=0x3f3f3f3f;
int dp[1<<MAXN];
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    int dis2()
    {
        return x*x+y*y;
    }
}p[MAXN+5],pre[1<<MAXN];
int main()
{
    int tx,ty;
    scanf("%d%d",&tx,&ty);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].x-=tx,p[i].y-=ty;
    }
    memset(dp,INF,sizeof(dp));
    dp[0]=0;
    for(int mask=0;mask<(1<<n);mask++)
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i))continue;
            if(dp[mask|(1<<i)]>dp[mask]+2*p[i].dis2())
            {
                dp[mask|(1<<i)]=dp[mask]+2*p[i].dis2();
                pre[mask|(1<<i)]=Point(i,-1);
            }
            for(int j=i+1;j<n;j++)
            {
                if(mask&(1<<j))continue;
                if(dp[mask|(1<<i)|(1<<j)]>dp[mask]+p[i].dis2()+p[j].dis2()+(p[i]-p[j]).dis2())
                {
                    dp[mask|(1<<i)|(1<<j)]=dp[mask]+p[i].dis2()+p[j].dis2()+(p[i]-p[j]).dis2();
                    pre[mask|(1<<i)|(1<<j)]=Point(i,j);
                }
            }
            break;
        }
    int now=(1<<n)-1;
    printf("%d\n",dp[now]);
    printf("0 ");
    while(now)
    {
        int p=pre[now].x,q=pre[now].y;
        printf("%d ",p+1);
        if(q>=0)printf("%d ",q+1);
        printf("0 ");
        now^=(1<<p);
        if(q>=0)now^=(1<<q);
    }
    return 0;
}