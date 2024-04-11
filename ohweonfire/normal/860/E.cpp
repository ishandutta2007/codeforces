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

vector<int> g[500111],layer[500111];
int n,p[500111],rt,f[22][500111],dep[500111];
int a[500111],stk[500111],top,cnt[500111];
LL ans[500111],sum[500111];
void dfs(int x,int d=1)
{
	dep[x]=d;layer[d].pb(x);
	for(int i=0;i<(int)g[x].size();i++)dfs(g[x][i],d+1);
}
void dfs2(int x)
{
	for(int i=0;i<(int)g[x].size();i++)
	{
		ans[g[x][i]]+=ans[x]+dep[x];
		dfs2(g[x][i]);
	}
}
int getlca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;i>=0;i--)if((dep[u]-dep[v]>>i)&1)u=f[i][u];
	if(u==v)return u;
	for(int i=19;i>=0;i--)if(f[i][u]!=f[i][v]){u=f[i][u];v=f[i][v];}
	return f[0][u];
}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(p[i]);
		if(p[i]==0)rt=i;
		else g[p[i]].pb(i);
	}
	memcpy(f[0],p,sizeof(p));
	for(int i=1;i<20;i++)for(int j=1;j<=n;j++)f[i][j]=f[i-1][f[i-1][j]];
	dfs(rt);
	for(int i=1;i<=n;i++)
	{
		int sz=(int)layer[i].size();if(sz<=1)continue;
		for(int j=1;j<sz;j++)a[j]=dep[getlca(layer[i][j-1],layer[i][j])];
		for(int j=0;j<=sz;j++)cnt[j]=sum[j]=0;top=0;
		for(int j=1;j<sz;j++)
		{
			int all=1;
			while(top&&a[stk[top]]>=a[j])
			{
				all+=cnt[top];
				top--;
			}
			stk[++top]=j;
			cnt[top]=all;
			sum[top]=sum[top-1]+1ll*cnt[top]*a[j];
			ans[layer[i][j]]+=sum[top];
		}
		
		for(int j=0;j<=sz;j++)cnt[j]=sum[j]=0;top=0;
		for(int j=sz-1;j>0;j--)
		{
			int all=1;
			while(top&&a[stk[top]]>=a[j])
			{
				all+=cnt[top];
				top--;
			}
			stk[++top]=j;
			cnt[top]=all;
			sum[top]=sum[top-1]+1ll*cnt[top]*a[j];
			ans[layer[i][j-1]]+=sum[top];
		}
	}
	dfs2(rt);
	for(int i=1;i<=n;i++)printf("%I64d ",ans[i]);
	return 0;
}