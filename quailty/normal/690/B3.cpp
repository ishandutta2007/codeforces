#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll d[8][2]={{0,1},{-1,0},{0,-1},{1,0},{1,1},{-1,1},{-1,-1},{1,-1}};
const ll t[4][2]={{0,0},{-1,0},{-1,-1},{0,-1}};
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
    ll dis2()
    {
        return x*x+y*y;
    }
    bool operator < (const Point &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
}in[200005],p[800005],stk[800005];
bool cmp(const Point &a,const Point &b)
{
    return (a-p[0])*(b-p[0]) ? (a-p[0])*(b-p[0])<0 : (a-p[0]).dis2()<(b-p[0]).dis2();
}
int Graham(int n)
{
    sort(p,p+n);
    sort(p+1,p+n,cmp);
    int top=0;
    for(int i=0;i<n;i++)
    {
        while(top>1 && (p[i]-stk[top-1])*(stk[top-1]-stk[top-2])<=0)top--;
        stk[top++]=p[i];
    }
    if(top>2)while(top>1 && (p[0]-stk[top-1])*(stk[top-1]-stk[top-2])<=0)top--;
    return top;
}
map<ll,ll>mx,mi;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n+m)
    {
        for(int i=0;i<m;i++)
            scanf("%I64d%I64d",&in[i].x,&in[i].y);
        mx.clear(),mi.clear();
        for(int i=0;i<m;i++)
        {
            mx[in[i].x]=0;
            mi[in[i].x]=n+1;
        }
        for(int i=0;i<m;i++)
        {
            mx[in[i].x]=max(mx[in[i].x],in[i].y);
            mi[in[i].x]=min(mi[in[i].x],in[i].y);
        }
        int tot=0;
        for(int i=0;i<m;i++)
        {
            bool isok[4]={1,1,1,1};
            for(int j=0;j<4;j++)
            {
                int tx=in[i].x+d[j][0];
                int ty=in[i].y+d[j][1];
                if(mx.lower_bound(tx)==mx.end()
                || mx[tx]<ty || mi[tx]>ty)
                    isok[j]=isok[(j+1)%4]=0;
            }
            for(int j=4;j<8;j++)
            {
                int tx=in[i].x+d[j][0];
                int ty=in[i].y+d[j][1];
                if(mx.lower_bound(tx)==mx.end()
                || mx[tx]<ty || mi[tx]>ty)
                    isok[j-4]=0;
            }
            for(int j=0;j<4;j++)if(isok[j])
                p[tot++]=Point(in[i].x+t[j][0],in[i].y+t[j][1]);
        }
        int res=Graham(tot);
        printf("%d\n",res);
        for(int i=0;i<res;i++)
            printf("%I64d %I64d\n",stk[i].x,stk[i].y);
    }
    return 0;
}