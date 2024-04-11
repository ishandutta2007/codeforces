#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const int p=999999937;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b,int p)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
char a[N];
vector<int>e[N];
namespace sptree
{
	int fa[N],top[N],deep[N],siz[N],son[N];
	void dfs0(int now,int father)
	{
		fa[now]=father;
		deep[now]=deep[father]+1;
		siz[now]=1,son[now]=0;
		for (int to:e[now])
		{
			if (to==father) continue;
			dfs0(to,now);
			siz[now]+=siz[to];
			if (siz[to]>siz[son[now]]) son[now]=to;
		}
	}
	void dfs1(int now,int father,int Top)
	{
		top[now]=Top;
		if (son[now]) dfs1(son[now],now,Top);
		for (int to:e[now])
		{
			if (to==father||to==son[now]) continue;
			dfs1(to,now,to);
		}
	}
	void build()
	{
		dfs0(1,0);
		dfs1(1,0,1);
	}
	int find(int x,int y)
	{
		while (top[x]!=top[y])
		{
			if (deep[top[x]]<deep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
		return deep[x]<deep[y]?x:y;
	}
}
namespace tree
{
	const int inv1=power(26,p-2,p);
	vector<int>up[N],down[N];
	int h1[N],h2[N],pw[N],ipw[N];
	int fa[N][20],Log[N],deep[N],len[N],son[N],top[N];
	void dfs0(int now,int father)
	{
		len[now]=1;
		fa[now][0]=father;
		for (int i=1;i<20;i++) fa[now][i]=fa[fa[now][i-1]][i-1];
		deep[now]=deep[father]+1;
		h1[now]=(h1[father]+1LL*(a[now]-'a')*pw[deep[now]])%p;
		h2[now]=(h2[father]*26LL+a[now]-'a')%p;
		for (int to:e[now])
		{
			if (to==father) continue;
			dfs0(to,now);
			if (len[now]<len[to]+1)
			{
				len[now]=len[to]+1;
				son[now]=to;
			}
		}
	}
	void dfs1(int now,int father,int Top)
	{
		top[now]=Top;
		if (son[now]) dfs1(son[now],now,Top);
		for (int to:e[now])
		{
			if (to==father||to==son[now]) continue;
			dfs1(to,now,to);
		}
	}
	void build(int n)
	{
		sptree::build();
		for (int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
		for (int i=pw[0]=1;i<=n;i++) pw[i]=pw[i-1]*26LL%p;
		for (int i=ipw[0]=1;i<=n;i++) ipw[i]=1LL*ipw[i-1]*inv1%p;
		dfs0(1,0);
		dfs1(1,0,1);
		for (int i=1;i<=n;i++)
		if (top[i]==i)
		{
			up[i].resize(len[i]),down[i].resize(len[i]);
			for (int j=0,x=i,y=i;j<len[i];j++)
			{
				up[i][j]=x,down[i][j]=y;
				x=fa[x][0],y=son[y];
			}
		}
	}
	int find(int x,int y)
	{
		return sptree::find(x,y);
		if (deep[x]<deep[y]) swap(x,y);
		for (int i=19;deep[x]!=deep[y];i--)
		if (deep[fa[x][i]]>=deep[y]) x=fa[x][i];
		if (x==y) return x;
		for (int i=19;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
		x=fa[x][i],y=fa[y][i];
		return fa[x][0];
	}
	inline int get(int x,int k)
	{
		if (!k) return x;
		int l=Log[k];
		x=fa[x][l],k-=1<<l;
		if (!k) return x;
		if (k<=deep[x]-deep[top[x]]) return down[top[x]][deep[x]-deep[top[x]]-k];
								else return up[top[x]][k-(deep[x]-deep[top[x]])];
	}
}
using namespace tree;
int geth(int x,int y,int lca,int k)
{
	int len=deep[x]-deep[lca]+1;
	if (k<=len) return 1LL*(h1[x]-h1[get(x,k)]+p)*ipw[deep[x]-k+1]%p;
	else
	{
		ll tmp=1LL*(h1[x]-h1[fa[lca][0]]+p)*ipw[deep[lca]]%p;
		return (1LL*tmp*pw[k-len]+h2[get(y,deep[y]-deep[lca]-(k-len))]-1LL*h2[lca]*pw[k-len]%p+p)%p;
	}
}

signed main()
{
	int n=read();
	scanf("%s",a+1);
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	build(n);
	int Q=read();
	while (Q--)
	{
		int x=read(),y=read(),u=read(),v=read(),la=find(x,y),lb=find(u,v);
		int l=1,r=min(deep[x]+deep[y]-deep[la]*2+1,deep[u]+deep[v]-deep[lb]*2+1);
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (geth(x,y,la,mid)==geth(u,v,lb,mid)) l=mid+1;
											   else r=mid-1;
		}
		print(r);
	}
	
	return 0;
}