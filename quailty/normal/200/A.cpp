#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef short int sint;
const int MAXN=2005;
const int INF=0x3f3f3f3f;
inline int getId(int l,int r)
{
    return (l+r)|(l<r);
}
struct nodeY
{
    int v[MAXN<<1],y,id;
    void build(int &xl,int &xr,int l=1,int r=-1)
    {
        if(r<0)r=y;
        int n=getId(l,r),m=(l+r)/2;
        if(l==r)
        {
            v[n]=((id/2 ? xl : -xl)+(id%2 ? l : -l)+2*MAXN)*10000+xl;
            v[n]=min(v[n],((id/2 ? xr : -xr)+(id%2 ? l : -l)+2*MAXN)*10000+xr);
            return;
        }
        build(xl,xr,l,m);
        build(xl,xr,m+1,r);
        v[n]=min(v[getId(l,m)],v[getId(m+1,r)]);
    }
    void update(int &p,int l=1,int r=-1)
    {
        if(r<0)r=y;
        int n=getId(l,r),m=(l+r)/2;
        if(l==r)
        {
            v[n]=INF;
            return;
        }
        if(p<=m)update(p,l,m);
        else update(p,m+1,r);
        v[n]=min(v[getId(l,m)],v[getId(m+1,r)]);
    }
    int query(int ql,int qr,int l=1,int r=-1)
    {
        if(r<0)r=y;
        int n=getId(l,r),m=(l+r)/2;
        if(ql==l && qr==r)return v[n];
        if(qr<=m)return query(ql,qr,l,m);
        if(ql>m)return query(ql,qr,m+1,r);
        return min(query(ql,m,l,m),query(m+1,qr,m+1,r));
    }
}s[4][MAXN<<1];
int l[MAXN<<1],r[MAXN<<1],ls[MAXN<<1],rs[MAXN<<1],tot;
void build(int xl,int xr,int &y,int &n)
{
    l[n]=xl,r[n]=xr;
    for(int _=0;_<4;_++)
    {
        s[_][n].y=y;
        s[_][n].id=_;
        s[_][n].build(xl,xr);
    }
    if(xl==xr)return;
    int xm=(xl+xr)/2;
    build(xl,xm,y,ls[n]=++tot);
    build(xm+1,xr,y,rs[n]=++tot);
}
void pushUp(int &yp,int yl,int yr,int &n)
{
    int t=getId(yl,yr);
    for(int _=0;_<4;_++)
        s[_][n].v[t]=min(s[_][ls[n]].v[t],s[_][rs[n]].v[t]);
    if(yl==yr)return;
    int ym=(yl+yr)/2;
    if(yp<=ym)pushUp(yp,yl,ym,n);
    else pushUp(yp,ym+1,yr,n);
}
void update(int &xp,int &yp,int &y,int &n)
{
    int xm=(l[n]+r[n])/2;
    if(l[n]==r[n])
    {
        for(int _=0;_<4;_++)
            s[_][n].update(yp);
        return;
    }
    if(xp<=xm)update(xp,yp,y,ls[n]);
    else update(xp,yp,y,rs[n]);
    pushUp(yp,1,y,n);
}
int query(int qxl,int qxr,int &qyl,int &qyr,int &id,int &n)
{
    int xm=(l[n]+r[n])/2;
    if(qxl==l[n] && qxr==r[n])return s[id][n].query(qyl,qyr);
    if(qxr<=xm)return query(qxl,qxr,qyl,qyr,id,ls[n]);
    if(qxl>xm)return query(qxl,qxr,qyl,qyr,id,rs[n]);
    return min(query(qxl,xm,qyl,qyr,id,ls[n]),query(xm+1,qxr,qyl,qyr,id,rs[n]));
}
int ptr,optr;
char buff[5000000],obuff[5000000];
inline int getInt()
{
    char ch;
    while((ch=buff[ptr++])<'0' || ch>'9');
    int res=ch-'0';
    while((ch=buff[ptr++])>='0' && ch<='9')
        res=res*10+ch-'0';
    return res;
}
char stk[15];
inline void Print(int x)
{
    int tot=0;
    if(x==0)stk[tot++]='0';
    while(x)
    {
        stk[tot++]=x%10+'0';
        x/=10;
    }
    while(tot--)
        obuff[optr++]=stk[tot];
}
int main()
{
    fread(buff,1,sizeof(buff),stdin);
    int n=getInt(),m=getInt(),k=getInt(),rt;
    build(1,n,m,rt=++tot);
    while(k--)
    {
        int x=getInt(),y=getInt();
        int xl[4],xr[4],yl[4],yr[4],now[4],res[4],dis=INF;
        for(int i=0;i<4;i++)
        {
            xl[i]=(i/2 ? x : 1),xr[i]=(i/2 ? n : x);
            yl[i]=(i%2 ? y : 1),yr[i]=(i%2 ? m : y);
            now[i]=query(xl[i],xr[i],yl[i],yr[i],i,rt);
            if(now[i]==INF)res[i]=INF;
            else res[i]=(i/2 ? -x : x)+(i%2 ? -y : y)+now[i]/10000-2*MAXN;
            dis=min(dis,res[i]);
        }
        int rx=n+1,ry=m+1;
        for(int i=0;i<4;i++)
        {
            if(res[i]>dis)continue;
            int tx=now[i]%10000;
            int ty=(i%2 ? 1 : -1)*(now[i]/10000-2*MAXN-(i/2 ? 1 : -1)*tx);
            if(tx<rx)rx=tx,ry=ty;
            else if(tx==rx && ty<ry)ry=ty;
        }
        update(rx,ry,m,rt);
        Print(rx);
        obuff[optr++]=' ';
        Print(ry);
        obuff[optr++]='\n';
    }
    fwrite(obuff,1,optr,stdout);
    return 0;
}