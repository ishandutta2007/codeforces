#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2010;
int n,Mod,dp[M][M],sum[M][M],C[M][M],ans[M],tmp[M],pre[M][M],suf[M][M];
vector<int>e[M];

int poww(int a,int b=Mod-2)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void dfs(int u,int fa=0)
{
	vector<int>V;
	for (auto v:e[u])
		if (v!=fa)dfs(v,u),V.pb(v);
	if (u==1)
	{
		for (int i=1;i<n;i++)ans[i]=1;
		for (int i=1;i<n;i++)for (auto v:e[u])ans[i]=ans[i]*sum[v][i]%Mod;
		for (int i=n-1;i>=1;i--)ans[i]=(ans[i]-ans[i-1]+Mod)%Mod;
		for (int i=2;i<n;i++)
			for (int j=1;j<i;j++)
				ans[i]=(ans[i]-ans[j]*C[i-1][j-1]%Mod+Mod)%Mod;
		return;
	}
	memset(tmp,0,sizeof(tmp));int sz=V.size();
	for (int i=1;i<n;i++)
	{
		pre[0][i]=suf[sz+1][i]=1;
		for (int j=1;j<=sz;j++)pre[j][i]=pre[j-1][i]*sum[V[j-1]][i]%Mod;
		for (int j=sz;j>=1;j--)suf[j][i]=suf[j+1][i]*sum[V[j-1]][i]%Mod;
		tmp[i]=dp[u][i]=pre[sz][i];
	}
	for (int j=1;j<=sz;j++)
	{
		int S=0;
		for (int i=1;i<n;i++)
			dp[u][i]=(dp[u][i]+dp[V[j-1]][i]*S)%Mod,S=(S+pre[j-1][i]*suf[j+1][i])%Mod;
	}
	for (int i=1;i<n;i++)
		sum[u][i]=(sum[u][i-1]+dp[u][i])%Mod;
//	cout<<u<<":\n";
//	for (int i=1;i<n;i++)cout<<dp[u][i]<<' ';
//	puts("");
}

signed main()
{
	n=read(),Mod=read();
	for (int i=0;i<n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs(1);
	for (int i=1;i<n;i++)cout<<ans[i]<<' ';
	return 0;
}