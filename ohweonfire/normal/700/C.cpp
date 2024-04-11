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

vector<int> g[1111],id[1111];
int s,t,n,m,f[1111],fid[1111],w[30111],pre[1111];
bool use[1111],can[30111],brg[30111];
void dfs(int x)
{
	use[x]=1;
	for(int i=0;i<(int)g[x].size();i++)
	{
		if(!use[g[x][i]])
		{
			f[g[x][i]]=x;fid[g[x][i]]=id[x][i];
			dfs(g[x][i]);
		}
	}
}
int clk;
int dfs2(int x)
{
	int lowu=pre[x]=++clk;
	for(int i=0;i<(int)g[x].size();i++)
	{
		if(can[id[x][i]])continue;
		if(fid[x]==id[x][i])continue;
		if(!pre[g[x][i]])
		{
			f[g[x][i]]=x;fid[g[x][i]]=id[x][i];
			int lowv=dfs2(g[x][i]);
			lowu=min(lowu,lowv);
			if(lowv>pre[x])brg[id[x][i]]=1;
		}
		else if(pre[g[x][i]]<pre[x])
			lowu=min(lowu,pre[g[x][i]]);
	}
	return lowu;
}
int getans()
{
	clk=0;
	memset(use,0,sizeof(use));
	memset(brg,0,sizeof(brg));
	memset(pre,0,sizeof(pre));
	memset(f,0,sizeof(f));memset(fid,0,sizeof(fid));
	dfs2(s);
	if(!pre[t])return 0;
	int tmp=t,ans=-1;
	while(tmp!=s)
	{
		if(brg[fid[tmp]]&&(ans==-1||w[ans]>w[fid[tmp]]))
			ans=fid[tmp];
		tmp=f[tmp];
	}
	return ans;
}
int main()
{
	get2(n,m);get2(s,t);
	for(int i=1,u,v;i<=m;i++)
	{
		get3(u,v,w[i]);
		g[u].pb(v);id[u].pb(i);
		g[v].pb(u);id[v].pb(i);
	}
	dfs(s);
	if(!use[t])
	{
		puts("0\n0");
		return 0;
	}
	vector<int> es;
	int tmp=t;
	while(tmp!=s)
	{
		es.pb(fid[tmp]);
		tmp=f[tmp];
	}
	int mn=0,mn2=0,val;
	for(int _=0;_<(int)es.size();_++)
	{
		int x=es[_];
		can[x]=1;
		int t=getans();
		if(t==-1)
		{
			can[x]=0;
			continue;
		}
		if(mn==0||val>w[x]+w[t])
		{
			mn=x;mn2=t;
			val=w[x]+w[t];
		}
		can[x]=0;
	}
	if(mn&&mn2)printf("%d\n2\n%d %d\n",val,mn,mn2);
	else if(mn)printf("%d\n1\n%d\n",val,mn);
	else puts("-1");
	return 0;
}