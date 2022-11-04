#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=1005;
const db PI=acos(-1.0);
const db eps=1e-9;
struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    db len()
    {
        return sqrt(x*x+y*y);
    }
    db arc()
    {
        db t=atan2(y,x);
        if(t<0)t+=2*PI;
        return t;
    }

}p[MAXN];
vector<pair<db,int> >e;
void add(db l,db r,int ty)
{
    if(l<0)
    {
        e.push_back(make_pair(l+2*PI,ty));
        e.push_back(make_pair(2*PI,-ty));
        e.push_back(make_pair(0,ty));
        e.push_back(make_pair(r,-ty));
    }
    else if(r>2*PI)
    {
        e.push_back(make_pair(l,ty));
        e.push_back(make_pair(2*PI,-ty));
        e.push_back(make_pair(0,ty));
        e.push_back(make_pair(r-2*PI,-ty));
    }
    else
    {
        e.push_back(make_pair(l,ty));
        e.push_back(make_pair(r,-ty));
    }
}
bool check(int c,int n,db w,db h,db r)
{
    e.clear();
    for(int i=0;i<n;i++)
    {
        if(i==c)continue;
        db d=(p[i]-p[c]).len();
        if(d>2*r-eps || d<eps)continue;
        db t=(p[i]-p[c]).arc();
        db x=acos(d/(2*r));
        add(t-x,t+x,1);
    }
    {
        db d=w-p[c].x,t=0;
        if(d<r-eps)
        {
            db x=acos(d/r);
            add(t-x,t+x,2);
        }
        d=p[c].x,t=PI;
        if(d<r-eps)
        {
            db x=acos(d/r);
            add(t-x,t+x,2);
        }
        d=h-p[c].y,t=PI/2;
        if(d<r-eps)
        {
            db x=acos(d/r);
            add(t-x,t+x,2);
        }
        d=p[c].y,t=PI/2*3;
        if(d<r-eps)
        {
            db x=acos(d/r);
            add(t-x,t+x,2);
        }
    }
    sort(e.begin(),e.end());
    db tot=0,la=0;
    int cnt=0,dep=0;
    for(int i=0;i<(int)e.size();i++)
    {
        if(dep>0 || cnt>1)tot+=e[i].first-la;
        cnt+=e[i].second;
        dep+=e[i].second/2;
        la=e[i].first;
    }
    return (tot<2*PI-eps);
}
int main()
{
    srand(time(NULL));
    db w,h;
    int n;
    scanf("%lf%lf%d",&w,&h,&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    random_shuffle(p,p+n);
    db res=0;
    for(int i=0;i<n;i++)
    {
        if(!check(i,n,w,h,res+eps))continue;
        db tmp=1;
        while(check(i,n,w,h,res+tmp))tmp*=2;
        db tl=res,tr=res+tmp;
        for(int _=0;_<60;_++)
        {
            db tm=(tl+tr)/2;
            if(check(i,n,w,h,tm))tl=tm;
            else tr=tm;
        }
        res=(tl+tr)/2;
    }
    return 0*printf("%.12f",res);
}