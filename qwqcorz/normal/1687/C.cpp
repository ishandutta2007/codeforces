#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct dsu
{
	int fa[N];
	void send(int n){for (int i=1;i<=n;i++) fa[i]=i;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
}d;
ll a[N];
vector<int>p[N];
void work()
{
	int n=read(),m=read();
	d.send(n+1);
	for (int i=0;i<=n;i++) p[i].clear();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) a[i]=a[i-1]+read()-a[i];
	for (int i=0;i<=n;i++) if (!a[i]) d.fa[i]=i+1;
	queue<pair<int,int>>q;
	while (m--)
	{
		int l=read()-1,r=read();
		p[l].push_back(r);
		p[r].push_back(l);
		if (!a[l]&&!a[r]) q.push({l,r});
	}
	while (!q.empty())
	{
		auto [l,r]=q.front(); q.pop();
		if (l>r) swap(l,r);
		for (int i=d.find(l);i<=r;i=d.find(i))
		{
			d.fa[i]=i+1,a[i]=0;
			for (int j:p[i]) if (!a[j]) q.push({j,i});
		}
	}
	puts(d.find(0)>n?"YES":"NO");
}

signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}