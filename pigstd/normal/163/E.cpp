#include<bits/stdc++.h>
#define pb push_back
//#define int long long
using namespace std;

const int M=1e6+10;
int n,q,ed[M],vis[M];
string s[M];

struct BIT
{
	int n,c[M];
	void build (int x){n=x;}
	int lowbit(int x){return x&(-x);} 
	void add(int k,int x)
	{
		for (int i=k;i<=n;i+=lowbit(i))c[i]+=x;
	}
	void update(int l,int r,int z)
	{
		add(l,z),add(r+1,-z);
	}
	int query(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))res+=c[i];
		return res;
	}
}T;
struct graph
{
	vector<int>e[M];
	void add(int u,int v){e[u].pb(v);}
	int size[M],dfn[M],ti;
	void dfs(int u)
	{
		size[u]=1;dfn[u]=++ti;
		for (int i=0;i<e[u].size();i++)
		{
			int to=e[u][i];
			dfs(to),size[u]+=size[to];
		}
	}
}G;
struct tree
{
	struct node
	{
		int son[26],fail;
	}t[M];int cnt;
	void insert(string s,int p)
	{
		int len=s.size(),now=0;
		for (int i=0;i<len;i++)
		{
			if (!t[now].son[s[i]-'a'])t[now].son[s[i]-'a']=++cnt;
			now=t[now].son[s[i]-'a'];
		}ed[p]=now;
	}
	void getfail()
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
	void gettree()
	{
		for (int i=1;i<=cnt;i++)
			G.add(t[i].fail,i);
	}
}TT;
int getnum(string s)
{
	int num=0;
	for (int i=1;i<s.size();i++)
		num=num*10+s[i]-'0';
	return num;
}

signed main()
{
	cin>>q>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
		TT.insert(s[i],i);
	}TT.getfail(),TT.gettree(),G.dfs(0);T.build(TT.cnt+1);
	for (int i=1;i<=n;i++)
		T.update(G.dfn[ed[i]],G.dfn[ed[i]]+G.size[ed[i]]-1,1),vis[i]=1;
	while(q--)
	{
		string s;cin>>s;
		if (s[0]=='?')
		{
			int now=0;long long ans=0;
			for (int i=1;i<s.size();i++)
			{
				now=TT.t[now].son[s[i]-'a'];
				ans+=T.query(G.dfn[now]);
			}cout<<ans<<endl;
		} 
		if (s[0]=='-')
		{
			int num=getnum(s);
			if (vis[num])
				T.update(G.dfn[ed[num]],G.dfn[ed[num]]+G.size[ed[num]]-1,-1),vis[num]--;
		}
		if (s[0]=='+')
		{
			int num=getnum(s);
			if (!vis[num])
				T.update(G.dfn[ed[num]],G.dfn[ed[num]]+G.size[ed[num]]-1,1),vis[num]++;
		}
	}return 0;
}