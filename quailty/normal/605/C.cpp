#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef double db;
const int MAXN=100005;
int sgn(ll x)
{
    if(x>0)return 1;
    if(x<0)return -1;
    return 0;
}
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
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
    bool operator < (const Point &t)const
    {
        return (*this)*t==0 ? ((*this)^(*this))<(t^t) : (*this)*t>0;
    }
}p[MAXN<<2];
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e):s(_s),e(_e){}
};
bool seg_inter_line(Line l1,Line l2)
{
    return sgn((l2.s-l1.e)*(l1.s-l1.e))*sgn((l2.e-l1.e)*(l1.s-l1.e))<=0;
}
Point stk[MAXN<<2];
int top;
void solve(int n,Point tar)
{
    sort(p+1,p+n);
    p[n]=p[0];
    stk[++top]=p[0];
    for(int i=1;i<=n;i++)
    {
        while(top>1 && (stk[top]-stk[top-1])*(p[i]-stk[top])<=0)--top;
        stk[++top]=p[i];
    }
    db res=1e10;
    for(int i=2;i<top-1;i++)
        if(seg_inter_line(Line(stk[1],tar),Line(stk[i],stk[i+1])))
        {
            ll s1=(tar-stk[i])*(stk[i+1]-stk[i]);
            ll s2=stk[i]*stk[i+1];
            res=min(res,(s1+s2+0.0)/s2);
        }
    printf("%.10f\n",res);
}
int main()
{
    int n;
    Point t;
    scanf("%d%I64d%I64d",&n,&t.x,&t.y);
    int tot=0;
    p[tot++]=Point(0,0);
    for(int i=1;i<=n;i++)
    {
        ll x,y;
        scanf("%I64d%I64d",&x,&y);
        p[tot++]=Point(0,y);
        p[tot++]=Point(x,0);
        p[tot++]=Point(x,y);
    }
    solve(tot,t);
    return 0;
}