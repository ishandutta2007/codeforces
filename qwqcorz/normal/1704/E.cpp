#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N],b[N],deg[N];
vector<int>e[N];
void work()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++) e[i].clear();
	for (int i=1;i<=n;i++) a[i]=read(),deg[i]=0;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		deg[v]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (*max_element(a+1,a+1+n)==0) return print(i-1),void();
		for (int u=1;u<=n;u++) b[u]=a[u];
		for (int u=1;u<=n;u++)
		if (a[u])
		{
			b[u]--;
			for (int v:e[u]) b[v]++;
		}
		for (int u=1;u<=n;u++) a[u]=b[u];
	}
	for (int i=1;i<=n;i++) a[i]%=p;
	queue<int>q;
	for (int i=1;i<=n;i++) if (!deg[i]) q.push(i);
	while (!q.empty())
	{
		int now=q.front(); q.pop();
		for (int to:e[now])
		{
			a[to]=(a[to]+a[now])%p;
			if (!--deg[to]) q.push(to);
		}
		if (q.empty()) print((n+a[now])%p);
	}
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}