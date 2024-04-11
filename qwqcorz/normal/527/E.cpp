#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=3e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct edge
{
	bool del;
	int to,nxt;
}e[M*2];
int head[N],cnte=1,siz[N];
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
void add(int u,int v)
{
	add_edge(u,v);
	add_edge(v,u);
	siz[u]++,siz[v]++;
}
vector<pair<int,int>>ans;
void dfs(int now)
{
	for (int i=head[now];i;i=head[now])
	{
		head[now]=e[i].nxt;
		if (e[i].del) continue;
		int to=e[i].to;
		e[i].del=e[i^1].del=1;
		dfs(to);
		ans.push_back(make_pair(now,to));
	}
}

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);
	}
	vector<int>p;
	for (int i=1;i<=n;i++) if (siz[i]&1) p.push_back(i);
	for (int i=0;i<(int)p.size();i+=2) add(p[i],p[i+1]),m++;
	if (m&1) add(1,1),m++;
	dfs(1);
	print(m);
	int flag=1;
	for (auto i:ans)
	{
		if (flag) print(i.first,' '),print(i.second);
			 else print(i.second,' '),print(i.first);
		flag^=1;
	}
	
	return 0;
}