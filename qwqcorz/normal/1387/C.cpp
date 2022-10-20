#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
const int M=55;
const ll inf=1e18;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int n,m,k;
namespace AC_automaton
{
	vector<int>e[M];
	struct node
	{
		bool ed;
		int son[N],fail;
	}t[M];
	int cnt=0;
	void dfs(int now)
	{
		for (int to:e[now])
		{
			t[to].ed|=t[now].ed;
			dfs(to);
		}
	}
	void insert(int len,int *a)
	{
		int now=0;
		for (int i=1;i<=len;i++)
		{
			if (!t[now].son[a[i]]) t[now].son[a[i]]=++cnt;
			now=t[now].son[a[i]];
		}
		t[now].ed=1;
	}
	void build()
	{
		queue<int>q;
		for (int i=0;i<=n;i++) if (t[0].son[i]) q.push(t[0].son[i]);
		while (!q.empty())
		{
			int now=q.front(); q.pop();
			for (int i=0;i<=n;i++)
			if (t[now].son[i]) t[t[now].son[i]].fail=t[t[now].fail].son[i],q.push(t[now].son[i]);
			else t[now].son[i]=t[t[now].fail].son[i];
		}
		for (int i=1;i<=cnt;i++) e[t[i].fail].push_back(i);
		dfs(0);
	}
}
using namespace AC_automaton;
int a[N],c[M];
vector<int>b[N];
struct matrix
{
	int n,m;
	vector<vector<ll>>a;
	matrix(int _n=0,int _m=0){n=_n,m=_m,a=vector<vector<ll>>(n+1,vector<ll>(m+1,inf));}
	friend matrix operator *(matrix a,matrix b)
	{
		matrix ret(a.n,b.m);
		for (int i=0;i<=a.n;i++)
		for (int k=0;k<=a.m;k++) if (a.a[i][k]<inf)
		for (int j=0;j<=b.m;j++) if (b.a[k][j]<inf)
		ret.a[i][j]=min(ret.a[i][j],a.a[i][k]+b.a[k][j]);
		return ret;
	}
}f[N];
bool vis[N],flag=0;
void update(int x,vector<int>&a)
{
	for (int i:a) if (!vis[i]) return;
	vis[x]=1;
	matrix now=matrix(cnt,cnt);
	for (int i=0;i<=cnt;i++) now.a[i][i]=0;
	for (int i:a) now=now*f[i];
	for (int i=0;i<=cnt;i++)
	for (int j=0;j<=cnt;j++)
	if (now.a[i][j]<f[x].a[i][j])
	{
		f[x].a[i][j]=now.a[i][j];
		flag=1;
	}
}

signed main()
{
	n=read()-1,m=read(),k=read();
	for (int i=1;i<=m;i++)
	{
		a[i]=read();
		int siz=read();
		b[i].resize(siz);
		for (int j=0;j<siz;j++) b[i][j]=read();
	}
	for (int i=1;i<=k;i++)
	{
		int len=read();
		for (int j=1;j<=len;j++) c[j]=read();
		insert(len,c);
	}
	build();
	for (int i=0;i<=n;i++) f[i]=matrix(cnt,cnt);
	for (int j=0;j<=1;j++)
	for (int i=0;i<=cnt;i++)
	if (!t[i].ed&&!t[t[i].son[j]].ed) f[j].a[i][t[i].son[j]]=1;
	vis[0]=vis[1]=1;
	do
	{
		flag=0;
		for (int i=1;i<=m;i++) update(a[i],b[i]);
	}while (flag);
	for (int i=2;i<=n;i++)
	{
		ll ans=inf;
		for (int j=0;j<=cnt;j++)
		for (int k=0;k<=cnt;k++)
		ans=min(ans,f[i].a[j][k]);
		if (ans<inf) printf("NO %lld\n",ans);
				else puts("YES");
	}
	
	return 0;
}