#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+1e3;

inline int read()
{
    int s=0;
    char c=getchar(),lc='+';
    while (c<'0'||c>'9') lc=c,c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return lc=='-'?-s:s;
}
int n,k,head[N],cnt=0,size[N];
ll ans=0;
struct edge
{
	int to,next;
}e[2*N];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int now,int father)
{
	for (int i=head[now];i;i=e[i].next)
	if (e[i].to!=father)
	{
		int to=e[i].to;
		dfs(to,now);
		size[now]+=size[to];
		ans+=min(size[to],2*k-size[to]);
	}
}

int main()
{
	memset(size,0,sizeof(size));
	n=read();
	k=read();
	for (int i=1;i<=2*k;i++)
	{
		int x=read();
		size[x]++;
	}
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	printf("%lld",ans);

	return 0;
}