#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
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

const int M=2e5+10;
int n,ans[M],de[M],f[M][25],sz[M];
vector<int>e[M];

void dfs(int u,int fa)
{
	f[u][0]=fa,de[u]=de[fa]+1;sz[u]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (to==fa)continue;
		dfs(to,u);sz[u]+=sz[to];
		if (u==0)ans[0]+=sz[to]*(sz[to]-1)/2;
	}
}

void init()
{
	for (int j=1;j<=20;j++)
		for (int i=0;i<n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
}

int jp(int u)
{
	for (int i=20;i>=0;i--)
		if (de[f[u][i]]>=2)u=f[u][i];
	return u;
}

bool find(int a,int b)
{
	for (int i=20;i>=0;i--)
		if (de[f[a][i]]>=de[b])a=f[a][i];
	return a==b;
}

signed main()
{
	WT
	{
		n=read();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			e[u].pb(v),e[v].pb(u);
		}dfs(0,0);init();int X=1,Y=0,kk=n-sz[jp(1)];
		for (int i=2;i<=n;i++)
		{
			if (find(i-1,X))X=i-1;
			else if (find(i-1,Y)&&!find(i-1,jp(X)))Y=i-1;
			else break;
			while((find(X,i)||find(Y,i))&&i<n)i++;
			ans[i]=1;
			if (find(i,X))
			{
				ans[i]*=sz[X]-sz[i];
				if (Y==0)ans[i]*=kk;
				else ans[i]*=sz[Y];
			}
			else 
			{
				ans[i]*=sz[X];
				if (Y==0&&!find(i,jp(X)))ans[i]*=(kk-sz[i]);
				else if (Y==0)ans[i]*=kk;
				else if (find(i,Y))ans[i]*=sz[Y]-sz[i];
				else ans[i]*=sz[Y];
			}
		}
		int sum=0;
		for (int i=0;i<=n;i++)sum+=ans[i];
		ans[1]=n*(n-1)/2-sum;
		for (int i=0;i<=n;i++)cout<<ans[i]<<' ';puts("");
		for (int i=0;i<n;i++)e[i].clear(),ans[i]=de[i]=sz[i]=0;ans[n]=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<=20;j++)f[i][j]=0;
	}
	return 0;
}
/*
1
4
1 0
2 1
3 1
*/