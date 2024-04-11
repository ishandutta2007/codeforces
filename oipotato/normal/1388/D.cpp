#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=200010;
vector<int>ansp,g[N];
long long f[N],ans;
int a[N],n,fa[N];
void dfs(int p)
{
	f[p]=a[p];
	for(auto i:g[p])
	{
		dfs(i);
		if(f[i]>0)f[p]+=f[i];
	}
	ans+=f[p];
}
void print(int p)
{
	for(auto i:g[p])if(f[i]>0)print(i);
	ansp.pb(p);
	for(auto i:g[p])if(f[i]<=0)print(i);
}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)
	{
		int x;scanf("%d",&x);
		if(x==-1)continue;
		g[x].pb(i);fa[i]=x;
	}
	rep(i,n)if(!fa[i])dfs(i),print(i);
	printf("%lld\n",ans);
	rep(i,n)printf("%d%c",ansp[i-1]," \n"[i==n]);
	return 0;
}