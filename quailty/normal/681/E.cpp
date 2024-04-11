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
const db PI=acos(-1.0);
const db eps=1e-8;
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    ll len2()
    {
        return x*x+y*y;
    }
    db ang()
    {
        db t=atan2(y,x);
        if(t<0)t+=2*PI;
        return t;
    }
}p[MAXN],o[MAXN];
ll v,T,r[MAXN];
vector<pair<db,int> >e;
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&p[0].x,&p[0].y,&v,&T);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d%I64d%I64d",&p[i].x,&p[i].y,&r[i]);
    for(int i=1;i<=n;i++)
        p[i]=p[i]-p[0];
    for(int i=1;i<=n;i++)
        if(p[i].len2()<=r[i]*r[i])
            return 0*printf("1.00000000000");
    for(int i=1;i<=n;i++)
    {
        db a=min(1.0*v*T,sqrt(p[i].len2()-r[i]*r[i]));
        if(a+r[i]-eps<sqrt(p[i].len2()))continue;
        db x=p[i].ang(),b=sqrt(p[i].len2()),c=r[i];
        db t=acos((a*a+b*b-c*c)/(2*a*b));
        if(x+t>2*PI)
        {
            e.push_back(make_pair(0,-1));
            e.push_back(make_pair(x+t-2*PI,1));
            e.push_back(make_pair(x-t,-1));
            e.push_back(make_pair(2*PI,1));
        }
        else if(x-t<0)
        {
            e.push_back(make_pair(x-t+2*PI,-1));
            e.push_back(make_pair(2*PI,1));
            e.push_back(make_pair(0,-1));
            e.push_back(make_pair(x+t,1));
        }
        else
        {
            e.push_back(make_pair(x-t,-1));
            e.push_back(make_pair(x+t,1));
        }
    }
    sort(e.begin(),e.end());
    int cnt=0;
    db res=0,la=0;
    for(int i=0;i<(int)e.size();i++)
    {
        if(cnt)res+=e[i].first-la;
        la=e[i].first;
        cnt-=e[i].second;
    }
    printf("%.10f\n",(double)(res/(2*PI)));
    return 0;
}