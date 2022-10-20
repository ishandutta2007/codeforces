#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int p[N],t[N],cnt=0;
bool vis[N];
vector<pair<int,int>>ans;
void Swap(int u,int v)
{
	swap(p[u],p[v]);
	ans.push_back(make_pair(u,v));
}
void merge(int u,int v)
{
	u=t[u],v=t[v];
	Swap(u,v);
	while (p[u]!=v) Swap(u,p[u]);
	while (p[v]!=u) Swap(v,p[v]);
	Swap(u,v);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++)
	if (!vis[i])
	{
		int now=t[++cnt]=i;
		do vis[now]=1; while ((now=p[now])!=i);
	}
	if (cnt==1)
	{
		int b=t[1],a=p[b];
		Swap(a,b);
		while (b!=p[p[b]]) Swap(b,p[b]);
		int c=p[b];
		Swap(a,c);
		Swap(b,c);
		Swap(a,b);
	}
	else
	{
		for (int i=1;i+1<=cnt;i+=2) merge(i,i+1);
		if (cnt&1) merge(1,cnt);
	}
	print(ans.size());
	for (auto i:ans) print(i.first,' '),print(i.second);
	
	return 0;
}