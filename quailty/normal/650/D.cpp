#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=400005;
struct BIT
{
    int n,c[MAXN<<1];
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)c[i]=0;
    }
    void update(int p,int v)
    {
        for(int i=p;i<=n;i+=i&-i)c[i]=max(c[i],v);
    }
    int query(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=i&-i)res=max(res,c[i]);
        return res;
    }
}bit;
int h[MAXN],a[MAXN],b[MAXN],x[MAXN<<1];
int pre[MAXN],suf[MAXN],cnt[MAXN],len[MAXN],res[MAXN];
#define ft first
#define sd second
vector<pair<int,int> >e[MAXN];
int main()
{
    int n,m,tot=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        x[tot++]=h[i];
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        x[tot++]=b[i];
    }
    sort(x,x+tot);
    tot=unique(x,x+tot)-x;
    for(int i=1;i<=n;i++)
        h[i]=lower_bound(x,x+tot,h[i])-x+1;
    for(int i=1;i<=m;i++)
    {
        b[i]=lower_bound(x,x+tot,b[i])-x+1;
        e[a[i]].push_back(make_pair(b[i],i));
    }
    bit.init(tot);
    for(int i=1;i<=n;i++)
    {
        pre[i]=bit.query(h[i]-1)+1;
        bit.update(h[i],pre[i]);
    }
    for(int i=1;i<=n;i++)
        h[i]=tot+1-h[i];
    bit.init(tot);
    for(int i=n;i>=1;i--)
    {
        suf[i]=bit.query(h[i]-1)+1;
        bit.update(h[i],suf[i]);
    }
    int mx=0;
    for(int i=1;i<=n;i++)
        mx=max(mx,pre[i]);
    for(int i=1;i<=n;i++)
    {
        if(pre[i]+suf[i]<mx+1)len[i]=mx;
        else cnt[pre[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(pre[i]+suf[i]==mx+1)
            len[i]=mx-1+(cnt[pre[i]]>1);
    for(int i=1;i<=n;i++)
        h[i]=tot+1-h[i];
    bit.init(tot);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(int)e[i].size();j++)
            pre[e[i][j].sd]=bit.query(e[i][j].ft-1)+1;
        bit.update(h[i],bit.query(h[i]-1)+1);
    }
    for(int i=1;i<=n;i++)
        h[i]=tot+1-h[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<(int)e[i].size();j++)
            e[i][j].ft=tot+1-e[i][j].ft;
    bit.init(tot);
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<(int)e[i].size();j++)
            suf[e[i][j].sd]=bit.query(e[i][j].ft-1)+1;
        bit.update(h[i],bit.query(h[i]-1)+1);
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<(int)e[i].size();j++)
            res[e[i][j].sd]=max(pre[e[i][j].sd]+suf[e[i][j].sd]-1,len[i]);
    for(int i=1;i<=m;i++)
        printf("%d\n",res[i]);
    return 0;
}