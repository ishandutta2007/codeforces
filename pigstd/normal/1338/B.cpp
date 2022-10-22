#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int f[M][2],out[M],dp[M],n;

struct edge
{
	int to,next;
}e[M<<1];int cnt,head[M];
void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt,out[u]++;}

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void dfs1(int u,int fa)
{
	if (out[u]==1)f[u][0]=1;
	for (int i=head[u];i;i=e[i].next)
	{
		int to=e[i].to;
		if (to==fa)continue;
		dfs1(to,u);
		f[u][0]|=f[to][1];
		f[u][1]|=f[to][0];
	}
}

void dfs2(int u,int fa)
{
	if (out[u]==1)
		dp[fa]++;
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa)dfs2(e[i].to,u);
}

int main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}int rt;
	for (int i=1;i<=n;i++)
		if (out[i]!=1){rt=i;break;}
	int k1=0;dfs1(rt,0);
	for (int i=1;i<=n;i++)
		if (f[i][0]&&f[i][1])k1=1;
	if (k1)cout<<"3 ";
	else cout<<"1 ";
	dfs2(rt,0);
	int ans=n-1;
	for (int i=1;i<=n;i++)
		ans-=max(0,dp[i]-1);
	cout<<ans;
	return 0;
}