#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool vis[N];
int deg[N],p[N];
bool TheDivisionBell()
{
	int n=read(),x=read(),rt=0;
	for (int i=1;i<=n;i++) deg[i]=vis[i]=0;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		deg[u]++,deg[v]++;
	}
	int tot=0;
	for (int i=1;i<=n;i++) tot+=(p[i]=read())!=i;
	if (!tot) return 1;
	for (int i=1;i<=n;i++) if (deg[i]==n-1) rt=i;
	if (!rt) return 1;
	if (tot==2) for (int i=1;i<=n;i++) if (i!=p[i]&&i!=x&&p[i]!=x) return 1;
	if (p[rt]!=rt)
	{
		if (x==rt||p[rt]==x) return 0;
		for (int i=1;i<=n;i++) if (p[i]==rt){swap(p[i],p[rt]);break;}
		x=rt;
	}
	int m=(n&1)^(x==rt);
	for (int i=1;i<=n;i++)
	if (!vis[i])
	{
		m^=1,vis[i]=1;
		for (int j=p[i];j!=i;j=p[j]) vis[j]=1;
	}
	return !m;
}

signed main()
{
	int T=read();
	while (T--) puts(TheDivisionBell()?"Alice":"Bob");
	
	return 0;
}