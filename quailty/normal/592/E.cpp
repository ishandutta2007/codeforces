#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=345678+5;
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
    bool operator < (const Point &t)const
    {
        bool up[2]={0,0};
        if(y>0 || (y==0 && x>0))up[0]=1;
        if(t.y>0 || (t.y==0 && t.x>0))up[1]=1;
        if(up[0]^up[1])return up[0];
        else return (*this)*t>0;
    }
}p[MAXN*3];
int main()
{
    int n;
    ll c,d;
    scanf("%d%I64d%I64d",&n,&c,&d);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
        p[i].x-=c,p[i].y-=d;
    }
    sort(p,p+n);
    for(int i=n;i<3*n;i++)
        p[i]=p[i-n];
    ll res=0,now=0;
    int p0=0,p1=0,p2=0,p3=0,p4=0;
    for(int i=0;i<n;i=p4)
    {
        while(p4<i+n && (p4<=i || (p[p4]*p[i]==0 && (p[p4]^p[i])>0)))p4++;
        p0=p1;
        while(p1<i+n && (p1<=i || (p[p1]*p[i]<0 || (p[p1]*p[i]==0 && (p[p1]^p[i])>0))))p1++;
        now-=1LL*(p0-i)*(p1-p2);
        while(p2<i+n && (p2<=i || p[p2]*p[i]<=0))p2++;
        now-=1LL*max(0,p0-i-(p4-i))*(p2-p1);
        for(int j=p0;j<p1;j++)
        {
            while(p3<j+n && (p3<=j || p[p3]*p[j]<0))p3++;
            now+=1LL*max(0,p3-p2);
        }
        res+=(p4-i)*now;
    }
    return 0*printf("%I64d",res/3);
}