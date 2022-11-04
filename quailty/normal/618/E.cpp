#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=300005;
const db PI=acos(-1.0);
db len[MAXN<<1],arg[MAXN<<1],lz[MAXN<<1];
int getId(int l,int r)
{
    return (l+r)|(l<r);
}
void pushUp(int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    int ls=getId(l,m),rs=getId(m+1,r);
    db x=len[ls]*cos(arg[ls]/180*PI)+len[rs]*cos(arg[rs]/180*PI);
    db y=len[ls]*sin(arg[ls]/180*PI)+len[rs]*sin(arg[rs]/180*PI);
    len[n]=sqrt(x*x+y*y),arg[n]=atan2(y,x)/PI*180;
}
void pushDown(int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    int ls=getId(l,m),rs=getId(m+1,r);
    arg[ls]+=lz[n];
    lz[ls]+=lz[n];
    arg[rs]+=lz[n];
    lz[rs]+=lz[n];
    lz[n]=0;
}
void build(int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(l==r)
    {
        len[n]=1;
        arg[n]=0;
        lz[n]=0;
        return;
    }
    build(l,m);
    build(m+1,r);
    pushUp(l,r);
}
void update(int ql,int qr,int v,int op,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(ql==l && qr==r)
    {
        if(op==1)len[n]+=v;
        else
        {
            arg[n]-=v;
            lz[n]-=v;
        }
        return;
    }
    pushDown(l,r);
    if(qr<=m)update(ql,qr,v,op,l,m);
    else if(ql>m)update(ql,qr,v,op,m+1,r);
    else
    {
        update(ql,m,v,op,l,m);
        update(m+1,qr,v,op,m+1,r);
    }
    pushUp(l,r);
}
void query(int l,int r)
{
    int n=getId(l,r);
    db x=len[n]*cos(arg[n]/180*PI);
    db y=len[n]*sin(arg[n]/180*PI);
    printf("%.10f %.10f\n",x,y);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,n);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        update(y,(x==1 ? y : n),z,x,1,n);
        query(1,n);
    }
    return 0;
}