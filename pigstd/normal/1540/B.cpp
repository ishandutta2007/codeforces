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

const int Mod=1e9+7;
const int M=205;
int n,ans,dp[M][M],de[M],fa[M][15];
vector<int>e[M];
int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}
int inv(int x){return poww(x,Mod-2);}

void dfs(int u,int f)
{
	de[u]=de[f]+1,fa[u][0]=f;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to==f)continue;
		dfs(to,u);
	}
}
void init()
{
	for (int j=1;j<=10;j++)
		for (int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}

int LCA(int x,int y)
{
	if (de[x]<de[y])swap(x,y);
	for (int i=10;i>=0;i--)
		if (de[fa[x][i]]>=de[y])x=fa[x][i];
	if (x==y)return x;
	for (int i=10;i>=0;i--)
		if (fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int dis(int x,int y)
{
	return de[x]+de[y]-2*de[LCA(x,y)];
}

signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	for (int i=1;i<=n;i++)dp[0][i]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dp[i][j]=inv(2)*((dp[i][j-1]+dp[i-1][j])%Mod)%Mod;
	for (int k=1;k<=n;k++)
	{
		dfs(k,0);init();
		for (int i=1;i<=n;i++)
			for (int j=1;j<i;j++)
			{
				int lca=LCA(i,j);
				ans=(ans+dp[dis(i,lca)][dis(j,lca)])%Mod;
//				cout<<k<<' '<<i<<' '<<j<<' '<<lca<<' '<<dis(i,lca)<<' '<<dis(j,lca)
//				<<' '<<dp[dis(i,lca)][dis(j,lca)]<<endl;
			}
	}//cout<<ans<<endl;
	ans=ans*inv(n)%Mod;cout<<ans<<endl;
	return 0;
}