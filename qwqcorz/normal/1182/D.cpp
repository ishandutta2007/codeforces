#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int Add=998244353;
const int Mod=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int n,siz[N],mx[N],md[N],deg[N],deep[N],rt,d[N],yes=1,h[N];
vector<int>e[N];
void dfs0(int now,int father)
{
	siz[now]=1;
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
void dfs1(int now,int father)
{
	h[now]=md[now]=deg[now];
	deep[now]=deep[father]+1;
	if (!d[deep[now]]) d[deep[now]]=deg[now];
				  else yes&=d[deep[now]]==deg[now];
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs1(to,now);
		h[now]=(1LL*h[now]*N+h[to]+Add)%Mod;
		md[now]=max(md[now],md[to]);
	}
}

signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	dfs0(1,0);
	dfs1(rt,0);
	if (yes) return print(rt),0;
	while (deg[rt]!=1)
	{
		int tmp=0;
		unordered_map<int,int>mp;
		for (int to:e[rt]) if (deep[to]>deep[rt]) tmp=h[to],mp[h[to]]++;
		for (int to:e[rt]) if (deep[to]>deep[rt]&&mp[h[to]]==1&&md[to]<=2) tmp=h[to];
		for (int to:e[rt]) if (deep[to]>deep[rt]&&tmp==h[to]){rt=to;break;}
	}
	memset(deep,0,sizeof(deep));
	memset(d,0,sizeof(d));
	yes=1;
	dfs1(rt,0);
	print(yes?rt:-1);
	
	return 0;
}