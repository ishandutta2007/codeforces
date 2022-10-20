#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=755;
const int M=1e7+5;

string a[N];
namespace AC_automation
{
	int head[M],nxt[M],cnte;
	void add_edge(int u)
	{
		nxt[++cnte]=head[u];
		head[u]=cnte;
	}
	int w[N],st[M],ed[M],cntdfn=0;
	void dfs0(int now)
	{
		st[now]=++cntdfn;
		for (int i=head[now];i;i=nxt[i]) dfs0(i);
		ed[now]=cntdfn;
	}
	int cnt=0;
	int son[M][2],fail[M];
	bool end[M];
	void insert(string a,int id)
	{
		int now=0,n=a.size();
		for (int i=0;i<n;i++)
		{
			if (!son[now][a[i]-'a']) son[now][a[i]-'a']=++cnt;
			now=son[now][a[i]-'a'];
		}
		w[id]=now;
	}
	void build()
	{
		int h=1,t=0;
		for (int i=0;i<=1;i++) if (son[0][i]) st[++t]=son[0][i];
		while (h<=t)
		{
			int now=st[h++];
			for (int i=0;i<=1;i++)
			if (son[now][i])
			{
				fail[son[now][i]]=son[fail[now]][i];
				st[++t]=son[now][i];
			}
			else son[now][i]=son[fail[now]][i];
		}
		for (int i=1;i<=cnt;i++) add_edge(fail[i]);
		dfs0(0);
	}
}
using namespace AC_automation;
namespace Dilworth
{
	bitset<N>e[N],is;
	int x[N],y[N],n;
	bool dfs(int now)
	{
		if (is[now]) return 0;
		is[now]=1;
		for (int i=1;i<=n;i++)
		if (e[now][i])
		if (!y[i]||dfs(y[i]))
		{
			x[now]=i,y[i]=now;
			return 1;
		}
		return 0;
	}
	int solve(int _n)
	{
		n=_n;
		int ans=n;
		for (int i=1;i<=n;i++) is.reset(),ans-=dfs(i);
		is.reset();
		for (int i=1;i<=n;i++) if (!x[i]) is.set(i);
		while (1)
		{
			bitset<N>to;
			bool flag=1;
			for (int i=1;i<=n;i++) if (is[i]) to|=e[i];
			for (int i=1;i<=n;i++) if (is[i]&&to[i])
			{
				is[i]=0,i=y[i],flag=0,is[i]=1;
				break;
			}
			if (flag) break;
		}
		return ans;
	}
}
using namespace Dilworth;

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int n; cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) insert(a[i],i);
	build();
	for (int i=1;i<=n;i++)
	{
		vector<int>pos(a[i].size());
		for (int j=0,now=0;j<(int)a[i].size();j++)
		{
			now=son[now][a[i][j]-'a'];
			pos[j]=st[now];
		}
		sort(pos.begin(),pos.end());
		for (int j=1;j<=n;j++)
		if (i!=j)
		{
			auto tmp=lower_bound(pos.begin(),pos.end(),st[w[j]]);
			if (tmp!=pos.end()&&*tmp<=ed[w[j]]) e[i].set(j);
		}
	}
	int ans=solve(n);
	cout<<ans<<'\n';
	for (int i=1;i<=n;i++) if (is[i]) cout<<i<<' ';
	
	return 0;
}