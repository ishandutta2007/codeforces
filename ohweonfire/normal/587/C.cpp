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

struct data
{
	int num,a[10];
	void clear(){num=0;memset(a,0,sizeof(a));}
	data(){clear();}
	data(int x){num=1;a[0]=x;}
	data operator +(const data&b)const
	{
		data ret;
		int ti=0,tj=0;int&tk=ret.num;
		while(ti<num&&tj<b.num&&tk<10)
		{
			if(a[ti]<b.a[tj])ret.a[tk++]=a[ti++];
			else ret.a[tk++]=b.a[tj++];
		}
		while(ti<num&&tk<10)ret.a[tk++]=a[ti++];
		while(tj<b.num&&tk<10)ret.a[tk++]=b.a[tj++];
		return ret;
	}
}val[100111][20];
vector<int> g[100111];
int n,m,q,f[100111][20],dep[100111];
void dfs(int x)
{
	for(int i=0;i<(int)g[x].size();i++)
	{
		if(g[x][i]==f[x][0])continue;
		f[g[x][i]][0]=x;dep[g[x][i]]=dep[x]+1;
		dfs(g[x][i]);
	}
}
data query(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	data ret;
	for(int i=19;i>=0;i--)if((dep[u]-dep[v])>>i)
	{
		ret=ret+val[u][i];
		u=f[u][i];
	}
	if(u==v)return ret+val[u][0];
//	printf("u= %d v= %d\n",u,v);
	for(int i=19;i>=0;i--)if(f[u][i]!=f[v][i])
	{
		ret=ret+val[u][i]+val[v][i];
		u=f[u][i];
		v=f[v][i];
	}
	return ret+val[u][1]+val[v][0];
}
int main()
{
	get3(n,m,q);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	for(int i=1,x;i<=m;i++)
	{
		get1(x);
		val[x][0]=val[x][0]+data(i);
	}
	for(int j=1;j<20;j++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
			val[i][j]=val[i][j-1]+val[f[i][j-1]][j-1];
		}
	}
	for(int i=1,u,v,a;i<=q;i++)
	{
		get3(u,v,a);
		data t=query(u,v);
		a=min(a,t.num);
		printf("%d ",a);for(int j=0;j<a;j++)printf("%d ",t.a[j]);puts("");
	}
	return 0;
}