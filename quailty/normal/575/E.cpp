#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double db;
const int MAXN=100005;
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    ll operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    ll operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
    db len()const
    {
        return sqrt(x*x+y*y);
    }
    bool operator < (const Point &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
    bool operator == (const Point &t)const
    {
        return x==t.x && y==t.y;
    }
}p[MAXN<<3];
int Init()
{
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        if(x+v<=100000)p[cnt++]=Point(x+v,y);
        else
        {
            int d=v-(100000-x);
            p[cnt++]=Point(100000,min(y+d,100000));
            p[cnt++]=Point(100000,max(y-d,0));
        }
        if(x-v>=0)p[cnt++]=Point(x-v,y);
        else
        {
            int d=v-x;
            p[cnt++]=Point(0,min(y+d,100000));
            p[cnt++]=Point(0,max(y-d,0));
        }
        if(y+v<=100000)p[cnt++]=Point(x,y+v);
        else
        {
            int d=v-(100000-y);
            p[cnt++]=Point(min(x+d,100000),100000);
            p[cnt++]=Point(max(x-d,0),100000);
        }
        if(y-v>=0)p[cnt++]=Point(x,y-v);
        else
        {
            int d=v-y;
            p[cnt++]=Point(min(x+d,100000),0);
            p[cnt++]=Point(max(x-d,0),0);
        }
    }
    sort(p,p+cnt);
    return unique(p,p+cnt)-p;
}
Point stk[MAXN<<3];
db cal(Point a,Point b,Point c)
{
    b=b-a,c=c-a;
    db len=(b-c).len();
    db arc=acos((b^c)/b.len()/c.len());
    return len/sin(arc);
}
int main()
{
    int n=Init();
    auto cmp=[&](const Point &a,const Point &b)
    {
        if((a-p[0])*(b-p[0]))return (a-p[0])*(b-p[0])>0;
        return ((a-p[0])^(a-p[0]))<((b-p[0])^(b-p[0]));
    };
    sort(p+1,p+n,cmp);
    p[n]=p[0];
    int top=0;
    for(int i=0;i<=n;i++)
    {
        while(top>1 && (p[i]-stk[top-1])*(stk[top-1]-stk[top-2])>=0)top--;
        if(i<n)stk[top++]=p[i];
    }
    db res=0;
    int id=0;
    for(int i=0;i<top;i++)
    {
        db tmp=cal(stk[i],stk[(i+1)%top],stk[(i+2)%top]);
        if(tmp>res)res=tmp,id=i;
    }
    for(int i=0;i<3;i++)
        printf("%lld %lld\n",stk[(id+i)%top].x,stk[(id+i)%top].y);
    return 0;
}