#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int u[N],v[N],w[N];
struct dsu
{
	int fa[N],siz[N];
	void send(int n){for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		if (x==y) return;
		if (siz[x]>siz[y]) swap(x,y);
		fa[x]=y,siz[y]+=siz[x];
	}
}d[30];
bool can[30][N];
int ask(int x,int y)
{
	for (int j=0;j<30;j++) if (d[j].find(x)==d[j].find(y)) return 0;
	for (int j=1;j<30;j++) if (can[j][d[j].find(x)]) return 1;
	return 2;
}

signed main()
{
	int n=read(),m=read();
	for (int j=0;j<30;j++) d[j].send(n);
	for (int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
		for (int j=0;j<30;j++) if (w[i]>>j&1) d[j].merge(u[i],v[i]);
	}
	for (int i=1;i<=m;i++) if (~w[i]&1)
	for (int j=1;j<30;j++) can[j][d[j].find(u[i])]=can[j][d[j].find(v[i])]=1;
	int Q=read();
	while (Q--)
	{
		int x=read(),y=read();
		print(ask(x,y));
	}
	
	return 0;
}