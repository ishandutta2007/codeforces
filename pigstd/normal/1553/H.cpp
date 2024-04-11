#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int N=20;
const int M=(1<<19)+10;
int k,n,a[M],f[N][M];
int son[M<<1][2],cnt;
vector<int>minn[M<<1],maxn[M<<1];

void insert(int x)
{
	int now=0;
	for (int i=k-1;i>=0;i--)
	{
		int c=((x>>i)&1);
		if (!son[now][c])son[now][c]=++cnt;
		now=son[now][c];
	}
}

void dfs(int u,int x)
{
	if (x==0)
	{
		minn[u].pb(0),maxn[u].pb(0);
		return;
	}
	if (son[u][0])dfs(son[u][0],x-1);
	if (son[u][1])dfs(son[u][1],x-1);
	for (int j=0;j<(1<<x);j++)
	{
		int c=(j>>(x-1))&1,y=j-(1<<(x-1))*c;
		int Min=inf,Max=0;
		if (son[u][c])Min=min(Min,minn[son[u][c]][y]),Max=max(Max,maxn[son[u][c]][y]);
		if (son[u][c^1])
			Min=min(Min,minn[son[u][c^1]][y]+(1<<(x-1))),
			Max=max(Max,maxn[son[u][c^1]][y]+(1<<(x-1)));
		if (son[u][c]&&son[u][c^1])
			f[x][j]=min(f[x][j],(1<<(x-1))+minn[son[u][c^1]][y]-maxn[son[u][c]][y]);
		minn[u].pb(Min),maxn[u].pb(Max);
	}
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)a[i]=read(),insert(a[i]);
	memset(f,0x3f,sizeof(f));
	dfs(0,k);
	for (int i=0;i<(1<<k);i++)
	{
		int ans=inf;
		for (int d=1;d<=k;d++)
			ans=min(ans,f[d][i&((1<<d)-1)]);
		cout<<ans<<' ';
	}
	return 0;
}