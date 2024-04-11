#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool del[N];
vector<pair<int,int>>t[N];
int u[N],v[N],siz[N],deg[N];
pair<int,int>fa[N];
pair<int,int>get(int x)
{
	for (auto [to,id]:t[x]) if (!del[to]) return make_pair(to,id);
	return make_pair(-1,-1);
}
vector<int>e[N],id[N],pos[N][2];
vector<pair<int,int>>ans;
void work()
{
	ans.clear();
	int n=read(),cnt=0;
	for (int i=1;i<=n;i++) t[i].clear(),id[i].clear(),pos[i][0].clear(),pos[i][1].clear(),e[i].clear(),siz[i]=deg[i]=del[i]=0;
	for (int i=1;i<n;i++)
	{
		u[i]=read(),v[i]=read();
		t[u[i]].push_back({v[i],i});
		t[v[i]].push_back({u[i],i});
		siz[u[i]]++,siz[v[i]]++;
	}
	for (int i=1;i<=n;i++) id[i].resize(siz[i]);
	for (int i=1;i<=n;i++)
	for (int j=0;j<siz[i];j++) pos[i][j&1].push_back(j);
	queue<int>q;
	for (int i=1;i<=n;i++) if (siz[i]==1) q.push(i),fa[i]=get(i);
	while (q.size()>1)
	{
		int now=q.front(); q.pop();
		del[now]=1;
		int col=pos[now][1].size();
		auto [to,i]=fa[now];
		if (pos[to][col].empty()) return puts("NO"),void();
		id[now][pos[now][col].back()]=i;
		id[to][pos[to][col].back()]=i;
		pos[now][col].pop_back();
		pos[to][col].pop_back();
		if (--siz[to]==1) q.push(to),fa[to]=get(to);
	}
	static int tmp[N];
	for (int i=1;i<=n;i++) tmp[i]=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<(int)id[i].size();j++)
	e[id[i][j]].push_back(id[i][j-1]),tmp[id[i][j-1]]++;
	queue<int>Q;
	for (int i=1;i<n;i++) if (!tmp[i]) Q.push(i);
	while (!Q.empty())
	{
		int now=Q.front(); Q.pop();
		ans.push_back({u[now],v[now]});
		for (int to:e[now]) if (!--tmp[to]) Q.push(to);
	}
	puts("YES");
	for (auto [x,y]:ans) print(x,' '),print(y);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}