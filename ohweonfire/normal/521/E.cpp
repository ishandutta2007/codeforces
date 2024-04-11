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
int n,m;
bool use[maxn];

int fa[maxn],dfn[maxn],edfn[maxn],timer,cnt[maxn];

vector<int> getp(int u,int v)
{
	bool rev=0;
	if(dfn[u]<dfn[v])
	{
		rev=1;
		swap(u,v);
	}
	vector<int> ret;
	while(u!=v)
	{
		ret.pb(u);
		u=fa[u];
	}
	ret.pb(u);
	if(rev)reverse(ret.begin(),ret.end());
	return ret;
}

void find_path(int piv1)
{
	pii e1=mp(0,0),e2=mp(0,0);
	for(int x=1;x<=n;x++)if(dfn[x]>=dfn[piv1]&&dfn[x]<=edfn[piv1])
	{
		for(auto v:g[x])if(dfn[v]<dfn[piv1]&&(x!=piv1||v!=fa[piv1]))
		{
			if(!e1.ff)e1=mp(x,v);
			else e2=mp(x,v);
		}
	}
	if(dfn[e1.ss]<dfn[e2.ss])swap(e1,e2);
	int piv2=e1.ss;
	vector<int> v1,v2,v3,tmp;
	v1=getp(piv1,piv2);
	v2=getp(piv1,e1.ff);v2.pb(piv2);
	v3=getp(piv1,e2.ff);tmp=getp(e2.ss,piv2);for(auto v:tmp)v3.pb(v);
	puts("YES");
	printf("%d ",(int)v1.size());for(int i=0;i<(int)v1.size();i++)printf("%d%c",v1[i],i==(int)v1.size()-1?'\n':' ');
	printf("%d ",(int)v2.size());for(int i=0;i<(int)v2.size();i++)printf("%d%c",v2[i],i==(int)v2.size()-1?'\n':' ');
	printf("%d ",(int)v3.size());for(int i=0;i<(int)v3.size();i++)printf("%d%c",v3[i],i==(int)v3.size()-1?'\n':' ');
	exit(0);
}

void dfs(int x,int f=0)
{
	fa[x]=f;dfn[x]=++timer;use[x]=1;
	for(auto v:g[x])
	{
		if(!use[v])
		{
			dfs(v,x);
			cnt[x]+=cnt[v];
		}
		else if(v!=f&&dfn[v]<dfn[x])
		{
			cnt[x]++;
			cnt[v]--;
		}
	}
	edfn[x]=timer;
	if(cnt[x]>1)find_path(x);
}

int main()
{
	get2(n,m);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1;i<=n;i++)if(!use[i])dfs(i);
	puts("NO");
	return 0;
}