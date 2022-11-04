#include<bits/stdc++.h>
using namespace std;

typedef __float128 db;

const int MAXN=10005;

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
    db len()const
    {
        return sqrtl(x*x+y*y);
    }
}p[MAXN],d[MAXN];

struct Complex
{
    db x,y;
    Complex(db x=0.0,db y=0.0):x(x),y(y){}
    Complex operator + (const Complex &t)const
    {
        return Complex(x+t.x,y+t.y);
    }
    Complex operator - (const Complex &t)const
    {
        return Complex(x-t.x,y-t.y);
    }
    Complex operator * (const Complex &t)const
    {
        return Complex(x*t.x-y*t.y,x*t.y+y*t.x);
    }
    Complex operator / (const Complex &t)const
    {
        return Complex((x*t.x+y*t.y)/(t.x*t.x+t.y*t.y),(y*t.x-x*t.y)/(t.x*t.x+t.y*t.y));
    }
};

Point rot(Point o,Point p,Point pre,Point nxt)
{
    Complex z=Complex(o.x,o.y);
    Complex a=Complex(p.x,p.y);
    Complex b=Complex(pre.x,pre.y);
    Complex c=Complex(nxt.x,nxt.y);
    Complex d=(a-z)*(c/b)+z;
    return Point(d.x,d.y);
}

Point solve(Point k,int id)
{
    Complex a=Complex(k.x,k.y);
    Point t=p[1]-p[0];
    Complex b=Complex(t.x,t.y);
    t=p[id]-p[0];
    Complex c=Complex(t.x,t.y);
    Complex d=a*(c/b);
    return Point(d.x,d.y);
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p[i]=Point(x,y);
    }
    Point g=Point(0,0);
    {
        db s=0;
        for(int i=1;i+1<n;i++)
        {
            Point tg=(p[0]+p[i]+p[i+1])/3;
            db ts=(p[i]-p[0])*(p[i+1]-p[0]);
            g=g*(s/(s+ts))+tg*(ts/(s+ts)),s+=ts;
        }
    }
    for(int i=0;i<n;i++)
        d[i]=g-p[i],d[i]=d[i]/d[i].len();
    int a=0,b=1;
    Point key[2]={p[0],p[1]},dir=Point(0,-1);
    while(q--)
    {
        int ty;
        scanf("%d",&ty);
        if(ty==1)
        {
            int f,t;
            scanf("%d%d",&f,&t),f--,t--;
            if(f==b)swap(a,b);
            Point cen=solve(key[1]-key[0],b)+key[0];
            for(int i=0;i<2;i++)
                key[i]=rot(cen,key[i],d[b],dir);
            a=t,dir=d[b];
        }
        else
        {
            int v;
            scanf("%d",&v),v--;
            Point res=solve(key[1]-key[0],v)+key[0];
            printf("%.12f %.12f\n",(double)res.x,(double)res.y);
        }
    }
    return 0;
}