#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-12;
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
struct Circle
{
    Point o;
    db r;
    Circle(Point _o=Point(0,0),db _r=1.0):o(_o),r(_r){}
    bool contain(Point t)
    {
        return sgn((t-o).len()-r)<=0;
    }
}c[3];
int CirCirIntersect(Circle c1,Circle c2,Point &p1,Point &p2)
{
    db d=(c1.o-c2.o).len();
    if(d>c1.r+c2.r+eps)return 0;
    if(d<fabs(c1.r-c2.r)-eps)return 3;
    db dt=(c1.r*c1.r-c2.r*c2.r)/d;
    db d1=(d+dt)/2;
    Point dir=c2.o-c1.o;
    dir=dir.normalize();
    Point pcrs=c1.o+dir*d1;
    dir=dir.rotLeft90();
    dt=sqrt(max(c1.r*c1.r-d1*d1,0.0));
    p1=pcrs+dir*dt;
    p2=pcrs-dir*dt;
    if(sgn((p1-c1.o)*(c2.o-c1.o))<0)swap(p1,p2);
    if(p1==p2)return 1;
    else return 2;
}
int main()
{
    db t[2];
    scanf("%lf%lf",&t[0],&t[1]);
    for(int i=0;i<3;i++)
        scanf("%lf%lf",&c[i].o.x,&c[i].o.y);
    t[0]+=(c[0].o-c[2].o).len();
    t[1]+=(c[0].o-c[1].o).len();
    db l=0,r=min(t[0],t[1]);
    for(int _=0;_<100;_++)
    {
        db m=(l+r)/2;
        c[0].r=m;
        c[1].r=t[1]-m;
        c[2].r=t[0]-m;
        Point p[6];
        int rem=-1;
        bool epty=0;
        for(int i=0;i<3;i++)
        {
            int ty=CirCirIntersect(c[i],c[(i+1)%3],p[i*2],p[i*2+1]);
            if(!ty)epty=1;
            if(ty==3)rem=(i+2)%3;
        }
        if(epty)
        {
            r=m;
            continue;
        }
        bool isok=0;
        if(rem==-1)
        {
            for(int i=0;i<6;i++)
            {
                bool flag=1;
                for(int j=0;j<3;j++)
                    if(!c[j].contain(p[i]))flag=0;
                isok|=flag;
            }
        }
        else
        {
            isok=1;
            for(int i=0;i<3;i++)
                if(!CirCirIntersect(c[rem],c[i],p[0],p[1]))isok=0;
        }
        if(isok)l=m;
        else r=m;
    }
    db res=(l+r)/2;
    if(t[1]>(c[0].o-c[2].o).len()+(c[2].o-c[1].o).len()-eps)
        res=max(res,min(t[0]+(c[2].o-c[1].o).len(),t[1]));
    printf("%.10f",res);
    return 0;
}