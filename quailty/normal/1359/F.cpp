#pragma GCC optimize("Ofast")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC target("fma","avx2")
// #pragma GCC target("xop","fma4")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"

#include <bits/stdc++.h>
using namespace std;

typedef double db;

const db eps=1e-9;
inline int sgn(db x)
{
    if(x>eps)return 1;
    if(x<-eps)return -1;
    return 0;
}

const int MAXN=25005;

struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    Point operator * (const db &t)const
    {
        return Point(x*t,y*t);
    }
    Point operator / (const db &t)const
    {
        return Point(x/t,y/t);
    }
    db operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    db operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
    db len()
    {
        return sqrt(x*x+y*y);
    }
    Point norm()
    {
        return (*this)/len();
    }
}d[MAXN];

struct Line
{
    Point s,e;
}l[MAXN];

db v[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&l[i].s.x,&l[i].s.y);
        scanf("%lf%lf",&d[i].x,&d[i].y);
        scanf("%lf",&v[i]);
        d[i]=d[i].norm();
        l[i].e=l[i].s+d[i];
    }
    db res=1e100;
    Point p;
    for(register int i=0;i<n;i++)
        for(register int j=i+1;j<n;j++)
        {
            if(sgn(d[i]*d[j])==0)
            {
                p=l[j].s-l[i].s;
                if(sgn(p*d[i])!=0)continue;
                register db dis=p^d[i];
                register db vl=max(sgn(dis)*v[i],0.0);
                register db vr=max(-sgn(p^d[j])*v[j],0.0);
                if(sgn(vl+vr)==0)continue;
                res=min(res,abs(dis)/(vl+vr));
            }
            else
            {
                register db d1=((l[j].s-l[i].s)*d[j])/(d[i]*d[j]);
                register db d2=(l[i].s+d[i]*d1-l[j].s)^d[j];
                if(sgn(d1)<0 || sgn(d2)<0)continue;
                res=min(res,max(d1/v[i],d2/v[j]));
            }
        }
    if(res<1e50)printf("%.12f\n",res);
    else printf("No show :(\n");
    return 0;
}