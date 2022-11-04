#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-8;
int sgn(db x)
{
    if(x>eps)return 1;
    if(x<-eps)return -1;
    return 0;
}
struct Point
{
    db x,y;
    Point(db _x=0,db _y=0):x(_x),y(_y){}
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
    bool operator == (const Point &t)const
    {
        return sgn(x-t.x)==0 && sgn(y-t.y)==0;
    }
    Point normalize()
    {
        return Point(x/len(),y/len());
    }
    Point rotLeft90()
    {
        return Point(-y,x);
    }
    db len()
    {
        return sqrt(x*x+y*y);
    }
};
struct Line
{
    db a,b,c;
    Line(db _a=1,db _b=0,db _c=0):a(_a),b(_b),c(_c){}
}l[2];
bool LineLineIntersect(Line l1,Line l2,Point &p)
{
    db crs=l1.a*l2.b-l2.a*l1.b;
    if(sgn(crs)==0)return 0;
    p.x=(l1.b*l2.c-l1.c*l2.b)/crs;
    p.y=(l2.a*l1.c-l1.a*l2.c)/crs;
    return 1;
}
struct Circle
{
    Point o;
    db r;
    Circle(Point _o=Point(0,0),db _r=1.0):o(_o),r(_r){}
}c[3],t[2];
int CirCirIntersect(Circle c1,Circle c2,Point &p1,Point &p2)
{
    db d=(c1.o-c2.o).len();
    if(d>c1.r+c2.r+eps || d<fabs(c1.r-c2.r)-eps)return 0;
    if(fabs(d)<eps)return 3;
    db dt=(c1.r*c1.r-c2.r*c2.r)/d;
    db d1=(d+dt)/2;
    Point dir=c2.o-c1.o;
    dir=dir.normalize();
    Point pcrs=c1.o+dir*d1;
    dir=dir.rotLeft90();
    dt=sqrt(c1.r*c1.r-d1*d1);
    p1=pcrs+dir*dt;
    p2=pcrs-dir*dt;
    if(sgn((p1-c1.o)*(c2.o-c1.o))<0)swap(p1,p2);
    if(p1==p2)return 1;
    else return 2;
}
int main()
{
    for(int i=0;i<3;i++)
        scanf("%lf%lf%lf",&c[i].o.x,&c[i].o.y,&c[i].r);
    bool isok=0;
    for(int i=0;i<3;i++)
        for(int j=i+1;j<3;j++)
            if(sgn(c[i].r-c[j].r)!=0)isok=1;
    Point p[2];
    if(!isok)
    {
        for(int i=0;i<3;i++)
            l[i]=Line(2*c[i+1].o.x-2*c[i].o.x,2*c[i+1].o.y-2*c[i].o.y,
                      c[i].o.x*c[i].o.x+c[i].o.y*c[i].o.y-c[i+1].o.x*c[i+1].o.x-c[i+1].o.y*c[i+1].o.y);
        if(LineLineIntersect(l[0],l[1],p[0]))printf("%.5f %.5f",p[0].x,p[0].y);
    }
    else
    {
        int s[3]={0,0,0};
        for(int i=0;i<3;i++)
            for(int j=i+1;j<3;j++)
                if(sgn(c[i].r-c[j].r)==0)
                    s[0]=i,s[1]=j;
        if(s[0]!=s[1])s[2]=3-s[0]-s[1];
        else s[0]=0,s[1]=1,s[2]=2;
        for(int i=0;i<2;i++)
        {
            bool flag=0;
            if(sgn(c[s[2]].r-c[s[i]].r)<0)flag=1,swap(c[s[2]],c[s[i]]);
            Point dir=c[s[i]].o-c[s[2]].o,q[2];
            q[0]=c[s[2]].o+dir*c[s[2]].r/(c[s[2]].r+c[s[i]].r);
            q[1]=c[s[2]].o+dir*c[s[2]].r/(c[s[2]].r-c[s[i]].r);
            t[i]=Circle((q[0]+q[1])/2,(q[1]-q[0]).len()/2);
            if(flag)swap(c[s[2]],c[s[i]]);
        }
        if(CirCirIntersect(t[0],t[1],p[0],p[1]))
        {
            if(sgn((p[0]-c[0].o).len()-(p[1]-c[0].o).len())<0)printf("%.5f %.5f",p[0].x,p[0].y);
            else printf("%.5f %.5f",p[1].x,p[1].y);
        }
    }
    return 0;
}