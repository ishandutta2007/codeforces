#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N];
int a[N],b[N],tot[N],deg[N];
bool work()
{
	int n=read();
	for (int i=1;i<=n;i++) e[i].clear();
	for (int i=1;i<=n;i++) tot[i]=deg[i]=0;
	for (int i=1;i<=n;i++) tot[a[i]=read()]++;
	for (int i=1;i<=n;i++) b[i]=read();
	int mx=1;
	for (int i=2;i<=n;i++) if (tot[i]>tot[mx]) mx=i;
	for (int i=1;i<=n;i++) if (a[i]!=mx&&b[i]!=mx) e[a[i]].push_back(b[i]),deg[b[i]]++;
	int cnt=0;
	queue<int>q;
	for (int i=1;i<=n;i++) if (!deg[i]) q.push(i);
	while (!q.empty())
	{
		int now=q.front();
		cnt++,q.pop();
		for (int to:e[now]) if (!--deg[to]) q.push(to);
	}
	return cnt==n;
}

signed main()
{
	int T=read();
	while (T--) puts(work()?"AC":"WA");
	
	return 0;
}