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

const int maxn=2111;

vector<int> g[maxn];
int n,p[maxn],c[maxn],sz[maxn],ans[maxn];

void dfs(int x)
{
	sz[x]=1;
	for(auto v:g[x])
	{
		dfs(v);
		sz[x]+=sz[v];
	}
	if(c[x]>=sz[x])
	{
		puts("NO");
		exit(0);
	}
}

void dfs2(int x,vector<int>&vs)
{
	ans[x]=vs[c[x]];
	int cur=0;
	for(auto v:g[x])
	{
		vector<int> nv;
		for(int i=0;i<sz[v];i++)
		{
			if(vs[cur]==ans[x])cur++;
			nv.pb(vs[cur]);
			cur++;
		}
		dfs2(v,nv);
	}
}

int main()
{
	get1(n);
	int rt=0;
	for(int i=1;i<=n;i++)
	{
		get2(p[i],c[i]);
		if(p[i])g[p[i]].pb(i);
		else rt=i;
	}
	dfs(rt);
	vector<int> vs;for(int i=1;i<=n;i++)vs.pb(i);
	dfs2(rt,vs);
	puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}