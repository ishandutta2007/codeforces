#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

ll k;
int mx[N],siz[N],rt,n,deep[N],cnt=0,fa[N];
vector<int>e[N];
void dfs0(int now,int father)
{
	siz[now]=1,mx[now]=0;
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs0(to,now);
		siz[now]+=siz[to];
		mx[now]=max(mx[now],siz[to]);
	}
	mx[now]=max(mx[now],n-siz[now]);
	if (mx[now]<=n/2) rt=now;
}
bool vis[N];
ll sum=0;
priority_queue<pair<int,int>>q;
set<int>t[N];
set<pair<int,int>>S[N];
void dfs1(set<pair<int,int>>&S,int now,int father)
{
	sum+=deep[now]=deep[fa[now]=father]+1;
	siz[now]=1;
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs1(S,to,now);
		siz[now]+=siz[to];
		t[now].insert(to);
	}
	if (!t[now].empty()) S.insert({deep[now],now});
}
void del(set<pair<int,int>>&S,int x)
{
	vis[x]=1;
	t[fa[x]].erase(x);
	if (t[fa[x]].empty()) S.erase({deep[fa[x]],fa[x]});
}
void dfs2(vector<int>&S,int now)
{
	if (!vis[now]) S.push_back(now);
	for (int to:t[now]) dfs2(S,to);
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs0(1,0);
	for (int to:e[rt])
	{
		t[rt].insert(to);
		dfs1(S[++cnt],to,rt);
		q.push({siz[to],cnt});
	}
	k=sum-k;
	if (k<0||(k&1)) return puts("NO"),0;
	vector<pair<int,int>>ans;
	while (k)
	{
		if (q.empty()) return puts("NO"),0;
		auto [siz,id]=q.top(); q.pop();
		if (S[id].empty()) continue;
		int x=S[id].rbegin()->second;
		if (k<deep[x]*2)
		{
			int u=*t[x].begin();
			while (k<deep[x]*2) x=fa[x];
			k-=deep[x]*2;
			int v=x;
			vis[u]=vis[v]=1;
			ans.push_back({u,v});
		}
		else if (t[x].size()>1)
		{
			k-=deep[x]*2;
			int u=*t[x].begin(); del(S[id],u);
			int v=*t[x].begin(); del(S[id],v);
			ans.push_back({u,v});
		}
		else
		{
			k-=deep[x]*2;
			int u=*t[x].begin(); del(S[id],u);
			int v=x; del(S[id],v);
			ans.push_back({u,v});
		}
		q.push({siz-2,id});
	}
	vector<int>now;
	dfs2(now,rt);
	int m=now.size();
	for (int i=0;i<m/2;i++) ans.push_back({now[i],now[i+m/2]});
	puts("YES");
	for (auto [x,y]:ans) print(x,' '),print(y);
	
	return 0;
}