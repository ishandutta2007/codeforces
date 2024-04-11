#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2005;
const int MAXQ=1000005;
struct BIT
{
    ll c[MAXN];
    int n;
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)c[i]=0;
    }
    void update(int p,ll v)
    {
        for(int i=p;i<=n;i+=i&-i)c[i]+=v;
    }
    ll query(int p)
    {
        ll res=0;
        for(int i=p;i>0;i-=i&-i)res+=c[i];
        return res;
    }
}bit[MAXN];
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    bool operator < (const Point &t)const
    {
        return x==t.x ? y<t.y : x<t.x;
    }
    bool operator == (const Point &t)const
    {
        return x==t.x && y==t.y;
    }
};
struct Event
{
    Point loc;
    int id,v;
    Event(){}
    Event(Point _loc,int _id,int _v):loc(_loc),id(_id),v(_v){}
    bool operator < (const Event &t)const
    {
        return loc==t.loc ? id<t.id : loc<t.loc;
    }
};
ll in[MAXN][MAXN];
int on[MAXN],ty[MAXQ],id[MAXQ];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<Event>v;
    for(int i=1;i<=k;i++)
    {
        int len;
        scanf("%d",&len);
        for(int j=1;j<=len;j++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            v.push_back(Event(Point(x,y),-i,w));
        }
    }
    int q;
    scanf("%d",&q);
    for(int i=1,j=0;i<=q;i++)
    {
        char op[15];
        scanf("%s",op);
        if(*op=='S')
        {
            ty[i]=0;
            scanf("%d",&id[i]);
        }
        else
        {
            ty[i]=1;
            id[i]=++j;
            int x[2],y[2];
            for(int i=0;i<2;i++)
                scanf("%d%d",&x[i],&y[i]);
            v.push_back(Event(Point(x[0]-1,y[0]-1),j,1));
            v.push_back(Event(Point(x[0]-1,y[1]),j,-1));
            v.push_back(Event(Point(x[1],y[0]-1),j,-1));
            v.push_back(Event(Point(x[1],y[1]),j,1));
        }
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=k;i++)
        bit[i].init(m);
    for(int i=0;i<(int)v.size();i++)
    {
        if(v[i].id<0)
        {
            bit[-v[i].id].update(v[i].loc.y,v[i].v);
        }
        else
        {
            for(int j=1;j<=k;j++)
                in[v[i].id][j]+=v[i].v*bit[j].query(v[i].loc.y);
        }
    }
    for(int i=1;i<=k;i++)
        on[i]=1;
    for(int i=1;i<=q;i++)
    {
        if(!ty[i])on[id[i]]^=1;
        else
        {
            ll res=0;
            for(int j=1;j<=k;j++)
                if(on[j])res+=in[id[i]][j];
            printf("%I64d\n",res);
        }
    }
    return 0;
}