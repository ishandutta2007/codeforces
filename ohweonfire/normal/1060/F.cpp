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

vector<int> g[55];
int n,sz[55];
LL c[55][55];
double dp[55][55],tmp[111],dp2[111];
void dfs(int x,int f)
{
	sz[x]=1;
	dp[x][0]=1;
	for(auto&v:g[x])if(v!=f)
		dfs(v,x);
	for(auto&v:g[x])if(v!=f)
	{
		for(int i=0;i<=sz[v];i++)
		{
			double p=0.0;
			for(int j=i+1;j<=sz[v];j++)
				p+=dp[v][j-1]*0.5/sz[v];
			if(i)p+=dp[v][i-1]*i/sz[v];
			tmp[i]=p;
		}
		for(int i=0;i<sz[x]+sz[v];i++)dp2[i]=0.0;
		for(int i=0;i<sz[x];i++)for(int j=0;j<=sz[v];j++)
			dp2[i+j]=dp2[i+j]+dp[x][i]*tmp[j]*c[i+j][i]*c[sz[x]+sz[v]-1-i-j][sz[v]-j]/c[sz[x]+sz[v]-1][sz[v]];
		sz[x]+=sz[v];
		for(int i=0;i<sz[x];i++)dp[x][i]=dp2[i];
	}
}
int main()
{
	for(int i=0;i<55;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	get1(n);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,0);
		printf("%.10lf\n",dp[i][0]);
	}
	return 0;
}