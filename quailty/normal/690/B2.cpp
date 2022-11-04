#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    int operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    int dis2()
    {
        return x*x+y*y;
    }
    bool operator < (const Point &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
}p[1005],stk[1005];
bool cmp(const Point &a,const Point &b)
{
    return (a-p[0])*(b-p[0]) ? (a-p[0])*(b-p[0])<0 : (a-p[0]).dis2()<(b-p[0]).dis2();
}
bool isok[505][505];
char s[505][505];
int mx[505],mi[505];
int Graham(int n)
{
    sort(p,p+n);
    sort(p+1,p+n,cmp);
    int top=0;
    for(int i=0;i<n;i++)
    {
        while(top>1 && (p[i]-stk[top-1])*(stk[top-1]-stk[top-2])<=0)top--;
        stk[top++]=p[i];
    }
    if(top>2)while(top>1 && (p[0]-stk[top-1])*(stk[top-1]-stk[top-2])<=0)top--;
    return top;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                isok[i][j]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(s[i][j]!='0')continue;
                for(int p=-1;p<=0;p++)
                    for(int q=-1;q<=0;q++)
                        isok[i+p][j+q]=0;
            }
        for(int i=0;i<=n;i++)
            mx[i]=-1,mi[i]=n+1;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(isok[n-j][i])
                {
                    mx[i]=max(mx[i],j);
                    mi[i]=min(mi[i],j);
                }
        int tot=0;
        for(int i=0;i<=n;i++)
        {
            if(mx[i]<0)continue;
            p[tot++]=Point(i,mx[i]);
            if(mi[i]<mx[i])p[tot++]=Point(i,mi[i]);
        }
        int res=Graham(tot);
        printf("%d\n",res);
        for(int i=0;i<res;i++)
            printf("%d %d\n",stk[i].x,stk[i].y);
    }
    return 0;
}