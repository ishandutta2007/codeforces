#include<bits/stdc++.h>
using namespace std;
const int MAXN=200055;
const int D=2;
int a[MAXN],mx[MAXN<<2],mi[MAXN<<2],tag[MAXN<<2];
inline void push_down(int n)
{
    if(tag[n]<0)return;
    mx[n<<1]=mx[n<<1|1]=tag[n];
    mi[n<<1]=mi[n<<1|1]=tag[n];
    tag[n<<1]=tag[n<<1|1]=tag[n];
    tag[n]=-1;
}
inline void push_up(int n)
{
    mx[n]=max(mx[n<<1],mx[n<<1|1]);
    mi[n]=min(mi[n<<1],mi[n<<1|1]);
}
void build(int l,int r,int n)
{
    tag[n]=-1;
    if(l==r)
    {
        mx[n]=mi[n]=0;
        return;
    }
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    push_up(n);
}
int update(int p,int v,int l,int r,int n)
{
    if(l>=p && mx[n]==mi[n])
    {
        if(mx[n]==0 && v==-1)
        {
            mx[n]=mi[n]=tag[n]=1;
            return -1;
        }
        if(mx[n]==D-1 && v==1)
        {
            mx[n]=mi[n]=tag[n]=0;
            return 1;
        }
        if(l==r)
        {
            mx[n]+=v,mi[n]+=v;
            if(mx[n]<0)
            {
                mx[n]+=D,mi[n]+=D;
                return -1;
            }
            if(mx[n]>=D)
            {
                mx[n]-=D,mi[n]-=D;
                return 1;
            }
            return 0;
        }
    }
    push_down(n);
    int m=(l+r)/2,t=0;
    if(p<=m)
    {
        t=update(p,v,l,m,n<<1);
        if(t)t=update(p,t,m+1,r,n<<1|1);
    }
    else t=update(p,v,m+1,r,n<<1|1);
    push_up(n);
    return t;
}
int query(int l,int r,int n)
{
    if(l==r)return l;
    push_down(n);
    int m=(l+r)/2;
    return mx[n<<1|1]==1 ? query(m+1,r,n<<1|1) : query(l,m,n<<1);
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    build(1,MAXN,1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        update(a[i],1,1,MAXN,1);
    }
    while(q--)
    {
        int k,l;
        scanf("%d%d",&k,&l);
        update(a[k],-1,1,MAXN,1);
        a[k]=l;
        update(a[k],1,1,MAXN,1);
        printf("%d\n",query(1,MAXN,1));
    }
    return 0;
}