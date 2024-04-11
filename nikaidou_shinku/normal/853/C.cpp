#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
struct BIT
{
    int c[MAXN],n;
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            c[i]=0;
    }
    void update(int p,int v)
    {
        for(int i=p;i<=n;i+=i&-i)
            c[i]+=v;
    }
    int query(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=i&-i)
            res+=c[i];
        return res;
    }
}bit;
struct Event
{
    int x,y,t,c,id;
    bool operator < (const Event &rhs)const
    {
        return (x==rhs.x ? (y==rhs.y ? t<rhs.t : y<rhs.y) : x<rhs.x);
    }
}e[MAXN<<4];
int cnt[MAXN][9];
ll C2(int x)
{
    return 1LL*x*(x-1)/2;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        e[tot++]=Event{i,p,0,0,0};
    }
    for(int i=1;i<=q;i++)
    {
        int l,d,r,u;
        scanf("%d%d%d%d",&l,&d,&r,&u);
        e[tot++]=Event{l-1,d-1,1,0,i};
        e[tot++]=Event{l-1,u,1,1,i};
        e[tot++]=Event{l-1,n,1,2,i};
        e[tot++]=Event{r,d-1,1,3,i};
        e[tot++]=Event{r,u,1,4,i};
        e[tot++]=Event{r,n,1,5,i};
        e[tot++]=Event{n,d-1,1,6,i};
        e[tot++]=Event{n,u,1,7,i};
        e[tot++]=Event{n,n,1,8,i};
    }
    sort(e,e+tot);
    bit.init(n);
    for(int i=0;i<tot;i++)
    {
        if(e[i].t==0)bit.update(e[i].y,1);
        else cnt[e[i].id][e[i].c]=bit.query(e[i].y);
    }
    for(int i=1;i<=q;i++)
    {
        ll res=C2(n);
        res-=C2(cnt[i][2]);
        res-=C2(cnt[i][6]);
        res-=C2(cnt[i][8]-cnt[i][7]);
        res-=C2(cnt[i][8]-cnt[i][5]);
        res+=C2(cnt[i][0]);
        res+=C2(cnt[i][2]-cnt[i][1]);
        res+=C2(cnt[i][6]-cnt[i][3]);
        res+=C2(cnt[i][8]-cnt[i][5]-cnt[i][7]+cnt[i][4]);
        printf("%lld\n",res);
    }
    return 0;
}