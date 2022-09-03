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

const int maxn=250111;

vector<int>g[maxn],leaf;
int n,m,k,dep[maxn],fa[maxn],sz[maxn];

vector<vector<int> > ans;
void dfs(int x,int f,int d)
{
	dep[x]=d;fa[x]=f;sz[x]=1;
	for(auto&v:g[x])if(!dep[v])
	{
		dfs(v,x,d+1);
		sz[x]+=sz[v];
	}
	if(dep[x]*k>=n)
	{
		vector<int> ans;
		int tmp=x;
		while(tmp)
		{
			ans.pb(tmp);
			tmp=fa[tmp];
		}
		printf("PATH\n%d\n",(int)ans.size());
		for(int i=0;i<(int)ans.size();i++)printf("%d%c",ans[i],i==(int)ans.size()-1?'\n':' ');
		exit(0);
	}
	if(sz[x]==1)leaf.pb(x);
}

int main()
{
	get3(n,m,k);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1,0,1);
	
	for(auto&x:leaf)
	{
		int k1=-1,k2=-1,l,r;
		for(auto&v:g[x])if(v!=fa[x])
		{
			if(k1==-1)k1=v;
			else if(k2==-1)k2=v;
		}
		if(dep[k1]>dep[k2])swap(k1,k2);
		if((dep[x]-dep[k1]+1)%3!=0)l=k1,r=fa[x];
		else if((dep[x]-dep[k2]+1)%3!=0)l=k2,r=fa[x];
		else l=k1,r=k2;
		vector<int> cur;cur.pb(x);
		int tmp=r;
		while(true)
		{
			cur.pb(tmp);
			if(tmp==l)break;
			tmp=fa[tmp];
		}
		ans.pb(cur);
		if((int)ans.size()==k)break;
	}
	
	if((int)ans.size()<k)
	{
		puts("-1");
		return 0;
	}
	puts("CYCLES");
	for(int i=0;i<(int)ans.size();i++)
	{
		printf("%d\n",(int)ans[i].size());
		for(int j=0;j<(int)ans[i].size();j++)
			printf("%d%c",ans[i][j],j==(int)ans[i].size()-1?'\n':' ');
	}
	return 0;
}