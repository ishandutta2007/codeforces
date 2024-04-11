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
const LL Linf=1ll<<62;
const double pi=acos(-1.0);

int f[100111],sz[100111];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
void un(int x,int y)
{
	x=gf(x);
	y=gf(y);
	if(x==y)return;
	sz[x]+=sz[y];
	f[y]=x;
}

int n,x[100111],y[100111],d[100111],ord[100111];
LL ans[100111];
bool cmp(int x,int y){return d[x]<d[y];}
vector<int> g[100111],eid[100111];
bool use[100111];
int dfs(int x,int fid=0)
{
	use[x]=1;
	int sz=::sz[x];
	for(int i=0;i<(int)g[x].size();i++)
		if(eid[x][i]!=fid)
			sz+=dfs(g[x][i],eid[x][i]);
	ans[fid]=sz;
	return sz;
}
int main()
{
	get1(n);
	for(int i=1;i<n;i++)
	{
		get3(x[i],y[i],d[i]);
		ord[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		sz[i]=1;
	}
	sort(ord+1,ord+n,cmp);
	for(int i=1,j;i<n;i=j)
	{
		for(j=i;j<n&&d[ord[i]]==d[ord[j]];j++);
		vector<int>ids;
		for(int k=i;k<j;k++)
		{
			int tx=x[ord[k]],ty=y[ord[k]];
			tx=gf(tx);ty=gf(ty);
			ids.pb(tx);ids.pb(ty);
			g[tx].pb(ty);g[ty].pb(tx);
			eid[tx].pb(ord[k]);eid[ty].pb(ord[k]);
		}
		for(auto x:ids)
		{
			if(!use[x])
				dfs(x);
		}
		for(auto x:ids){g[x].clear();eid[x].clear();use[x]=0;}
		for(int k=i;k<j;k++)un(x[ord[k]],y[ord[k]]);
		for(int k=i;k<j;k++)
		{
			int sz=::sz[gf(x[ord[k]])];
			ans[ord[k]]*=(sz-ans[ord[k]]);
		}
	}
	LL mx=*max_element(ans+1,ans+n);int cnt=0;
	for(int i=1;i<n;i++)cnt+=(mx==ans[i]);
	printf("%I64d %d\n",mx*2,cnt);
	for(int i=1;i<n;i++)if(mx==ans[i])printf("%d ",i);
	return 0;
}