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
const db eps=1e-12;
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
}p[MAXN],q[MAXN];
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
bool checkRed(int c,int n,int m,db r)
{
    e.clear();
    for(int i=0;i<m;i++)
    {
        db d=(q[i]-p[c]).len();
        if(d>2*r-eps)continue;
        db t=(q[i]-p[c]).arc();
        db x=acos(d/(2*r));
        add(t-x,t+x,1);
    }
    sort(e.begin(),e.end());
    db tot=0,la=0;
    int cnt=0;
    for(int i=0;i<(int)e.size();i++)
    {
        if(cnt>0)tot+=e[i].first-la;
        cnt+=e[i].second;
        la=e[i].first;
    }
    return (tot<2*PI-eps);
}
bool checkBlue(int c,int n,int m,db r)
{
    e.clear();
    for(int i=0;i<n;i++)
    {
        db d=(p[i]-q[c]).len();
        if(d>2*r-eps)continue;
        db t=(p[i]-q[c]).arc();
        db x=acos(d/(2*r));
        add(t-x,t+x,1);
    }
    for(int i=0;i<m;i++)
    {
        if(i==c)continue;
        db d=(q[i]-q[c]).len();
        if(d>2*r-eps)continue;
        db t=(q[i]-q[c]).arc();
        db x=acos(d/(2*r));
        add(t-x,t+x,2);
    }
    sort(e.begin(),e.end());
    db tot=0,la=0;
    int cnt=0,dep=0;
    for(int i=0;i<(int)e.size();i++)
    {
        if(dep==0 && cnt>0)tot+=e[i].first-la;
        cnt+=e[i].second;
        dep+=e[i].second/2;
        la=e[i].first;
    }
    return (tot>eps);
}
bool check(int n,int m,db r)
{
    for(int i=0;i<n;i++)
        if(checkRed(i,n,m,r))return 1;
    for(int i=0;i<m;i++)
        if(checkBlue(i,n,m,r))return 1;
    return 0;
}
int main()
{
    srand(time(NULL));
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    for(int i=0;i<m;i++)
        scanf("%lf%lf",&q[i].x,&q[i].y);
    random_shuffle(p,p+n);
    random_shuffle(q,q+m);
    if(check(n,m,1e11))return 0*printf("-1");
    db res=1;
    for(int i=0;i<n;i++)
    {
        if(!checkRed(i,n,m,res))continue;
        db tmp=1;
        while(checkRed(i,n,m,res+tmp))tmp*=2;
        db tl=res,tr=res+tmp;
        for(int _=0;_<60;_++)
        {
            db tm=(tl+tr)/2;
            if(checkRed(i,n,m,tm))tl=tm;
            else tr=tm;
        }
        res=(tl+tr)/2;
    }
    for(int i=0;i<m;i++)
    {
        if(!checkBlue(i,n,m,res))continue;
        db tmp=1;
        while(checkBlue(i,n,m,res+tmp))tmp*=2;
        db tl=res,tr=res+tmp;
        for(int _=0;_<60;_++)
        {
            db tm=(tl+tr)/2;
            if(checkBlue(i,n,m,tm))tl=tm;
            else tr=tm;
        }
        res=(tl+tr)/2;
    }
    return 0*printf("%.6f",res);
}