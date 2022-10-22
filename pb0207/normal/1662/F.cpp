#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int cnt;

typedef pair<int,int> pii;

struct T{
    int l,r,ls,rs;
    pii a,b;
}t[N*2+1];

void update(int x)
{
    t[x].a=max(t[t[x].ls].a,t[t[x].rs].a);
    t[x].b=min(t[t[x].ls].b,t[t[x].rs].b);
}

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    if(l==r)
        return x;
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    update(x);
    return x;
}

void change(int x,int p,int v)
{
    if(t[x].l==t[x].r)
    {
        t[x].a=pii(t[x].l+v,t[x].l);
        t[x].b=pii(t[x].l-v,t[x].l);
        return;
    }
    int mid=(t[x].l+t[x].r)>>1;
    if(p<=mid)
        change(t[x].ls,p,v);
    else
        change(t[x].rs,p,v);
    update(x);
}

pii qrya(int x,int l,int r)
{
    if(l<=t[x].l&&t[x].r<=r)
        return t[x].a;
    int mid=(t[x].l+t[x].r)>>1;
    pii ret(-1e9,-1e9);
    if(l<=mid)
        ret=max(ret,qrya(t[x].ls,l,r));
    if(r>mid)
        ret=max(ret,qrya(t[x].rs,l,r));
    return ret;
}

pii qryb(int x,int l,int r)
{
    if(l<=t[x].l&&t[x].r<=r)
        return t[x].b;
    int mid=(t[x].l+t[x].r)>>1;
    pii ret(1e9,1e9);
    if(l<=mid)
        ret=min(ret,qryb(t[x].ls,l,r));
    if(r>mid)
        ret=min(ret,qryb(t[x].rs,l,r));
    return ret;
}

int T,n,a,b,p[N];

queue<int>q;

int d[N];

#define fs first
#define sd second

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&n,&a,&b);
        cnt=0;
        build(1,n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&p[i]),change(1,i,p[i]);
        q.push(a);
        d[a]=0;
        change(1,a,-1e9);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            while(1)
            {
                pii pos=qrya(1,max(x-p[x],1ll),max(x-1,1ll));
                if(pos.fs<x)
                    break;
                d[pos.sd]=d[x]+1;
                q.push(pos.sd);
                change(1,pos.sd,-1e9);
            }
            while(1)
            {
                pii pos=qryb(1,min(x+1,n),min(x+p[x],n));
                if(pos.fs>x)
                    break;
                d[pos.sd]=d[x]+1;
                q.push(pos.sd);
                change(1,pos.sd,-1e9);
            }
        }
        printf("%lld\n",d[b]);
    }
}