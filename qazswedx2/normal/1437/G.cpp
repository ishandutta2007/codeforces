#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct edge
{
	int v,nxt;
}e[600005];
int n,m,h[300005],t,ch[300005][26],cnt=1,val[300005],a[300005];
int fail[300005],q[300005],head,tail,sum[2000005],ct;
int sz[300005],son[300005],f[300005],d[300005],tp[300005],dfn[300005];
int udfn[300005];
char s[300005];
multiset<int> st[300005];
void add(int u,int v)
{
	//printf("add:u=%d,v=%d\n",u,v);
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
int ins(char *str)
{
	int u=1;
	for(int i=0;str[i];i++)
	{
		if(!ch[u][str[i]-'a']) ch[u][str[i]-'a']=++cnt;
		u=ch[u][str[i]-'a'];
	}
	return u;
}
void build()
{
	fail[1]=0;
	for(int i=0;i<26;i++)
		ch[0][i]=1;
	head=0,tail=1;
	q[1]=1;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=0;i<26;i++)
			if(ch[u][i])
			{
				fail[ch[u][i]]=ch[fail[u]][i];
				q[++tail]=ch[u][i];
			}
			else ch[u][i]=ch[fail[u]][i];
	}
}
void pushup(int x)
{
	sum[x]=max(sum[x*2],sum[x*2+1]);
}
void modify(int x,int l,int r,int qx,int v)
{
	//if(x==1) printf("modify:qx=%d,v=%d\n",qx,v);
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]=v;
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return -1;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;
	return max(query(x*2,l,mid,ql,qr),query(x*2+1,mid+1,r,ql,qr));
}
void dfs(int u,int fa,int dep)
{
	f[u]=fa;
	d[u]=dep;
	sz[u]=1;
	son[u]=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])
			son[u]=v;
	}
}
void dfs2(int u,int ttp)
{
	dfn[u]=++ct;
	udfn[ct]=u;
	tp[u]=ttp;
	if(son[u]) dfs2(son[u],ttp);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==f[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
int tquery(int u)
{
	int ans=-1;
	while(u)
	{
		ans=max(ans,query(1,1,cnt,dfn[tp[u]],dfn[u]));
	//	printf("query:l=%d,r=%d,q=%d\n",dfn[tp[u]],dfn[u],query(1,1,cnt,dfn[tp[u]],dfn[u]));
		u=f[tp[u]];
	}
	return ans;
}
inline void tmodify(int u,int val)
{
	modify(1,1,cnt,dfn[u],val);
}
int main()
{
	memset(sum,0xff,sizeof(sum));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int u=ins(s);
		a[i]=u;
		st[u].insert(0);
	}
	build();
	for(int i=2;i<=cnt;i++)
		add(fail[i],i),add(i,fail[i]);
	dfs(1,0,1);
	dfs2(1,1);
	for(int i=1;i<=cnt;i++)
		if(st[i].size())
			tmodify(i,0);
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d",&op);
		if(op==1)
		{
			int u;
			scanf("%d%d",&x,&y);
			u=a[x];
			st[u].erase(st[u].lower_bound(val[x]));
			st[u].insert(y);
			tmodify(u,*(--st[u].end()));
			val[x]=y;
		}
		else
		{
			scanf("%s",s);
			int ans=-1,u=1;
			for(int j=0;s[j];j++)
			{
				u=ch[u][s[j]-'a'];
		//		printf("i=%d,u=%d,ans=%d\n",i,u,ans);
				ans=max(ans,tquery(u));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}