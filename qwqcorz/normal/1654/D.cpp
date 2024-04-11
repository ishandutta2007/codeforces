#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
struct edge{int to,x,y;};
vector<edge>e[N];
vector<int>fac[N];
bool vis[N];
int mn[N],mx[N],tot[N],ans;
void ysgs(int n)
{
	ans=0;
	for (int i=1;i<=n;i++) e[i].clear(),fac[i].clear(),mn[i]=mx[i]=tot[i]=vis[i]=0;
	for (int i=2;i<=n;i++) if (!vis[i])
	for (int j=i;j<=n;j+=i) if (!vis[j]) mn[j]=i,vis[j]=1;
	for (int i=2;i<=n;i++)
	for (int j=i;j>1;j/=mn[j])
	fac[i].push_back(mn[j]);
}
void dfs(int now,int father,int val)
{
	ans=(ans+val)%p;
	for (edge i:e[now])
	{
		int to=i.to,x=i.x,y=i.y;
		if (to==father) continue;
		for (int j:fac[x]) tot[j]++;
		for (int j:fac[y]) tot[j]--;
		for (int j:fac[x]) mx[j]=max(mx[j],tot[j]);
		dfs(to,now,1LL*val*y%p*power(x,p-2)%p);
		for (int j:fac[x]) tot[j]--;
		for (int j:fac[y]) tot[j]++;
	}
}
void GreenDay()
{
	int n=read(); ysgs(n);
	for (int i=1;i<=n;i++) e[i].clear();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),x=read(),y=read();
		e[u].push_back((edge){v,x,y});
		e[v].push_back((edge){u,y,x});
	}
	dfs(1,0,1);
	for (int i=1;i<=n;i++) if (mx[i]) ans=1LL*ans*power(i,mx[i])%p;
	print(ans);
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}