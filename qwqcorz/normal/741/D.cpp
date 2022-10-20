#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int M=1<<22;
const int inf=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N];
int a[N],siz[N],son[N],deep[N];
void dfs(int now)
{
	siz[now]=1,son[now]=0;
	for (int to:e[now])
	{
		dfs(to);
		siz[now]+=siz[to];
		if (siz[to]>siz[son[now]]) son[now]=to;
	}
}
int t[M];
void clear(int now)
{
	t[a[now]]=-inf;
	for (int to:e[now]) clear(to);
}
void add(int now)
{
	t[a[now]]=max(t[a[now]],deep[now]);
	for (int to:e[now]) add(to);
}
int calc(int x)
{
	int ret=t[x];
	for (int i=0;i<22;i++) ret=max(ret,t[x^(1<<i)]);
	return ret;
}
int solve(int now)
{
	int ret=calc(a[now])+deep[now];
	for (int to:e[now]) ret=max(ret,solve(to));
	return ret;
}
int ans[N];
int dot(int now)
{
	int ret=0;
	for (int to:e[now])
	{
		if (to==son[now]) continue;
		ret=max(ret,dot(to));
		clear(to);
	}
	if (son[now]) ret=max(ret,dot(son[now]));
	for (int to:e[now])
	{
		if (to==son[now]) continue;
		ret=max(ret,solve(to)-deep[now]*2);
		add(to);
	}
	ret=max(ret,calc(a[now])-deep[now]),t[a[now]]=max(t[a[now]],deep[now]);
	return ans[now]=ret;
}

signed main()
{
	for (int i=0;i<M;i++) t[i]=-inf;
	int n=read();
	for (int i=2;i<=n;i++)
	{
		int fa=read();
		char c; cin>>c;
		a[i]=a[fa]^(1<<(c-'a'));
		deep[i]=deep[fa]+1;
		e[fa].push_back(i);
	}
	dfs(1);
	dot(1);
	for (int i=1;i<=n;i++) print(ans[i]," \n"[i==n]);
	
	return 0;
}