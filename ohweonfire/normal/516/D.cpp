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

const int maxn=100111;

vector<int> g[maxn];
vector<LL> l[maxn];
int n,m;

LL down[maxn],up[maxn];
void dfs(int x,int fa)
{
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=fa)
	{
		dfs(g[x][i],x);
		if(down[g[x][i]]==-1)continue;
		if(down[g[x][i]]+l[x][i]>down[x])down[x]=down[g[x][i]]+l[x][i];
	}
}

void dfs2(int x,int fa)
{
	LL cur_up=up[x];
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=fa)
	{
		if(down[g[x][i]]==-1)continue;
		if(cur_up!=-1)up[g[x][i]]=cur_up+l[x][i];
		if(down[g[x][i]]+l[x][i]>cur_up)cur_up=down[g[x][i]]+l[x][i];
	}
	cur_up=-1;
	for(int i=(int)g[x].size()-1;i>=0;i--)if(g[x][i]!=fa)
	{
		if(down[g[x][i]]==-1)continue;
		if(cur_up!=-1)
		{
			if(cur_up+l[x][i]>up[g[x][i]])up[g[x][i]]=cur_up+l[x][i];
		}
		if(down[g[x][i]]+l[x][i]>cur_up)cur_up=down[g[x][i]]+l[x][i];
		dfs2(g[x][i],x);
	}
}

int pa[maxn],dep[maxn];
LL d[maxn];

void dfs3(int x,int f)
{
	pa[x]=f;
	for(auto v:g[x])if(v!=f)
	{
		dep[v]=dep[x]+1;
		dfs3(v,x);
	}
}

int f[maxn],sz[maxn],ord[maxn];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
bool cmp(int x,int y){return mp(d[x],dep[x])>mp(d[y],dep[y]);}

void activate(int x)
{
//	printf("activate %d\n",x);
	sz[x]=1;
	for(auto v:g[x])if(v!=pa[x])
	{
		f[v]=x;
		sz[x]+=sz[v];
	}
}
void deactivate(int x)
{
//	printf("deactivate %d\n",x);
	sz[gf(x)]--;
}

void solve()
{
	LL val;get1(val);
	
	for(int i=1;i<=n;i++)f[i]=i;
	int cur=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		activate(ord[i]);
		while(cur<n&&d[ord[cur]]>d[ord[i]]+val)
		{
			deactivate(ord[cur]);
			cur++;
		}
		ans=max(ans,sz[ord[i]]);
	}
	printf("%d\n",ans);
}

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
	{
		LL w;
		scanf("%d%d%lld",&u,&v,&w);
		g[u].pb(v);l[u].pb(w);
		g[v].pb(u);l[v].pb(w);
	}
	
	for(int x=1;x<=n;x++)up[x]=down[x]=0;
	dfs(1,0);
	dfs2(1,0);
	
	for(int i=1;i<=n;i++)d[i]=max(up[i],down[i]);
	int mn=min_element(d+1,d+n+1)-d;dfs3(mn,0);
	
	for(int i=1;i<=n;i++)ord[i]=i;sort(ord+1,ord+n+1,cmp);
	
	int q;
	get1(q);
	while(q--)solve();
	
	return 0;
}