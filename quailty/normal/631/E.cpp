#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll a[MAXN];
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
};
Point p[MAXN],stk[MAXN];
int top;
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        p[i]=Point(i,p[i-1].y+a[i]);
        sum+=i*a[i];
    }
    ll res=0;
    top=0;
    for(int i=n;i>=1;i--)
    {
        while(top>1 && (p[i]-stk[top])*(stk[top]-stk[top-1])<=0)--top;
        stk[++top]=p[i];
        int l=1,r=top;
        while(l<r)
        {
            int m1=(2*l+r)/3;
            int m2=(l+2*r+2)/3;
            if(a[i]*stk[m1].x-stk[m1].y<a[i]*stk[m2].x-stk[m2].y)l=m1+1;
            else r=m2-1;
        }
        res=max(res,a[i]*stk[l].x-stk[l].y+p[i].y-i*a[i]);
    }
    top=0;
    for(int i=1;i<=n;i++)
    {
        while(top>1 && (p[i-1]-stk[top])*(stk[top]-stk[top-1])>=0)--top;
        stk[++top]=p[i-1];
        int l=1,r=top;
        while(l<r)
        {
            int m1=(2*l+r)/3;
            int m2=(l+2*r+2)/3;
            if(a[i]*stk[m1].x-stk[m1].y<a[i]*stk[m2].x-stk[m2].y)l=m1+1;
            else r=m2-1;
        }
        res=max(res,a[i]*stk[l].x-stk[l].y+p[i-1].y-(i-1)*a[i]);
    }
    printf("%I64d",sum+res);
    return 0;
}