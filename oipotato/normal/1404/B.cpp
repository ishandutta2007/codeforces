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
int dep[N];
vector<int>g[N];
void dfs(int p,int fa)
{
	for(auto i:g[p])if(i!=fa)dep[i]=dep[p]+1,dfs(i,p);
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,a,b,da,db;
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		rep(i,n)g[i].clear();
		rep(i,n-1){int x,y;scanf("%d%d",&x,&y);g[x].pb(y);g[y].pb(x);}
		dep[a]=0;dfs(a,0);
		if(dep[b]<=da||db<=2*da){puts("Alice");continue;}
		int R=a;rep(i,n)if(dep[i]>dep[R])R=i;
		dep[R]=0;dfs(R,0);
		rep(i,n)if(dep[i]>dep[R])R=i;
		puts(dep[R]<=2*da?"Alice":"Bob");
	}
	return 0;
}