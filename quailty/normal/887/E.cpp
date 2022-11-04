#include<bits/stdc++.h>
using namespace std;

typedef long double db;

const db eps=1e-9;

db read_ldb()
{
    double t;
    scanf("%lf",&t);
    return t;
}

const int MAXN=100005;

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
    db operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
    db len()const
    {
        return sqrt(x*x+y*y);
    }
    Point rot_left90()const
    {
        return Point(-y,x);
    }
    Point normal()const
    {
        return (*this)/len();
    }
    void read()
    {
        x=read_ldb();
        y=read_ldb();
    }
}P[MAXN];

db R[MAXN];

int main()
{
    Point A,B,C,D;
    A.read(),B.read();
    C=(A+B)/2,D=(B-A).rot_left90().normal();
    db h=((B-A)/2).len();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        P[i].read(),R[i]=read_ldb();
    db res=1e12;
    for(int _=0;_<2;_++)
    {
        vector<pair<db,db> > seg;
        for(int i=0;i<n;i++)
        {
            pair<db,db> cov;
            if(((P[i]-A)^D)>0)
            {
                db tl=0,tr=1e12;
                for(int b=0;b<100;b++)
                {
                    db tm=(tl+tr)/2;
                    if(sqrt(h*h+tm*tm)+R[i]<(C+D*tm-P[i]).len())tl=tm;
                    else tr=tm;
                }
                cov.first=(tl+tr)/2;
                tl=0,tr=1e12;
                for(int b=0;b<100;b++)
                {
                    db tm=(tl+tr)/2;
                    if(sqrt(h*h+tm*tm)<(C+D*tm-P[i]).len()+R[i])tl=tm;
                    else tr=tm;
                }
                cov.second=(tl+tr)/2;
            }
            else
            {
                db tl=-1,tr=1e12;
                for(int b=0;b<100;b++)
                {
                    db tm=(tl+tr)/2;
                    if(sqrt(h*h+tm*tm)<(C+D*tm-P[i]).len()+R[i])tr=tm;
                    else tl=tm;
                }
                cov.first=(tl+tr)/2;
                tl=-1,tr=1e12;
                for(int b=0;b<100;b++)
                {
                    db tm=(tl+tr)/2;
                    if(sqrt(h*h+tm*tm)+R[i]<(C+D*tm-P[i]).len())tr=tm;
                    else tl=tm;
                }
                cov.second=(tl+tr)/2;
            }
            seg.push_back(cov);
        }
        seg.push_back({1e12,1e12});
        db pre=0;
        sort(seg.begin(),seg.end());
        for(int i=0;i<(int)seg.size();i++)
        {
            db now=seg[i].first;
            if(now>pre+eps)
            {
                res=min(res,sqrt(h*h+pre*pre));
                break;
            }
            pre=max(pre,seg[i].second);
        }
        D=Point(0,0)-D;
    }
    printf("%.12f\n",(double)res);
    return 0;
}