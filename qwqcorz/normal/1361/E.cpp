#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

mt19937 rnd(time(0));
multiset<pair<int,int>>S[N];
int p[N],f[N],deep[N],ans[N];
bool vis[N],in[N];
vector<int>e[N],t[N];
bool dfs(int now,int father)
{
	vis[now]=in[now]=1;
	for (int to:e[now])	
	if (!vis[to]){if (!dfs(to,now)) return 0;}
	else if (!in[to]) return 0;
	in[now]=0;
	return 1;
}
bool check(int n,int x)
{
	for (int i=1;i<=n;i++) vis[i]=in[i]=0;
	return dfs(x,0);
}
void merge(multiset<pair<int,int>>&a,multiset<pair<int,int>>&b)
{
	if (a.size()<b.size()) a.swap(b);
	for (auto i:b) a.insert(i);
	b.clear();
}
void dfs0(int now,int father)
{
	f[now]=0;
	vis[now]=1;
	deep[now]=deep[father]+1;
	for (int to:e[now])
	if (!vis[to])
	{
		dfs0(to,now);
		t[now].push_back(to);
		merge(S[now],S[to]);
	}
	else S[now].insert({deep[to],to});
	while (!S[now].empty()&&S[now].rbegin()->second==now) S[now].erase(S[now].find(*S[now].rbegin()));
	if (S[now].empty()) f[now]=0;
	else if (S[now].size()>1) f[now]=-1;
	else f[now]=S[now].begin()->second;
}
void dfs1(int now,int father)
{
	if (f[now]<=0) ans[now]=!father;
			  else ans[now]=ans[f[now]];
	for (int to:t[now]) dfs1(to,now);
}
void solve(int n,int rt)
{
	for (int i=1;i<=n;i++) S[i].clear(),vis[i]=0;
	dfs0(rt,0);
	dfs1(rt,0);
	int cnt=0;
	for (int i=1;i<=n;i++) if (ans[i]) cnt++;
	if (cnt<n*0.2) return puts("-1"),void();
	for (int i=1;i<=n;i++) if (ans[i]) print(i,' ');
	puts("");
}
void work()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++) e[i].clear(),t[i].clear();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
	}
	for (int i=1;i<=n;i++) p[i]=i;
	shuffle(p+1,p+1+n,rnd);
	int rt=0;
	for (int i=1;i<=min(n,50);i++)
	{
		int x=p[i];
		if (check(n,x)) rt=x;
	}
	if (rt) solve(n,rt);
	   else puts("-1");
}

signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}