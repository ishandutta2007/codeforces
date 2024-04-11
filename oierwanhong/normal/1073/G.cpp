#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void umax(int& a,int t){if(t>a)a=t;}
bool umin(int& a,int t){if(t<a)return a=t,1;return 0;}
#define MAXN 400011
struct SAM
{
    int t[MAXN][26],pre[MAXN],len[MAXN];
    int last,tot;
    SAM(){tot=last=1;}
    void insert(int w)
    {
        int pos=last,cur=++tot;
        len[cur]=len[pos]+1,last=cur;
        while(pos&&!t[pos][w])t[pos][w]=cur,pos=pre[pos];
        if(!pos){pre[cur]=1;return;}
        int nxt=t[pos][w];
        if(len[nxt]==len[pos]+1)pre[cur]=nxt;
        else
        {
            int tmp=++tot;
            len[tmp]=len[pos]+1;
            memcpy(t[tmp],t[nxt],sizeof t[nxt]);
            pre[tmp]=pre[nxt],pre[nxt]=pre[cur]=tmp;
            while(pos&&t[pos][w]==nxt)t[pos][w]=tmp,pos=pre[pos];
        }
    }
}sam;
struct Segment_Tree
{
    struct node
    {
        ll sum,k,tag;
    }t[MAXN<<2|1];
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    void pushdown(un l,un r,un num)
    {
        if(!rt.tag)return;
        un mid=(l+r)>>1;
        tl.sum+=tl.k*rt.tag,tl.tag+=rt.tag;
        tr.sum+=tr.k*rt.tag,tr.tag+=rt.tag;
        rt.tag=0;
    }
    void build(int* arr,un l=1,un r=sam.tot,un num=1)
    {
        if(l==r)rt.k=arr[l];
        else
        {
            un mid=(l+r)>>1;
            build(arr,l,mid,num<<1),build(arr,mid+1,r,num<<1|1);
            rt.k=tl.k+tr.k;
        }
    }
    void modify(un ql,un qr,ll k,un l=1,un r=sam.tot,un num=1)
    {
        if(ql<=l&&r<=qr){rt.sum+=k*rt.k,rt.tag+=k;return;}
        pushdown(l,r,num);
        un mid=(l+r)>>1;
        if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
        if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
        rt.sum=tl.sum+tr.sum;
    }
    ll Qsum(un ql,un qr,un l=1,un r=sam.tot,un num=1)
    {
        if(ql<=l&&r<=qr)return rt.sum;
        pushdown(l,r,num);
        un mid=(l+r)>>1;ll ans=0;
        if(ql<=mid)ans+=Qsum(ql,qr,l,mid,num<<1);
        if(qr>mid)ans+=Qsum(ql,qr,mid+1,r,num<<1|1);
        return ans;
    }
}sgt;
struct edge
{
    int v,nxt;
}e[MAXN];
int cnt=0,last[MAXN];
void adde(int u,int v){e[++cnt].v=v,e[cnt].nxt=last[u],last[u]=cnt;}
int size[MAXN],fa[MAXN],mson[MAXN];
void dfs1(int u)
{
    size[u]=1;
    for(int i=last[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        fa[v]=u,dfs1(v);
        if(size[v]>size[mson[u]])mson[u]=v;
        size[u]+=size[v];
    }
}
int top[MAXN],dfn[MAXN],w[MAXN], cur=0;
void dfs2(int u,int now_top)
{
    top[u]=now_top,dfn[u]=++cur,w[cur]=sam.len[u]-sam.len[fa[u]];
    if(mson[u])dfs2(mson[u],now_top);
    for(int i=last[u];i;i=e[i].nxt)
        if(e[i].v!=mson[u])dfs2(e[i].v,e[i].v);
}
void add_to_root(int u,int k)
{
    while(u)sgt.modify(dfn[top[u]],dfn[u],k),u=fa[top[u]];
}
ll Qsum_to_root(int u)
{
    ll res=0;
    while(u)res+=sgt.Qsum(dfn[top[u]],dfn[u]),u=fa[top[u]];
    return res;
}
int ed[MAXN],a[MAXN],b[MAXN];
char s[MAXN];
int main()
{
    int n=read(),m=read();scanf("%s",s+1);
    for(int i=n;i;--i)sam.insert(s[i]-'a'),ed[i]=sam.last;
    for(int i=2;i<=sam.tot;++i)adde(sam.pre[i],i);
    dfs1(1),dfs2(1,1),sgt.build(w);
    while(m--)
    {
        int k=read(),l=read();
        ll ans=0;
        for(int i=1;i<=k;++i)a[i]=read();
        for(int i=1;i<=l;++i)b[i]=read(),add_to_root(ed[b[i]],1);
        for(int i=1;i<=k;++i)ans+=Qsum_to_root(ed[a[i]]);
        for(int i=1;i<=l;++i)add_to_root(ed[b[i]],-1);
        printf("%lld\n",ans);
    }
    return 0;
}