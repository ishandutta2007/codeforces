#include<bits/stdc++.h>
//#define int long long
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
const int M=110;
int n,s[M],ans[M],fac[M],ifac[M],sz[M],tmp[M],tmp2[M];
vector<int>e[M],dp[M],dp2[M];

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=1ll*res*a%Mod;
		a=1ll*a*a%Mod,b>>=1;
	}return res;
}
int inv(int x){return poww(x,Mod-2);} 
void init(int n)
{
	fac[0]=ifac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%Mod,ifac[i]=1ll*ifac[i-1]*inv(i)%Mod;
}
int C(int m,int n){return 1ll*fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;}

void dfs(int u,int fa)
{
	dp[u].pb(1),dp2[u].pb(1);sz[u]=1;
	for (auto to:e[u])
	{
		if (to==fa)continue;
		dfs(to,u);
		memset(tmp,0,sizeof(tmp));
		memset(tmp2,0,sizeof(tmp2));
		for(int i=0;i<sz[u];i++)
			for (int j=0;j<sz[to];j++)
					tmp[i+j]=(tmp[i+j]+1ll*dp[u][i]*dp[to][j])%Mod,
					tmp[i+j+1]=(tmp[i+j+1]+1ll*dp[u][i]*dp2[to][j]%Mod+1ll*dp[to][j]*dp2[u][i]%Mod)%Mod,
					tmp2[i+j]=(tmp2[i+j]+1ll*dp2[u][i]*dp[to][j])%Mod,
					tmp2[i+j+1]=(tmp2[i+j+1]+1ll*dp2[u][i]*dp2[to][j])%Mod;
		sz[u]+=sz[to];dp[to].clear(),dp2[to].clear(),dp[u].clear(),dp2[u].clear();
		for (int i=0;i<sz[u];i++)dp[u].pb(tmp[i]),dp2[u].pb(tmp2[i]);
	}
}

signed main()
{
//	freopen("qwq.txt","r",stdin);
//	freopen("qwq.out","w",stdout);
	n=read();init(n);
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u); 
	}
	dfs(1,0);
	for (int i=0;i<n-1;i++)s[i]=dp[1][i];
	for (int i=0;i<n-1;i++)s[i]=1ll*s[i]*poww(n,n-i-2)%Mod;
	s[n-1]=1;
//	for (int i=0;i<n;i++)cout<<s[i]<<' ';puts("");
	for (int i=n-1;i>=0;i--)
	{
		ans[i]=s[i];
		for (int j=0;j<=i;j++)
			s[j]=(s[j]-1ll*C(i,j)*ans[i]%Mod+Mod)%Mod;
	}
	for (int i=0;i<n;i++)
		printf("%d ",ans[i]);
	return 0;
}