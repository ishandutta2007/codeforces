#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
struct point
{
    ll x,y;
    void input()
    {
        ll _x,_y;
        scanf("%I64d%I64d",&_x,&_y);
        x=_x; y=_y;
    }
    bool operator == (const point &p) const
    {
        return x==p.x && y==p.y;
    }
    bool operator < (const point &p) const
    {
        return x==p.x ? y<p.y : x<p.x;
    }
}p[2005];
struct line
{
    ll a,b,c;//ax+by+c=0
    bool operator < (const line &l) const
    {
        if(a==l.a)
        {
            if(b==l.b)return c<l.c;
            else return b<l.b;
        }
        else return a<l.a;
    }
};
ll gcd(ll x,ll y)
{
    return y==0 ? x : gcd(y,x%y);
}
bool online(point p,line l)
{
    return l.a*p.x+l.b*p.y+l.c==0;
}
line make_line(point p,point q)
{
    line t;
    t.a=p.y-q.y;
    t.b=q.x-p.x;
    t.c=-t.a*p.x-t.b*p.y;
    if(t.a==0)//by+c=0
    {
        if(t.c==0)t.b=1;
        else
        {
            ll g=gcd(t.b,t.c);
            t.b/=g;
            t.c/=g;
            if(t.b<0)
            {
                t.b=-t.b;
                t.c=-t.c;
            }
        }
    }
    else if(t.b==0)//ax+c=0
    {
        if(t.c==0)t.a=1;
        else
        {
            ll g=gcd(t.a,t.c);
            t.a/=g;
            t.c/=g;
            if(t.a<0)
            {
                t.a=-t.a;
                t.c=-t.c;
            }
        }
    }
    else if(t.c==0)//ax+by=0
    {
        ll g=gcd(t.a,t.b);
        t.a/=g;
        t.b/=g;
        if(t.a<0)
        {
            t.a=-t.a;
            t.b=-t.b;
        }
    }
    else
    {
        ll g=gcd(gcd(t.a,t.b),t.c);
        t.a/=g;
        t.b/=g;
        t.c/=g;
        if(t.a<0)
        {
            t.a=-t.a;
            t.b=-t.b;
            t.c=-t.c;
        }
    }
    return t;
}
ll C[2005];
void build()
{
    for(int i=1;i<=2000;i++)
    {
        C[i]=i*(i-1)/2;
    }
}
map<line,ll>cnt;
int main()
{
    build();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        p[i].input();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            cnt[make_line(p[i],p[j])]++;
        }
    }
    map<line,ll>::iterator itr;
    ll ans=0;
    for(itr=cnt.begin();itr!=cnt.end();itr++)
    {
        int loc=lower_bound(C,C+2001,(*itr).second)-C;
        ans+=(n-loc)*(*itr).second;
    }
    printf("%I64d\n",ans/3);
    return 0;
}