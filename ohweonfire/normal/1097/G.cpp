// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=100111;
const int mod=1e9+7;

int pw2[maxn],ipw2[maxn],coef[maxn],n,k,s[211][211],fac[211];
vector<int> g[maxn];

int dp[maxn][211],len[maxn],sz[maxn],tmp[411],ans[211];
void dfs(int x,int f)
{
	dp[x][0]=1;sz[x]=1;
	for(auto&v:g[x])if(v!=f)
	{
		dfs(v,x);
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<=len[v];i++)
		{
			for(int j=0;j<=len[x]&&i+j<=k;j++)
				tmp[i+j]=(tmp[i+j]+(LL)dp[v][i]*dp[x][j])%mod;
		}
		len[x]=min(len[x]+len[v],k);
		sz[x]+=sz[v];
		for(int i=0;i<=len[x];i++)dp[x][i]=tmp[i];
	}
	if(f)
	{
		for(int i=k-1;i>=0;i--)
		{
			int cur=dp[x][i];
			if(i==0)cur=(LL)cur*coef[sz[x]]%mod;
			dp[x][i+1]+=cur;
			if(dp[x][i+1]>=mod)dp[x][i+1]-=mod;
			cur=(LL)cur*(coef[n-sz[x]]+mod-1)%mod;
			ans[i+1]+=cur;
			if(ans[i+1]>=mod)ans[i+1]-=mod;
		}
		len[x]=min(k,len[x]+1);
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			ans[i]+=dp[x][i];
			if(ans[i]>=mod)ans[i]-=mod;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	pw2[0]=1;for(int i=1;i<maxn;i++)pw2[i]=pw2[i-1]*2%mod;
	ipw2[0]=1;for(int i=1;i<maxn;i++)ipw2[i]=(LL)ipw2[i-1]*(mod+1)/2%mod;
	for(int i=0;i<maxn;i++)coef[i]=(LL)(pw2[i]-1)*ipw2[i]%mod;
	
	dfs(1,0);
	
	s[0][0]=fac[0]=1;
	for(int i=1;i<=k;i++)fac[i]=(LL)i*fac[i-1]%mod;
	for(int i=1;i<=k;i++)for(int j=1;j<=i;j++)
		s[i][j]=(s[i-1][j-1]+(LL)j*s[i-1][j])%mod;
	
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		ans[i]=(LL)ans[i]*pw2[n]%mod;
		sum=(sum+(LL)ans[i]*fac[i]%mod*s[k][i])%mod;
	}
	printendl(sum);
	return 0;
}