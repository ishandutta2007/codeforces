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

vector<pair<pii,int> >cmd;
int n;
vector<int> g[200111];
struct centroid
{
	int sz[200111],mx[200111];
	void dfs(int x,int f=0)
	{
		sz[x]=1;
		for(int i=0;i<(int)g[x].size();i++)
			if(g[x][i]!=f)
			{
				dfs(g[x][i],x);
				sz[x]+=sz[g[x][i]];
				mx[x]=max(mx[x],sz[g[x][i]]);
			}
		mx[x]=max(mx[x],n-sz[x]);
	}
	void find(int&c1,int&c2)
	{
		dfs(1);
		c1=min_element(mx+1,mx+n+1)-mx;
		c2=min_element(mx+c1+1,mx+n+1)-mx;
		if(mx[c1]!=mx[c2])c2=0;
	}
}m1;

vector<pii> v;
void dfs(int x,int pre)
{
	for(int i=0;i<(int)g[x].size();i++)
		if(g[x][i]!=pre)
			dfs(g[x][i],x);
	v.pb(mp(x,pre));
}
void go(int x,int pre)
{
	int tpre=pre;
	v.clear();dfs(x,pre);
	for(int i=0;i<(int)v.size();i++)
	{
		if(x!=v[i].ff)cmd.pb(mp(mp(pre,x),v[i].ff));
		pre=v[i].ff;x=v[i].ss;
	}
	if(v.size()<=2)return;
	int cent=v[(int)v.size()-2].ff;
	for(int i=(int)v.size()-3;i>=0;i--)
	{
		if(i==0)pre=tpre;else pre=v[i-1].ff;
		cmd.pb(mp(mp(pre,v[i].ff),cent));
	}
}
int main()
{
	get1(n);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);g[v].pb(u);
	}
	int c1,c2;m1.find(c1,c2);
//	printf("centroid= %d %d\n",c1,c2);
	for(int i=0;i<(int)g[c1].size();i++)if(g[c1][i]!=c2)
		go(g[c1][i],c1);
	for(int i=0;i<(int)g[c2].size();i++)if(g[c2][i]!=c1)
		go(g[c2][i],c2);
		
	printf("%d\n",(int)cmd.size());
	for(int i=0;i<(int)cmd.size();i++)printf("%d %d %d\n",cmd[i].ff.ff,cmd[i].ff.ss,cmd[i].ss);
	return 0;
}