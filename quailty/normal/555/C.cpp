#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXQ=200005;
struct node
{
    int l,r,m,v,t;
}s[2][MAXQ<<2];
void push_up(int n,int id)
{
    s[id][n].v=max(s[id][n<<1].v,s[id][n<<1|1].v);
}
void push_down(int n,int id)
{
    if(!s[id][n].t)return;
    s[id][n<<1].v=max(s[id][n<<1].v,s[id][n].t);
    s[id][n<<1|1].v=max(s[id][n<<1|1].v,s[id][n].t);
    s[id][n<<1].t=max(s[id][n<<1].t,s[id][n].t);
    s[id][n<<1|1].t=max(s[id][n<<1|1].t,s[id][n].t);
    s[id][n].t=0;
}
void build(int l,int r,int n,int id)
{
    int m=(l+r)>>1;
    s[id][n].l=l;
    s[id][n].r=r;
    s[id][n].m=m;
    s[id][n].v=0;
    s[id][n].t=0;
    if(r-l==1)return;
    build(l,m,n<<1,id);
    build(m,r,n<<1|1,id);
}
void update(int k,int l,int r,int n,int id)
{
    if(r<=l)return;
    if(s[id][n].l==l && s[id][n].r==r)
    {
        s[id][n].v=max(s[id][n].v,k);
        s[id][n].t=max(s[id][n].t,k);
        return;
    }
    push_down(n,id);
    if(r<=s[id][n].m)update(k,l,r,n<<1,id);
    else if(l>=s[id][n].m)update(k,l,r,n<<1|1,id);
    else
    {
        update(k,l,s[id][n].m,n<<1,id);
        update(k,s[id][n].m,r,n<<1|1,id);
    }
    push_up(n,id);
}
int query(int p,int n,int id)
{
    if(s[id][n].l==p && s[id][n].r==p+1)return s[id][n].v;
    push_down(n,id);
    if(p<s[id][n].m)return query(p,n<<1,id);
    else return query(p,n<<1|1,id);
}
int x[MAXQ],y[MAXQ],op[MAXQ];
int xx[MAXQ],yy[MAXQ];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    char cmd[5];
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%s",&x[i],&y[i],cmd);
        xx[i]=x[i];
        yy[i]=y[i];
        if(cmd[0]=='U')op[i]=0;
        else op[i]=1;
    }
    sort(xx+1,xx+q+1);
    sort(yy+1,yy+q+1);
    build(1,q+1,1,0);
    build(1,q+1,1,1);
    int l[2];
    for(int i=1;i<=q;i++)
    {
        l[0]=lower_bound(xx+1,xx+q+1,x[i])-xx;
        l[1]=lower_bound(yy+1,yy+q+1,y[i])-yy;
        int t=query(l[op[i]],1,op[i]);
        update(l[op[i]^1],l[op[i]],l[op[i]]+1,1,op[i]);
        update(l[op[i]],t+1,l[op[i]^1]+1,1,op[i]^1);
        if(!op[i])printf("%d\n",y[i]-yy[t]);
        else printf("%d\n",x[i]-xx[t]);
    }
    return 0;
}