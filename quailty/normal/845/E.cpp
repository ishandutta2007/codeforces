#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=505;
int x[MAXN],y[MAXN];
struct Event
{
    int l,r,y,t;
    bool operator < (const Event &rhs)const
    {
        return (y==rhs.y ? t>rhs.t : y<rhs.y);
    }
}e[MAXN<<1];
int xx[MAXN<<4],cov[MAXN<<4];
bool check(int n,int m,int k,int r)
{
    int mx[2],mi[2];
    for(int _=0;_<2;_++)
    {
        int cnt=0;
        xx[cnt++]=1;
        xx[cnt++]=n;
        for(int i=0;i<k;i++)
        {
            e[i<<1]=Event{max(1,x[i]-r),min(n,x[i]+r),max(1,y[i]-r),1};
            e[i<<1|1]=Event{max(1,x[i]-r),min(n,x[i]+r),min(m+1,y[i]+r+1),-1};
            xx[cnt++]=e[i<<1].l;
            if(e[i<<1].l-1>=1)xx[cnt++]=e[i<<1].l-1;
            if(e[i<<1].l+1<=n)xx[cnt++]=e[i<<1].l+1;
            xx[cnt++]=e[i<<1].r;
            if(e[i<<1].r-1>=1)xx[cnt++]=e[i<<1].r-1;
            if(e[i<<1].r+1<=n)xx[cnt++]=e[i<<1].r+1;
            xx[cnt++]=e[i<<1|1].l;
            if(e[i<<1|1].l-1>=1)xx[cnt++]=e[i<<1|1].l-1;
            if(e[i<<1|1].l+1<=n)xx[cnt++]=e[i<<1|1].l+1;
            xx[cnt++]=e[i<<1|1].r;
            if(e[i<<1|1].r-1>=1)xx[cnt++]=e[i<<1|1].r-1;
            if(e[i<<1|1].r+1<=n)xx[cnt++]=e[i<<1|1].r+1;
        }
        sort(xx,xx+cnt);
        cnt=unique(xx,xx+cnt)-xx;
        for(int i=0;i<2*k;i++)
        {
            e[i].l=lower_bound(xx,xx+cnt,e[i].l)-xx;
            e[i].r=lower_bound(xx,xx+cnt,e[i].r)-xx;
        }
        for(int i=0;i<cnt;i++)cov[i]=0;
        sort(e,e+2*k);
        mx[_]=xx[0],mi[_]=xx[cnt-1];
        if(e[0].y>1)mx[_]=xx[cnt-1],mi[_]=xx[0];
        for(int l=0,r=0;l<2*k && e[l].y<=m;l=r)
        {
            while(r<2*k && e[l].y==e[r].y)r++;
            for(int i=l;i<r;i++)
                for(int j=e[i].l;j<=e[i].r;j++)
                    cov[j]+=e[i].t;
            for(int i=0;i<cnt;i++)if(!cov[i])
                mx[_]=max(mx[_],xx[i]),mi[_]=min(mi[_],xx[i]);
        }
        for(int i=0;i<k;i++)
            swap(x[i],y[i]);
        swap(n,m);
    }
    return mx[0]-mi[0]+1<=2*r+1 && mx[1]-mi[1]+1<=2*r+1;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
        scanf("%d%d",&x[i],&y[i]);
    int tl=0,tr=1000000000;
    while(tl<tr)
    {
        int tm=(tl+tr)/2;
        if(check(n,m,k,tm))tr=tm;
        else tl=tm+1;
    }
    return 0*printf("%d\n",tl);
}