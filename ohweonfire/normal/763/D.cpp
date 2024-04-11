// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=100111;
const uLL base=1000000009,b2=998244353;
vector<int> g[maxn];
uLL power[maxn],hs[maxn],down[maxn];

map<uLL,int> cur;
int curans;
void add(uLL x){if((cur[x]++)==0)curans++;}
void era(uLL x){if((--cur[x])==0)curans--;}

int n,f[maxn],sz[maxn],ans[maxn];
void dfs(int x,int f)
{
	sz[x]=1;
	vector<uLL> hsy;
	for(int i=0;i<(int)g[x].size();i++)
		if(g[x][i]!=f)
		{
			dfs(g[x][i],x);
			hsy.pb(hs[g[x][i]]);
			sz[x]+=sz[g[x][i]];
		}
	sort(hsy.begin(),hsy.end());
	for(int i=0;i<(int)hsy.size();i++)
		hs[x]=hs[x]*base+hsy[i];
	hs[x]=hs[x]*base*b2+sz[x];
	add(hs[x]);
}
void dfs2(int x,int f)
{
	era(hs[x]);
	ans[x]=curans;
	
	vector<pair<uLL,int> >hsy;vector<uLL>suf;
	for(int i=0;i<(int)g[x].size();i++)
		if(g[x][i]!=f)
			hsy.pb(mp(hs[g[x][i]],g[x][i]));
		else hsy.pb(mp(down[x],0));
	
	sort(hsy.begin(),hsy.end());
	suf.resize(hsy.size()+1);
	suf[hsy.size()]=0;
	for(int i=hsy.size()-1;i>=0;i--)suf[i]=suf[i+1]+power[(int)hsy.size()-i-1]*hsy[i].ff;
	
	uLL cur=0;
	for(int i=0;i<(int)hsy.size();i++)
	{
		if(hsy[i].ss)
		{
			down[hsy[i].ss]=(cur*power[(int)hsy.size()-i-1]+suf[i+1])*base*b2+n-sz[hsy[i].ss];
			add(down[hsy[i].ss]);
			dfs2(hsy[i].ss,x);
			era(down[hsy[i].ss]);
		}
		cur=cur*base+hsy[i].ff;
	}
	add(hs[x]);
}
int main()
{
	power[0]=1;
	for(int i=1;i<maxn;i++)power[i]=power[i-1]*base;
	
	get1(n);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	dfs2(1,0);
#ifdef EEEEEericKKK
	for(int i=1;i<=n;i++)printf("%I64u ",hs[i]);puts("");
	for(int i=1;i<=n;i++)printf("%I64u ",down[i]);puts("");
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
#endif
	printf("%d\n",max_element(ans+1,ans+n+1)-ans);
	return 0;
}