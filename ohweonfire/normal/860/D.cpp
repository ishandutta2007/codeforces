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

vector<int> g[200111],id[200111],ver,have[200111];
set<int>e;
int n,m,u[200111],v[200111],fid[200111],to[200111],now[200111];
bool use[200111];
void dfs(int x,int f=0)
{
	ver.pb(x);use[x]=1;
	for(int i=0;i<(int)g[x].size();i++)
	{
		if(g[x][i]==f)continue;
		e.insert(id[x][i]);
		if(!use[g[x][i]])
		{
			fid[g[x][i]]=id[x][i];
			dfs(g[x][i],x);
		}
	}
}
vector<pair<pii,int> >cmd;
void add(int i,int j,int x)
{
	if(v[i]!=x)swap(v[i],u[i]);if(u[j]!=x)swap(u[j],v[j]);
	cmd.pb(mp(mp(u[i],v[i]),v[j]));
}
int main()
{
	get2(n,m);
	for(int i=1;i<=m;i++)
	{
		get2(u[i],v[i]);
		g[u[i]].pb(v[i]);
		g[v[i]].pb(u[i]);
		id[u[i]].pb(i);
		id[v[i]].pb(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(use[i])continue;
		ver.clear();e.clear();
		dfs(i);
		reverse(ver.begin(),ver.end());
		for(auto x:e){now[u[x]]^=1;to[x]=0;}
		for(auto x:ver)
		{
			if(!fid[x])break;
			if(now[x])
			{
				now[x]=0;
				now[u[fid[x]]+v[fid[x]]-x]^=1;
				to[fid[x]]^=1;
			}
		}
	}
	for(int i=1;i<=m;i++)if(to[i])have[v[i]].pb(i);else have[u[i]].pb(i);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<(int)have[i].size();j+=2)
			add(have[i][j],have[i][j-1],i);
	}
	printf("%d\n",(int)cmd.size());
	for(auto x:cmd)printf("%d %d %d\n",x.ff.ff,x.ff.ss,x.ss);
	return 0;
}