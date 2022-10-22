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
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
#define MAXN 400011
#define MAXQ 500011
struct node
{
    int lson,rson;
    ll sum;
}t[MAXN*28+5];
int root[MAXN],ed[MAXN], n,cnt=0;
#define rt t[num]
void insert(int& num,un pos,un l=1,un r=n)
{
    if(!num)num=++cnt;
    ++rt.sum;
    if(l==r)return;
    un mid=(l+r)>>1;
    if(pos<=mid)insert(rt.lson,pos,l,mid);
    else insert(rt.rson,pos,mid+1,r);
}
ll Qsum(int num,un ql,un qr,un l=1,un r=n)
{
    if(!num)return 0;
    if(ql<=l&&r<=qr)return rt.sum;
    un mid=(l+r)>>1;ll res=0;
    if(ql<=mid)res+=Qsum(rt.lson,ql,qr,l,mid);
    if(qr>mid)res+=Qsum(rt.rson,ql,qr,mid+1,r);
    return res;
}
int merge(int num,int p,un l=1,un r=n)
{
    if(!num||!p)return num|p;
    if(l==r){rt.sum+=t[p].sum;return num;}
    un mid=(l+r)>>1;
    rt.lson=merge(rt.lson,t[p].lson,l,mid);
    rt.rson=merge(rt.rson,t[p].rson,mid+1,r);
    rt.sum=t[rt.lson].sum+t[rt.rson].sum;
    return num;
}
struct one
{
    int l,r,dex;
    one(int _l,int _r,int _dex){l=_l,r=_r,dex=_dex;}
};
std::vector<one>a[MAXN];
ll ans[MAXQ];
struct SAM
{
    int t[MAXN][26],pre[MAXN],len[MAXN];
    int last,tot;
    SAM(){last=tot=1;}
    void insert(int w)
    {
        if(t[last][w])
        {
            int nxt=t[last][w];
            if(len[nxt]==len[last]+1)last=nxt;
            else
            {
                int tmp=++tot;
                len[tmp]=len[last]+1;
                memcpy(t[tmp],t[nxt],sizeof t[nxt]);
                pre[tmp]=pre[nxt],pre[nxt]=tmp;
                while(last&&t[last][w]==nxt)t[last][w]=tmp,last=pre[last];
                last=tmp;
            }
            return;
        }
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
    struct edge
    {
        int v,nxt;
    }e[MAXN];
    int cnt,head[MAXN];
    void adde(int u,int v){e[++cnt].v=v,e[cnt].nxt=head[u],head[u]=cnt;}
    void dfs(int u)
    {
        for(int i=head[u];i;i=e[i].nxt)dfs(e[i].v), root[u]=merge(root[u],root[e[i].v]);
        //printf("sum[%d]=%lld\n",u,Qsum(root[u],1,n));
        for(one x:a[u])
            ans[x.dex]=Qsum(root[u],x.l,x.r);
    }
    void solve()
    {
        for(int i=2;i<=tot;++i)adde(pre[i],i);
        dfs(1);
    }
}sam;
char str[MAXN];
int len[MAXN];
int main()
{
    n=read();
    int Q=read();
    for(int i=1;i<=n;++i)
    {
        sam.last=1;
        scanf("%s",str+len[i-1]);
        len[i]=len[i-1]+strlen(str+len[i-1]);
        for(int j=len[i-1];j<len[i];++j)sam.insert(str[j]-'a');
    }
    for(int i=1;i<=n;++i)
    {
        int u=1;
        for(int j=len[i-1];j<len[i];++j)u=sam.t[u][str[j]-'a'],insert(root[u],i);
        ed[i]=u;
    }
    for(int i=1;i<=Q;++i)
    {
        int l=read(),r=read(),x=read();
        a[ed[x]].push_back(one(l,r,i));
    }
    sam.solve();
    for(int i=1;i<=Q;++i)printf("%lld\n",ans[i]);
    return 0;
}