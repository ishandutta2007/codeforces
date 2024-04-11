#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
const int M=805;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b,int p)
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
struct dsu
{
	int fa[N*N],siz[N*N],n;
	void send(int _n){n=_n;for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	bool merge(int x,int y)
	{
		x=find(x),y=find(y);
		if (x==y) return 0;
		if (siz[x]>siz[y]) swap(x,y);
		fa[x]=y,siz[y]+=siz[x];
		return 1;
	}
}d;
int id[N][N],cnt=0,pos[N*N];
char a[N][N];
vector<pair<int,int>>e;
void add_edge(int u,int v){e.push_back(make_pair(u,v));}
int calc(int n,int p)
{
	static int a[M][M];
	memset(a,0,sizeof(a));
//	print(n);
//	for (auto i:e) print(i.first,' '),print(i.second);
	for (auto i:e)
		a[i.first][i.first]++,
		a[i.second][i.second]++,
		a[i.first][i.second]--,
		a[i.second][i.first]--;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) a[i][j]=(a[i][j]%p+p)%p;
	int ans=1;
//	for (int i=1;i<=n;i++)
//	for (int j=1;j<=n;j++) print(a[i][j]," \n"[j==n]);
	for (int i=2;i<=n;i++)
	{
		if (!a[i][i])
		for (int j=i+1;j<=n;j++)
		if (a[j][i])
		{
			swap(a[i],a[j]);
			ans*=-1;
			break;
		}
		if (!a[i][i]) return 0;
		int inv=power(a[i][i],p-2,p);
		ans=1LL*ans*a[i][i]%p;
		for (int j=i;j<=n;j++) a[i][j]=1LL*a[i][j]*inv%p;
		for (int j=i+1;j<=n;j++)
		if (a[j][i])
		{
			int tmp=a[j][i];
			for (int k=i;k<=n;k++)
			a[j][k]=(a[j][k]-1LL*a[i][k]*tmp%p+p)%p;
		}
	}
//	print((ans%p+p)%p);
	return (ans%p+p)%p;
}

signed main()
{
	int n=read(),m=read(),p=read();
	for (int i=0;i<=n;i++)
	for (int j=0;j<=m;j++) id[i][j]=++cnt;
	d.send(cnt);
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		if (a[i][j]=='/' ) if (!d.merge(id[i-1][j],id[i][j-1])) return puts("0"),0;
		if (a[i][j]=='\\') if (!d.merge(id[i][j],id[i-1][j-1])) return puts("0"),0;
	}
	int ans=0;
	for (int t=0;t<=1;t++)
	{
		e.clear();
		int k=0;
		for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++)
		if (((i^j)&1)==t&&d.find(id[i][j])==id[i][j]) pos[id[i][j]]=++k;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		if (a[i][j]=='*')
		{
			if (((i^j)&1)==t) add_edge(pos[d.find(id[i][j])],pos[d.find(id[i-1][j-1])]);
						 else add_edge(pos[d.find(id[i-1][j])],pos[d.find(id[i][j-1])]);
		}
		ans+=calc(k,p);
	}
	print(ans%p);
	
	return 0;
}