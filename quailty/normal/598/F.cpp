#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

typedef long double db;

const int MAXN=1005;
const db eps=1e-9;

inline int sgn(db x)
{
    if(x>eps)return 1;
    if(x<-eps)return -1;
    return 0;
}

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
    db operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    db len()const
    {
        return sqrt(x*x+y*y);
    }
}p[MAXN];

db solve(Point p[],int n,Point s,Point t)
{
    vector<pair<db,int> >event;
    for(int i=0;i<n;i++)
    {
        int lef=sgn((p[i]-s)*(t-s));
        int rig=sgn((p[(i+1)%n]-s)*(t-s));
        if(lef==rig)continue;
        db r=((p[(i+1)%n]-s)*(p[(i+1)%n]-p[i]))/((t-s)*(p[(i+1)%n]-p[i]));
        event.push_back(make_pair(r,rig-lef));
    }
    sort(event.begin(),event.end());
    int cnt=0;
    db sum=0,la=0;
    for(int i=0;i<(int)event.size();i++)
    {
        if(cnt>0)sum+=event[i].first-la;
        la=event[i].first;
        cnt+=event[i].second;
    }
    return sum*(t-s).len();
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;
    db sum=0;
    for(int i=0;i<n;i++)
        sum+=p[i]*p[(i+1)%n];
    if(sum<0)reverse(p,p+n);
    cout<<fixed<<setprecision(12);
    for(int i=0;i<m;i++)
    {
        Point s,t;
        cin>>s.x>>s.y>>t.x>>t.y;
        cout<<solve(p,n,s,t)<<endl;
    }
    return 0;
}