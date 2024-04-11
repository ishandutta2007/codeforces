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

const int maxn=200111;

vector<int> g[maxn];
int n,k,fa[20][maxn],dep[maxn];
void dfs(int x,int f,int d)
{
	fa[0][x]=f;for(int i=1;i<20;i++)fa[i][x]=fa[i-1][fa[i-1][x]];
	dep[x]=d;
	for(auto v:g[x])if(v!=f)dfs(v,x,d+1);
}
int getlca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;i>=0;i--)if(dep[u]-dep[v]>>i)u=fa[i][u];
	if(u==v)return u;
	for(int i=19;i>=0;i--)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
int getdist(int u,int v){return dep[u]+dep[v]-dep[getlca(u,v)]*2+1;}

int getfar(int u)
{
	int ret=0,d=0;
	for(int i=1;i<=n;i++)
	{
		int nd=getdist(u,i);
		if(nd>d)
		{
			d=nd;
			ret=i;
		}
	}
	return ret;
}

int ans[maxn];
int main()
{
	get2(n,k);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0,0);
	
	if(k==2)
	{
		puts("Yes");
		for(int i=1;i<=n;i++)printf("%d ",getdist(1,i)%2+1);
		return 0;
	}
	
	int u,v=1,c,d;
	u=getfar(v);
	v=getfar(u);
	d=getdist(u,v);
	ans[u]=1;
	ans[v]=d%k;
	for(int i=1;i<=n;i++)
	{
		int du=getdist(i,u),dv=getdist(i,v);
		if(d==du+dv-1)ans[i]=du%k;
		else if(du>=k&&dv>=k)
		{
			puts("No");
			return 0;
		}
		else if(du>=dv)ans[i]=du%k;
		else ans[i]=((ans[v]-dv+1)%k+k)%k;
	}
	puts("Yes");
	for(int i=1;i<=n;i++)printf("%d ",ans[i]+1);
	return 0;
}