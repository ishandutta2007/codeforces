#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct edge{int to,val;};
vector<edge>e[N];
bool del[N];
double ans=1e36,a[N];
int rt,id,siz[N],mx[N];
void findroot(int now,int father,int tot)
{
	siz[now]=1,mx[now]=0;
	for (edge i:e[now])
	{
		int to=i.to;
		if (to==father||del[to]) continue;
		findroot(to,now,tot);
		siz[now]+=siz[to];
		mx[now]=max(mx[now],siz[to]);
	}
	mx[now]=max(mx[now],tot-siz[now]);
	if (mx[now]<=tot/2) rt=now;
}
double f[N],sum;
void dfs0(int now,int father,int len)
{
	sum+=len*sqrt(len)*a[now];
	f[now]=1.5*sqrt(len)*a[now];
	for (edge i:e[now])
	{
		int to=i.to,val=i.val;
		if (to==father) continue;
		dfs0(to,now,len+val);
		f[now]+=f[to];
	}
}
void dfs(int now,int tot)
{
	rt=0,findroot(now,0,tot),findroot(rt,0,tot);
	sum=0,dfs0(rt,0,0);
	int x=rt;
	del[x]=1;
	if (sum<ans) ans=sum,id=x;
	for (edge i:e[x])
	{
		int to=i.to;
		if (del[to]) continue;
		if (f[x]-f[to]*2<0)
		{
			dfs(to,siz[to]);
			return;
		}
	}
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	dfs(1,n);
	print(id,' ');
	printf("%.10lf\n",ans);
	
	return 0;
}