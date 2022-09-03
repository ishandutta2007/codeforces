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

const int maxn=2000111;

vector<int> g[maxn],rg[maxn];
int n,m,lv[maxn],rv[maxn];

int seq[maxn],scc[maxn],tot;
bool use[maxn];

void dfs1(int x)
{
	use[x]=1;
	for(auto v:g[x])if(!use[v])dfs1(v);
	seq[++tot]=x;
}
void dfs2(int x,int cc)
{
	scc[x]=cc;
	for(auto v:rg[x])if(!scc[v])dfs2(v,cc);
}

void solve()
{
	get2(n,m);
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
		rg[i].clear();
		use[i]=scc[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		get2(lv[i],rv[i]);
		if(lv[i]!=rv[i])
		{
			g[lv[i]].pb(rv[i]);
			rg[rv[i]].pb(lv[i]);
		}
	}
	tot=0;
	for(int i=1;i<=n;i++)if(!use[i])dfs1(i);
	tot=0;
	for(int i=n;i>=1;i--)if(!scc[seq[i]])dfs2(seq[i],++tot);
	if(tot==1)
	{
		puts("No");
		return;
	}
	puts("Yes");
	int c1=0,c2=0;
	for(int i=1;i<=n;i++)if(scc[i]==tot)c1++;else c2++;
	printf("%d %d\n",c1,c2);
	for(int i=1;i<=n;i++)if(scc[i]==tot)printf("%d ",i);puts("");
	for(int i=1;i<=n;i++)if(scc[i]<tot)printf("%d ",i);puts("");
}

int main()
{
	int tc;
	get1(tc);
	while(tc--)solve();
	return 0;
}