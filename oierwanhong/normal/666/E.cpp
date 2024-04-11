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
#define MAXN 200011
#define MAXL 500011
struct node
{
	int lson,rson;
	int val,pos;
	node(){}
	node(int _val,int _pos){val=_val,pos=_pos,lson=rson=0;}
}t[MAXN*22+1];
#define rt t[num]
pii max(pii a,pii b)
{
	return a.first>b.first||(a.first==b.first&&a.second<b.second)?a:b;
}
void pushup(int num)
{
	if(t[rt.lson].val>t[rt.rson].val||(t[rt.lson].val==t[rt.rson].val&&t[rt.lson].pos<t[rt.rson].pos))
		rt.val=t[rt.lson].val,rt.pos=t[rt.lson].pos;
	else rt.val=t[rt.rson].val,rt.pos=t[rt.rson].pos;
}
int root[MAXN],cnt=0;
void insert(int& num,int pos,un l=1,un r=50000)
{
	if(!num)num=++cnt;
	if(l==r){++rt.val,rt.pos=l;return;}
	un mid=(l+r)>>1;
	if(pos<=mid)insert(rt.lson,pos,l,mid);
	else insert(rt.rson,pos,mid+1,r);
	pushup(num);
	//printf("mxval[%d]=%d\n",num,rt.val);
}
pii query(int num,un ql,un qr,un l=1,un r=50000)
{
	if(!num)return pii(0,0);
	if(ql<=l&&r<=qr)return pii(rt.val,rt.pos);
	un mid=(l+r)>>1;pii res(0,0);
	if(ql<=mid)res=max(res,query(rt.lson,ql,qr,l,mid));
	if(qr>mid)res=max(res,query(rt.rson,ql,qr,mid+1,r));
	return res;
}
int merge(int num,int p,un l=1,un r=50000)
{
    if(!num||!p)return num|p;
    if(l==r){rt.val+=t[p].val;return num;}
    un mid=(l+r)>>1;
    rt.lson=merge(rt.lson,t[p].lson,l,mid);
    rt.rson=merge(rt.rson,t[p].rson,mid+1,r);
    pushup(num);
    return num;
}
int ed[MAXL],mxl[MAXL],L[MAXL];
char ss[MAXL],st[MAXL];
struct one
{
    int l,r,dex;
    //one(){}
    one(int _l,int _r,int _dex){l=_l,r=_r,dex=_dex;}
};
std::vector<one>q[MAXL];
pii ans[MAXL];
struct SAM
{
	int t[MAXN][26],pre[MAXN],len[MAXN];
	int tot,last,ecnt;
	SAM(){tot=last=1,ecnt=0;}
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
	void match(char* s)
	{
		int n=strlen(s+1),u=1,nowlen=0;
		for(int i=1;i<=n;++i)
		{
			int c=s[i]-'a';
			while(u&&!t[u][c])u=pre[u],nowlen=len[u];
			if(t[u][c])++nowlen,u=t[u][c];
			else nowlen=0,u=1;
			ed[i]=u,mxl[i]=nowlen;
		}
	}
	struct edge
	{
		int v,nxt;
	}e[MAXN];
	int head[MAXN];
	void adde(int u,int v){e[++ecnt].v=v,e[ecnt].nxt=head[u],head[u]=ecnt;}
	int fa[18][MAXN];
	void dfs(int u)
	{
		fa[0][u]=pre[u];
		for(int i=1;i<18;++i)
			fa[i][u]=fa[i-1][fa[i-1][u]];
		for(int i=head[u];i;i=e[i].nxt)dfs(e[i].v);
	}
	void build()
	{
		for(int i=2;i<=tot;++i)adde(pre[i],i);
		dfs(1);
	}
	int get_pos(int dex,int l)
	{
		if(mxl[dex]<l)return -1;
		int u=ed[dex];
		for(int i=17;i>=0;--i)
			if(fa[i][u]&& len[fa[i][u]]>=l)u=fa[i][u];
		return u;
	}
	void solve(int u)
	{
		fa[0][u]=pre[u];
		for(int i=1;i<18;++i)fa[i][u]=fa[i-1][fa[i-1][u]];
		for(int i=head[u];i;i=e[i].nxt)
		{
			solve(e[i].v);
			root[u]=merge(root[u],root[e[i].v]);
		}
        for(one x:q[u])ans[x.dex]=query(root[u],x.l,x.r);
	}
}sam;
int len[MAXN];
int main()
{
	scanf("%s",ss+1);
	int n=strlen(ss+1),m=read();
	for(int i=1;i<=m;++i)
	{
		scanf("%s",st+len[i-1]);
		len[i]=len[i-1]+strlen(st+len[i-1]);
		sam.last=1;
		for(int j=len[i-1];j<len[i];++j)sam.insert(st[j]-'a');
	}
	for(int i=1;i<=m;++i)
	{
		int u=1;
		for(int j=len[i-1];j<len[i];++j)u=sam.t[u][st[j]-'a'],insert(root[u],i);
	}
    sam.match(ss);
	sam.build();
	int Q=read();
	for(int i=1;i<=Q;++i)
	{
		int l=read(),r=read(),pl=read(),pr=read();
        L[i]=l;
		int u=sam.get_pos(pr,pr-pl+1);
        if(u>0)q[u].push_back(one(l,r,i));
	}
    sam.solve(1);
    for(int i=1;i<=Q;++i)
        if(ans[i].first)printf("%d %d\n",ans[i].second,ans[i].first);
        else printf("%d 0\n",L[i]);
	return 0;
}