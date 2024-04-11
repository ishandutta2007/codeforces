#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int f[M],n,a[M],m,ans,out[M];

struct node
{
	int to,next;
}e[M<<1];int cnt,head[M];

void add(int u,int to)
{
	e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;
}

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void dfs1(int u,int fa)
{
	if (a[u]==1)f[u]=f[fa]+1;
	else f[u]=0;
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa)dfs1(e[i].to,u);
}

void dfs2(int u,int fa,int maxn)
{
	f[u]=max(maxn,f[u]);
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa)dfs2(e[i].to,u,f[u]);
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<n;i++)
	{
		int a=read(),b=read();add(a,b),add(b,a);
		out[a]++,out[b]++;
	}
	dfs1(1,0);
	dfs2(1,0,0);
	for (int i=2;i<=n;i++)if (out[i]==1&&f[i]<=m)ans++;
	cout<<ans;
	return 0;
}