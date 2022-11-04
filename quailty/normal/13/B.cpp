#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Point
{
    ll x,y;
    Point(ll _x=0,ll _y=0):x(_x),y(_y){}
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
    bool operator == (const Point &t)const
    {
        return x==t.x && y==t.y;
    }
    void input()
    {
        scanf("%I64d%I64d",&x,&y);
    }
    ll len2()
    {
        return x*x+y*y;
    }
};
struct Line
{
    Point s,e;
    Line(Point _s=Point(0,0),Point _e=Point(0,1)):s(_s),e(_e){}
    void input()
    {
        s.input();
        e.input();
    }
}l[3];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<3;i++)l[i].input();
        int r[3]={-1,-1,-1};
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(i!=j && (l[i].s==l[j].s || l[i].s==l[j].e || l[i].e==l[j].e))
                    r[0]=i,r[1]=j,r[2]=3^i^j;
        if(r[0]<0)
        {
            printf("NO\n");
            continue;
        }
        if(l[r[0]].s==l[r[1]].e)swap(l[r[1]].s,l[r[1]].e);
        if((l[r[0]].s-l[r[0]].e)*(l[r[1]].s-l[r[1]].e)==0
        || ((l[r[0]].s-l[r[0]].e)^(l[r[1]].s-l[r[1]].e))<0)
        {
            printf("NO\n");
            continue;
        }
        bool isok=0;
        for(int i=0;i<2;i++)
        {
            if((l[r[2]].s-l[r[0]].s)*(l[r[2]].s-l[r[0]].e)==0
            && 5*((l[r[2]].s-l[r[0]].s)^(l[r[0]].e-l[r[0]].s))>=(l[r[0]].s-l[r[0]].e).len2()
            && 5*((l[r[2]].s-l[r[0]].s)^(l[r[0]].e-l[r[0]].s))<=4*(l[r[0]].s-l[r[0]].e).len2()
            && (l[r[2]].e-l[r[1]].s)*(l[r[2]].e-l[r[1]].e)==0
            && 5*((l[r[2]].e-l[r[1]].s)^(l[r[1]].e-l[r[1]].s))>=(l[r[1]].s-l[r[1]].e).len2()
            && 5*((l[r[2]].e-l[r[1]].s)^(l[r[1]].e-l[r[1]].s))<=4*(l[r[1]].s-l[r[1]].e).len2())
                isok=1;
            swap(r[0],r[1]);
        }
        printf("%s\n",(isok ? "YES" : "NO"));
    }
    return 0;
}