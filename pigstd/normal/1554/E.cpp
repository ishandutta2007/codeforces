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

const int Mod=998244353;
const int M=1e6+10;
int n,ans[M],dp[M][2],cnt,a[M],d,f[M],prime[M];
vector<int>e[M];

void dfs(int u,int fa,int k)
{
	dp[u][0]=dp[u][1]=0;int cnt=0,res=1;
	for (auto to:e[u])
	{
		if (to==fa)continue;
		dfs(to,u,k);if (dp[to][0]!=0)cnt++,res=1ll*res*dp[to][0]%Mod;
		else res=1ll*res*dp[to][1]%Mod;
	}
	if (cnt%k==0)dp[u][0]=res,a[u]=cnt;
	else if ((cnt+1)%k==0)dp[u][1]=res,a[u]=cnt+1;
	d=__gcd(d,a[u]);
	if (u==1&&dp[u][0])ans[d]=1;
}

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=1ll*res*a%Mod;
		a=1ll*a*a%Mod,b>>=1;
	}return res;
}

int main()
{
	for (int i=2;i<=1e6;i++)
	{
		if (f[i])continue;prime[++cnt]=i;
		if (i>1e3)continue;
		for (int j=i*i;j<=1e6;j+=i)
			f[j]=1;//puts("???");
	}
	WT
	{
		n=read();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			e[u].pb(v),e[v].pb(u); 
		}
		for (int i=2;i<n;i++)
			if ((n-1)%i==0&&!f[i])d=0,dfs(1,0,i);
		ans[1]=poww(2,n-1);
		for (int i=2;i<=n;i++)ans[1]=(ans[1]-ans[i]+Mod)%Mod;
		for (int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
		for (int i=1;i<=n;i++)ans[i]=0,e[i].clear();
	}
	return 0;
}