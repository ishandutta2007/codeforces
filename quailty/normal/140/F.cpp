#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    bool operator < (const Point &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
    bool operator == (const Point &t)const
    {
        return x==t.x && y==t.y;
    }
}p[MAXN],q[MAXN],t[MAXN];
vector<Point>res;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
    if(k>=n)return 0*printf("-1\n");
    sort(p,p+n);
    for(int i=0;i<n;i++)
        q[i]=Point(-p[i].x,-p[i].y);
    sort(q,q+n);
    for(int i=0;i<=k;i++)
        for(int j=0;j<=k;j++)
        {
            Point v=p[i]-q[j];
            int mis=0;
            for(int _=0;_<n;_++)
                t[_]=q[_]+v;
            for(int l=0,r=0;l<n;l++)
            {
                while(r<n && t[r]<p[l])r++;
                mis+=!(r<n && t[r]==p[l]);
            }
            if(mis<=k)res.push_back(v);
        }
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%.12f %.12f\n",res[i].x/2.0,res[i].y/2.0);
    return 0;
}