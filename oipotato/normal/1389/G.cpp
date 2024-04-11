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
const int N=300010;
const int M=N;
typedef long long ll;
struct EDGE { int adj, next; } edge[M<<1];
int top, gh[N];
int dfn[N], low[N], cnt, ind, stop, instack[N], stack[N], belong[N];
void addedge(int x, int y) {
	edge[++top].adj = y;
	edge[top].next = gh[x];
	gh[x] = top;
}
void tarjan(int x,int fa) {
	dfn[x] = low[x] = ++ind;
	instack[x] = 1; stack[++stop] = x;
	for (int p=gh[x]; p; p=edge[p].next)
		if (!dfn[edge[p].adj]) {
			tarjan(edge[p].adj,x);
			low[x] = min(low[x], low[edge[p].adj]);
		} else if (edge[p].adj!=fa && instack[edge[p].adj]) {
			low[x] = min(low[x], dfn[edge[p].adj]);
		}
	if (dfn[x] == low[x]) {
		++cnt; int tmp=0;
		while (tmp!=x) {
			tmp = stack[stop--];
			belong[tmp] = cnt;
			instack[tmp] = 0;
		}
	}
}
vector<pair<int,int>>g[N];
ll f[N],ans,C[N];
int x[M],y[M],c[N],w[M],n,m,k,key[N],siz[N];
void dfs(int p,int fa)
{
	f[p]=C[p];
	for(auto i:g[p])
	{
		int x=i.first;
		if(x==fa)continue;
		dfs(x,p);
		siz[p]+=siz[x];
		if(0<siz[x]&&siz[x]<k)f[p]+=max(0ll,f[x]-i.second);else f[p]+=f[x];
	}
}
void work(int p,int fa,ll F)
{
	f[p]+=F;
	for(auto i:g[p])
	{
		int x=i.first;
		if(x==fa)continue;
		work(x,p,max(0ll,f[p]-max(0ll,f[x]-(0<siz[x]&&siz[x]<k)*i.second)-(0<siz[x]&&siz[x]<k)*i.second));
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,k)scanf("%d",&key[i]);
	rep(i,n)scanf("%d",&c[i]);
	rep(i,m)scanf("%d",&w[i]);
	rep(i,m)scanf("%d%d",&x[i],&y[i]),addedge(x[i],y[i]),addedge(y[i],x[i]);
	tarjan(1,0);
	rep(i,n)C[belong[i]]+=c[i];
	rep(i,k)siz[belong[key[i]]]++;
	rep(i,m)if(belong[x[i]]!=belong[y[i]])g[belong[x[i]]].pb(mp(belong[y[i]],w[i])),g[belong[y[i]]].pb(mp(belong[x[i]],w[i]));
	dfs(1,0);
	work(1,0,0ll);
	rep(i,n)printf("%lld%c",f[belong[i]]," \n"[i==n]);
	return 0;
}