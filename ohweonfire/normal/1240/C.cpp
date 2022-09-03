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

const int maxn=500111;

vector<int> g[maxn],l[maxn];
int n,k;

LL dp[maxn][2];
void dfs(int x,int f=0)
{
	for(auto v:g[x])if(v!=f)dfs(v,x);
	
	vector<LL> vs;
	LL sum=0;
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=f)
	{
		sum+=dp[g[x][i]][0];
		vs.pb(dp[g[x][i]][1]-dp[g[x][i]][0]+l[x][i]);
	}
	sort(vs.begin(),vs.end());reverse(vs.begin(),vs.end());
	
	dp[x][0]=dp[x][1]=sum;
	for(int i=0;i<k&&i<(int)vs.size();i++)if(vs[i]>0)dp[x][0]+=vs[i];
	for(int i=0;i<k-1&&i<(int)vs.size();i++)if(vs[i]>0)dp[x][1]+=vs[i];
}

void solve()
{
	get2(n,k);
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
		l[i].clear();
	}
	for(int i=1,u,v,w;i<n;i++)
	{
		get3(u,v,w);
		g[u].pb(v);g[v].pb(u);
		l[u].pb(w);l[v].pb(w);
	}
	dfs(1);
	printf("%lld\n",dp[1][0]);
}

int main()
{
	int tc;get1(tc);while(tc--)solve();
	return 0;
}