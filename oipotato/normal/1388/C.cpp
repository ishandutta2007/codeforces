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
const int N=100010;
int siz[N],num[N],h[N];
vector<int>g[N];
bool flag;
void dfs(int p,int fa)
{
	long long sigh=0;
	siz[p]=num[p];
	for(auto i:g[p])
	{
		if(i==fa)continue;
		dfs(i,p);
		siz[p]+=siz[i];
		sigh+=h[i];
	}
	if(!(sigh-num[p]<=h[p]&&h[p]<=siz[p]&&(h[p]&1)==(siz[p]&1)))flag=0;
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		rep(i,n)scanf("%d",&num[i]);
		rep(i,n)scanf("%d",&h[i]);
		rep(i,n)g[i].clear();
		rep(i,n-1){int x,y;scanf("%d%d",&x,&y);g[x].pb(y);g[y].pb(x);}
		flag=1;
		dfs(1,0);
		puts(flag?"YES":"NO");
	}
	return 0;
}