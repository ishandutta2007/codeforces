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
int f[maxn];
int gf(int x)
{
	return x==f[x]?x:f[x]=gf(f[x]);
}
vector<int> g[maxn];

void merge(int u,int v)
{
	if(u>v)return;
	u=gf(u);
	while(u<v)
	{
		f[u]=u+1;
		u=gf(u);
	}
}

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;get2(u,v);
		g[u].pb(v);g[v].pb(u);
	}
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++)
	{
		g[i].pb(0);g[i].pb(n+1);
		sort(g[i].begin(),g[i].end());
		for(int j=1;j<(int)g[i].size();j++)merge(g[i][j-1]+1,g[i][j]-1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<(int)g[i].size();j++)if(g[i][j]>g[i][j-1]+1)f[gf(i)]=gf(g[i][j]-1);
	}
	int cnt=0;for(int i=1;i<=n;i++)if(f[i]==i)cnt++;
	printendl(cnt-1);
	return 0;
}