#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
const int MAXQ=100005;
struct BIT2D
{
    int n,m,c[MAXN][MAXN];
    void init(int _n,int _m)
    {
        n=_n,m=_m;
        for(int i=1;i<=n;i++)
            memset(c[i]+1,0,m*sizeof(int));
    }
    void update(int x,int y,int v)
    {
        for(int i=x;i<=n;i+=i&-i)
            for(int j=y;j<=m;j+=j&-j)
                c[i][j]+=v;
    }
    int query(int x,int y)
    {
        int res=0;
        for(int i=x;i>0;i-=i&-i)
            for(int j=y;j>0;j-=j&-j)
                res+=c[i][j];
        return res;
    }
}bit;
int ty[MAXQ],dir[MAXQ],x[MAXQ],y[MAXQ],len[MAXQ],res[MAXQ];
struct Event
{
    int x,y,t,id;
    bool operator < (const Event &rhs)const
    {
        return t<rhs.t;
    }
}el[MAXQ],er[MAXQ];
void solve(int l,int r)
{
    if(l==r)return;
    int m=(l+r)/2;
    for(int _=1;_<=4;_++)
    {
        int cl=0,cr=0;
        for(int i=l;i<=m;i++)
        {
            if(dir[i]!=_)continue;
            if(_==1)el[cl++]=Event{x[i],y[i],-x[i]-y[i]-len[i],i};
            if(_==2)el[cl++]=Event{x[i],bit.n+1-y[i],-x[i]+y[i]-len[i],i};
            if(_==3)el[cl++]=Event{bit.n+1-x[i],y[i],x[i]-y[i]-len[i],i};
            if(_==4)el[cl++]=Event{bit.n+1-x[i],bit.n+1-y[i],x[i]+y[i]-len[i],i};
        }
        for(int i=m+1;i<=r;i++)
        {
            if(ty[i]!=2)continue;
            if(_==1)er[cr++]=Event{x[i],y[i],-x[i]-y[i],i};
            if(_==2)er[cr++]=Event{x[i],bit.n+1-y[i],-x[i]+y[i],i};
            if(_==3)er[cr++]=Event{bit.n+1-x[i],y[i],x[i]-y[i],i};
            if(_==4)er[cr++]=Event{bit.n+1-x[i],bit.n+1-y[i],x[i]+y[i],i};
        }
        sort(el,el+cl);
        sort(er,er+cr);
        int p=0;
        for(int i=0;i<cr;i++)
        {
            while(p<cl && el[p].t<=er[i].t)
            {
                bit.update(el[p].x,el[p].y,1);
                p++;
            }
            res[er[i].id]+=bit.query(er[i].x,er[i].y);
        }
        for(int i=0;i<p;i++)
            bit.update(el[i].x,el[i].y,-1);
    }
    solve(l,m);
    solve(m+1,r);
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    bit.init(n,n);
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&ty[i]);
        if(ty[i]==1)scanf("%d%d%d%d",&dir[i],&x[i],&y[i],&len[i]);
        else scanf("%d%d",&x[i],&y[i]);
    }
    solve(1,q);
    for(int i=1;i<=q;i++)
        if(ty[i]==2)printf("%d\n",res[i]);
    return 0;
}