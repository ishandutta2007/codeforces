#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
};
vector<Point>q[100005];

struct Event
{
    int x,y,op;
    Event(){}
    Event(int _x,int _y,int _op):x(_x),y(_y),op(_op){}
};
Event e[200005];

const int INF=0x3f3f3f3f;
struct BIT
{
    int n,c[605];
    stack<int>stk;
    void init(int tn)
    {
        n=tn;
        for(int i=1;i<=n;i++)c[i]=INF;
    }
    void update(int p,int v)
    {
        stk.push(p);
        for(int i=p;i<=n;i+=i&-i)c[i]=min(c[i],v);
    }
    int query(int p)
    {
        int res=INF;
        for(int i=p;i;i-=i&-i)res=min(res,c[i]);
        return res;
    }
    void reset(int p)
    {
        for(int i=p;i<=n;i+=i&-i)c[i]=INF;
    }
    void reset()
    {
        while(!stk.empty())
        {
            reset(stk.top());
            stk.pop();
        }
    }
}bit;

int dis[305][305];

int main()
{
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int a;
            scanf("%d",&a);
            q[a].push_back(Point(i,j));
        }
    memset(dis,INF,sizeof(dis));
    for(int i=0;i<(int)q[1].size();i++)
    {
        Point v=q[1][i];
        dis[v.x][v.y]=abs(v.x-1)+abs(v.y-1);
    }
    bit.init(m);
    for(int _=1;_<=p-1;_++)
    {
        int tot=0;
        for(int i=0;i<(int)q[_].size();i++)
            e[tot++]=Event(q[_][i].x,q[_][i].y,1);
        for(int i=0;i<(int)q[_+1].size();i++)
            e[tot++]=Event(q[_+1][i].x,q[_+1][i].y,0);
        sort(e,e+tot,[](Event a,Event b){return a.x==b.x ? a.y<b.y : a.x<b.x;});
        for(int i=0;i<tot;i++)
        {
            if(e[i].op)bit.update(e[i].y,dis[e[i].x][e[i].y]-e[i].x-e[i].y);
            else dis[e[i].x][e[i].y]=min(dis[e[i].x][e[i].y],bit.query(e[i].y)+e[i].x+e[i].y);
        }
        bit.reset();
        sort(e,e+tot,[](Event a,Event b){return a.x==b.x ? a.y>b.y : a.x<b.x;});
        for(int i=0;i<tot;i++)
        {
            if(e[i].op)bit.update(m+1-e[i].y,dis[e[i].x][e[i].y]-e[i].x+e[i].y);
            else dis[e[i].x][e[i].y]=min(dis[e[i].x][e[i].y],bit.query(m+1-e[i].y)+e[i].x-e[i].y);
        }
        bit.reset();
        sort(e,e+tot,[](Event a,Event b){return a.x==b.x ? a.y<b.y : a.x>b.x;});
        for(int i=0;i<tot;i++)
        {
            if(e[i].op)bit.update(e[i].y,dis[e[i].x][e[i].y]+e[i].x-e[i].y);
            else dis[e[i].x][e[i].y]=min(dis[e[i].x][e[i].y],bit.query(e[i].y)-e[i].x+e[i].y);
        }
        bit.reset();
        sort(e,e+tot,[](Event a,Event b){return a.x==b.x ? a.y>b.y : a.x>b.x;});
        for(int i=0;i<tot;i++)
        {
            if(e[i].op)bit.update(m+1-e[i].y,dis[e[i].x][e[i].y]+e[i].x+e[i].y);
            else dis[e[i].x][e[i].y]=min(dis[e[i].x][e[i].y],bit.query(m+1-e[i].y)-e[i].x-e[i].y);
        }
        bit.reset();
    }
    return 0*printf("%d",dis[q[p][0].x][q[p][0].y]);
}