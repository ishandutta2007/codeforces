#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void error(){puts("IMPOSSIBLE"),exit(0);}
vector<int>e[N];
bool vis[N];
int l[N],r[N],col[N];
void dfs(int now)
{
	if (vis[now]) return;
	vis[now]=1;
	for (int to:e[now])
	if (col[to]){if (col[now]==col[to]) error();}
			else col[to]=3-col[now],dfs(to);
}

signed main()
{
	int L=read(),R=read(),n=read(),m=read();
	for (int i=1;i<=n;i++) l[i]=read(),r[i]=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int n1=0,n2=R;
	for (int i=1;i<=n;i++) n1=max(n1,l[i]),n2=min(n2,r[i]);
	if (n1+n2<L) n1+=L-n1-n2;
	if (n1+n2>R) n2-=n1+n2-R;
	if (n1<0||n2<0) error();
	for (int i=1;i<=n;i++)
	{
		bool can1=l[i]<=n1&&n1<=r[i],can2=l[i]<=n2&&n2<=r[i];
		if (!can1&&!can2) error();
		if (can1&&!can2) col[i]=1;
		if (!can1&&can2) col[i]=2;
	}
	for (int i=1;i<=n;i++) if (col[i]) dfs(i);
	for (int i=1;i<=n;i++) if (!vis[i]) col[i]=1,dfs(i);
	puts("POSSIBLE");
	print(n1,' '),print(n2);
	for (int i=1;i<=n;i++) putchar(col[i]+'0');
	
	return 0;
}