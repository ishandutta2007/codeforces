#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;

const int M=8e5+10;
struct BIT
{
	int c[M],n;
	int lowbit(int x){return x&(-x);}
	void add(int k,int x)
	{
//		cout<<k<<' '<<x<<endl;
		for (int i=k;i<=n;i+=lowbit(i))
			c[i]+=x;
	}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))
			res+=c[i];
		return res;
	}
	int query(int l,int r){return ask(r)-ask(l-1);} 
}T;
struct graph
{
	vector<int>e[M];
	void add(int u,int v){e[u].pb(v);}
	int dfn[M],size[M],ti;
	void dfs(int u)
	{
		size[u]=1,dfn[u]=++ti;
		for (int i=0;i<e[u].size();i++)
		{
			int to=e[u][i];
			dfs(to),size[u]+=size[to];
		}
	}
}G;
struct tree
{
	int fail,son[26];
}t[M];int cnt;
void get_fail()
{
	queue<int>q;
	for (int i=0;i<26;i++)
		if (t[0].son[i])q.push(t[0].son[i]);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for (int i=0;i<26;i++)
		{
			int v=t[now].son[i];
			if (v)t[v].fail=t[t[now].fail].son[i],q.push(v);
			else t[now].son[i]=t[t[now].fail].son[i];
		}
	}
}
void get_tree()
{
	for (int i=1;i<=cnt;i++)
		G.add(t[i].fail,i);
}
int n,m,ed[M],ans[M];
vector<int>e[M];
vector<pair<int,int> >q[M];

void dfs(int u)
{
	if (u!=0)T.add(G.dfn[ed[u]],1);
	for (int i=0;i<q[u].size();i++)
		ans[q[u][i].y]=T.query(G.dfn[q[u][i].x],G.dfn[q[u][i].x]+G.size[q[u][i].x]-1);
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		dfs(to);
	}
	if (u!=0)T.add(G.dfn[ed[u]],-1);
}

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int opt,x;cin>>opt;
		if (opt==2)cin>>x;
		else x=0;int now=ed[x];
		e[x].pb(i);
		string s;cin>>s;
		if (!t[now].son[s[0]-'a'])t[now].son[s[0]-'a']=++cnt;
		ed[i]=t[now].son[s[0]-'a'];
	}cin>>m;
	for (int i=1;i<=m;i++)
	{
		int x;string s;cin>>x>>s;
		int now=0,len=s.size();
		for (int j=0;j<len;j++)
		{
			if (!t[now].son[s[j]-'a'])t[now].son[s[j]-'a']=++cnt;
			now=t[now].son[s[j]-'a'];
		}q[x].pb(mp(now,i));
	}get_fail(),get_tree();G.dfs(0);T.n=cnt+1;
	dfs(0);
	for (int i=1;i<=m;i++)cout<<ans[i]<<endl;
	return 0;
}