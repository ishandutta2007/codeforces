#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<bitset>
typedef long long ll;
typedef unsigned un;
//typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
const ll INF=1ll<<58;
#define MAXN 400011
struct node
{
    int lson,rson;
}t[MAXN*21];
#define rt t[num]
int root[MAXN],cnt=0,n;
void insert(int& num,un pos,un l=1,un r=n)
{
    if(!num)num=++cnt;
    if(l==r)return;
    un mid=(l+r)>>1;
    if(pos<=mid)insert(rt.lson,pos,l,mid);
    else insert(rt.rson,pos,mid+1,r);
}
bool Query(int num,un ql,un qr,un l=1,un r=n)
{
    if(!num)return 0;
    if(ql<=l&&r<=qr)return 1;
    un mid=(l+r)>>1;bool res=0;
    if(ql<=mid)res|=Query(rt.lson,ql,qr,l,mid);
    if(qr>mid)res|=Query(rt.rson,ql,qr,mid+1,r);
    return res;
}
int merge(int a,int b)
{
    if(!a||!b)return a|b;
    int num=++cnt;
    rt.lson=merge(t[a].lson,t[b].lson);
    rt.rson=merge(t[a].rson,t[b].rson);
    return num;
}
int ed[MAXN];
struct SAM
{
    int t[MAXN][26],pre[MAXN],len[MAXN];
    int last,tot,ecnt;
    SAM(){last=tot=1;ecnt=0;}
    void insert(int w,int dex)
    {
        int pos=last,cur=++tot;
        ed[cur]=dex;
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
            ed[tmp]=ed[nxt];
            pre[tmp]=pre[nxt],pre[nxt]=pre[cur]=tmp;
            while(pos&&t[pos][w]==nxt)t[pos][w]=tmp,pos=pre[pos];
        }
    }
    struct edge
    {
        int v,nxt;
    }e[MAXN];
    int head[MAXN],f[MAXN],g[MAXN];
    void adde(int u,int v){e[++ecnt].v=v,e[ecnt].nxt=head[u],head[u]=ecnt;}
    void dfs1(int u)
    {
        for(int i=head[u];i;i=e[i].nxt)dfs1(e[i].v),root[u]=merge(root[u],root[e[i].v]);
    }
    void dfs2(int u)
    {
        if(!pre[u])g[u]=u,f[u]=0;
        else if(pre[u]==1)g[u]=u,f[u]=1;
        else
        {
            if(Query(root[g[pre[u]]],ed[u]-len[u]+len[g[pre[u]]],ed[u]-1))f[u]=f[pre[u]]+1,g[u]=u;
            else f[u]=f[pre[u]],g[u]=g[pre[u]];
        }
        for(int i=head[u];i;i=e[i].nxt)dfs2(e[i].v);
    }
    int solve()
    {
        for(int i=2;i<=tot;++i)adde(pre[i],i);
        dfs1(1),dfs2(1);
        int ans=0;
        for(int i=1;i<=tot;++i)ans=std::max(ans,f[i]);
        return ans;
    }
}sam;
char s[MAXN];
int main()
{
    n=read();
    scanf("%s",s+1);
    for(int i=1;i<=n;++i)sam.insert(s[i]-'a',i),insert(root[sam.last],i);
    printf("%d",sam.solve());
    return 0;
}