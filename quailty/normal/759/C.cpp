#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
struct info
{
    int v,mx;
    info(){}
    info(int _v,int _mx):v(_v),mx(_mx){}
    info operator + (const info &t)const
    {
        return info(v+t.v,max(mx+t.v,t.mx));
    }
}s[MAXN<<2];
void pushUp(int n)
{
    s[n]=s[n<<1]+s[n<<1|1];
}
void build(int l,int r,int n)
{
    s[n]=info(0,0);
    if(l==r)return;
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
}
void update(int p,int v,int l,int r,int n)
{
    if(l==r)
    {
        s[n]=info(v,v);
        return;
    }
    int m=(l+r)/2;
    if(p<=m)update(p,v,l,m,n<<1);
    else update(p,v,m+1,r,n<<1|1);
    pushUp(n);
}
int query(int l,int r,int n,info tmp)
{
    if((s[n]+tmp).mx<=0)return 0;
    if(l==r)return l;
    int m=(l+r)/2;
    int t=query(m+1,r,n<<1|1,tmp);
    return t ? t : query(l,m,n<<1,s[n<<1|1]+tmp);
}
int x[MAXN];
int main()
{
    int m;
    scanf("%d",&m);
    x[0]=-1;
    build(1,m,1);
    for(int i=1;i<=m;i++)
    {
        int p,t;
        scanf("%d%d",&p,&t);
        if(!t)update(p,-1,1,m,1);
        else
        {
            update(p,1,1,m,1);
            scanf("%d",&x[p]);
        }
        printf("%d\n",x[query(1,m,1,info(0,0))]);
    }
    return 0;
}