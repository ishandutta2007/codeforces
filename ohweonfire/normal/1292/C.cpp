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
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=3111;
vector<int> g[maxn];
int sz[maxn][maxn],fa[maxn][maxn],dep[maxn][maxn],n;
vector<pii> vs[maxn];
void dfs(int x,int*fa,int*dep,int*sz)
{
	sz[x]=1;
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=fa[x])
	{
		fa[g[x][i]]=x;
		dep[g[x][i]]=dep[x]+1;
		dfs(g[x][i],fa,dep,sz);
		sz[x]+=sz[g[x][i]];
	}
}
LL dp[maxn][maxn];

void calc_dp(int u,int v)
{
	dp[u][v]=dp[v][u]=(LL)sz[u][v]*sz[v][u]+max(dp[fa[u][v]][u],dp[fa[v][u]][v]);
//	printf("u= %d v= %d dp= %lld\n",u,v,dp[u][v]);
}

int main()
{
	get1(n);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for(int i=1;i<=n;i++)
	{
		dfs(i,fa[i],dep[i],sz[i]);
		for(int j=i+1;j<=n;j++)if(i!=j)vs[dep[i][j]].pb(mp(i,j));
	}
	
	LL ans=0;
	for(int i=1;i<=n;i++)for(auto v:vs[i])
	{
		calc_dp(v.ff,v.ss);
		ans=max(ans,dp[v.ff][v.ss]);
	}
	printf("%lld\n",ans);
	
	return 0;
}