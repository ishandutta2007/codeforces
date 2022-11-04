#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=300005;
const ll INF=(1LL<<60)-1;
int ty[MAXN],id[MAXN],q[MAXN],pt;
int l[MAXN],r[MAXN];
ll res[MAXN];
bool hasq[MAXN],hasres[MAXN];
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
        return x==t.x ? y<t.y : x<t.x;
    }
}p[MAXN],stk[MAXN];
int top;
ll query(Point q)
{
    int l=1,r=top;
    while(l<r)
    {
        int m1=(2*l+r)/3;
        int m2=(l+2*r+2)/3;
        if((stk[m1]^q)<(stk[m2]^q))l=m1+1;
        else r=m2-1;
    }
    return (stk[l]^q);
}
vector<Point>s[MAXN<<1];
int getId(int l,int r)
{
    return (l+r)|(l<r);
}
void update(int l,int r,Point &q,int tl,int tr)
{
    int n=getId(tl,tr);
    if(l==tl && r==tr)
    {
        s[n].push_back(q);
        return;
    }
    int tm=(tl+tr)>>1;
    if(r<=tm)update(l,r,q,tl,tm);
    else if(l>tm)update(l,r,q,tm+1,tr);
    else
    {
        update(l,tm,q,tl,tm);
        update(tm+1,r,q,tm+1,tr);
    }
}
void cdq(int l,int r)
{
    int m=(l+r)>>1;
    if(l<r)
    {
        cdq(l,m);
        cdq(m+1,r);
    }
    int n=getId(l,r);
    //sort(s[n].begin(),s[n].end());
    top=0;
    for(int i=0;i<(int)s[n].size();i++)
    {
        while(top>1 && (s[n][i]-stk[top])*(stk[top]-stk[top-1])<=0)--top;
        stk[++top]=s[n][i];
    }
    for(int i=l;i<=r;i++)
        if(hasq[i] && top)
        {
            res[i]=max(res[i],query(Point(q[i],1)));
            hasres[i]=1;
        }
}
int f[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ty[i]);
        if(ty[i]==1)
        {
            pt++;
            id[i]=pt,l[pt]=i,r[pt]=n;
            scanf("%I64d%I64d",&p[pt].x,&p[pt].y);
        }
        else if(ty[i]==2)
        {
            int d;
            scanf("%d",&d);
            r[id[d]]=i-1;
        }
        else
        {
            scanf("%d",&q[i]);
            hasq[i]=1;
        }
    }
    for(int i=1;i<=pt;i++)f[i]=i;
    sort(f+1,f+pt+1,[](int a,int b){return p[a]<p[b];});
    sort(p+1,p+pt+1);
    for(int i=1;i<=pt;i++)
        update(l[f[i]],r[f[i]],p[i],1,n);
    for(int i=1;i<=n;i++)
        res[i]=-INF;
    cdq(1,n);
    for(int i=1;i<=n;i++)
        if(hasq[i])
        {
            if(hasres[i])printf("%I64d\n",res[i]);
            else printf("EMPTY SET\n");
        }
    return 0;
}