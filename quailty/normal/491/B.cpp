#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int INF=0x7fffffff;
int N,M,C,H;
struct point
{
    int x,y;
    point(int _x=0,int _y=0):x(_x),y(_y){}
}h[MAXN],r[MAXN];
int a[MAXN],b[MAXN];
int main()
{
    scanf("%d%d%d",&N,&M,&C);
    for(int i=1;i<=C;i++)
    {
        scanf("%d%d",&h[i].x,&h[i].y);
        a[i]=h[i].x+h[i].y;
        b[i]=h[i].x-h[i].y;
    }
    sort(a+1,a+1+C);
    sort(b+1,b+1+C);
    scanf("%d",&H);
    int loc=0,ans=INF;
    for(int i=1;i<=H;i++)
    {
        scanf("%d%d",&r[i].x,&r[i].y);
        int t1=max(abs(r[i].x+r[i].y-a[1]),abs(r[i].x+r[i].y-a[C]));
        int t2=max(abs(r[i].x-r[i].y-b[1]),abs(r[i].x-r[i].y-b[C]));
        int t=max(t1,t2);
        if(ans>t)
        {
            ans=t;
            loc=i;
        }
    }
    printf("%d\n%d\n",ans,loc);
    return 0;
}