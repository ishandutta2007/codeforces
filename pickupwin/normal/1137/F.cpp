#include<bits/stdc++.h>
#define N 200100
using namespace std;

int n,m,tt,bj[N],son[N][2],size[N],fa[N];
char str[10];
bool fz[N],dwn[N];
struct Sz
{
    int num[N<<1];
    inline int lb(int u){return u&(-u);}
    inline int add(int u,int v){for(;u<=(n+m);u+=lb(u)) num[u]+=v;}
    inline int ask(int u){int res=0;for(;u;u-=lb(u)) res+=num[u];return res;}
}sz;
vector<int>to[N];

inline bool ar(int u){return u!=son[fa[u]][0]&&u!=son[fa[u]][1];}
inline bool as(int u){return u==son[fa[u]][1];}
inline void up(int now)
{
    int L=son[now][0],R=son[now][1];
    size[now]=size[L]+size[R]+1;
}
inline void down(int now)
{
    int L=son[now][0],R=son[now][1];
    if(fz[now])
    {
	swap(son[now][0],son[now][1]);
	fz[L]^=1,fz[R]^=1;
	fz[now]=0;
    }
    if(dwn[now])
    {
	bj[L]=bj[R]=bj[now];
	dwn[L]=dwn[R]=1;
	dwn[now]=0;
    }
}

inline void rot(int u)
{
    int p=fa[u],d=as(u);
    if(!ar(p)) son[fa[p]][as(p)]=u;
    fa[u]=fa[p];
    fa[p]=u;
    fa[son[u][!d]]=p;
    son[p][d]=son[u][!d];
    son[u][!d]=p;
    up(p),up(u);
}

void Down(int now)
{
    if(!ar(now)) Down(fa[now]);
    down(now);
}

inline void splay(int u)
{
    Down(u);
    for(;!ar(u);)
    {
	int p=fa[u];
	if(!ar(p))
	    as(u)==as(p)?rot(p):rot(u);
	rot(u);
    }
}

inline void acc(int u,int v)
{
    int p,q;
    for(p=u,q=0;p;q=p,p=fa[p])
    {
	splay(p);
	son[p][1]=0,up(p);
	sz.add(bj[p],-size[p]),sz.add(v,size[p]);
	son[p][1]=q,up(p);
	bj[p]=v,dwn[p]=1;
    }
}

void dfs(int now,int last)
{
    int i,t;
    bj[now]=now;
    for(i=0;i<to[now].size();i++)
    {
	t=to[now][i];
	if(t==last) continue;
	fa[t]=now;
	dfs(t,now);
	if(bj[t]>bj[now])
	{
	    bj[now]=bj[t];
	    son[now][1]=t;
	}
    }
    up(now);
    sz.add(bj[now],1);
}

inline int calc(int u)
{
    splay(u);
    int res=sz.ask(bj[u]);
    return res-size[son[u][0]];
}

int main()
{
    int i,j,p,q;
    cin>>n>>m;
    for(i=1;i<n;i++)
    {
	scanf("%d%d",&p,&q);
	to[p].push_back(q);
	to[q].push_back(p);
    }
    dfs(n,-1);
    tt=n;
    for(i=1;i<=m;i++)
    {
	scanf("%s",str);
	if(str[0]=='u')
	{
	    scanf("%d",&p);
	    acc(p,++tt),splay(p),fz[p]^=1;
	}
	else if(str[0]=='c')
	{
	    scanf("%d%d",&p,&q);
	    
	    ++p;--p;
	    printf("%d\n",calc(p)<calc(q)?p:q);
	}
	else
	{
	    scanf("%d",&p);
	    printf("%d\n",calc(p));
	}
    }
}