#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int m[N],col[N];
vector<int>id[N],e[N];
void add_edge(int u,int v)
{
	e[u].push_back(v);
	e[v].push_back(u);
}
void dfs(int now,int c)
{
	col[now]=c;
	for (int to:e[now]) if (!~col[to]) dfs(to,!c);
}

signed main()
{
	map<int,int>rest;
	int n=read(),cnt=0;
	for (int i=1;i<=n;i++)
	{
		map<int,int>mp;
		id[i].resize(m[i]=read());
		for (int j=0;j<m[i];j++)
		{
			id[i][j]=++cnt;
			int x=read();
			if (mp.count(x))
			{
				add_edge(id[i][mp[x]],id[i][j]);
				mp.erase(x);
			}
			else mp[x]=j;
		}
		for (auto j:mp)
		if (rest.count(j.first))
		{
			add_edge(rest[j.first],id[i][j.second]);
			rest.erase(j.first);
		}
		else rest[j.first]=id[i][j.second];
		vector<int>tmp;
		for (auto j:mp) tmp.push_back(id[i][j.second]);
		for (int i=0;i<(int)tmp.size();i+=2) add_edge(tmp[i],tmp[i+1]);
	}
	if (!rest.empty()) return puts("NO"),0;
	puts("YES");
	memset(col,-1,sizeof(col));
	for (int i=1;i<=cnt;i++) if (!~col[i]) dfs(i,0);
	for (int i=1;i<=n;i++,puts(""))
	for (int j=0;j<m[i];j++) putchar("LR"[col[id[i][j]]]);
	
	return 0;
}