#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=300010;
vector<int>g[N];
int a[N],dep[N],fa[N],tim,now,n;
LL ans;
void fuck(){puts("NO");exit(0);}
bool cmp(int x,int y){return a[x]<a[y];}
void dfs(int p)
{
	for(auto i:g[p])dep[i]=dep[p]+1,fa[i]=p,dfs(i);
}
void check(int p)
{
	for(auto i:g[p])check(i);
	if(tim!=a[p])fuck();tim++;ans+=dep[p];
}
void work(int p)
{
	if(a[p]!=now)fuck();now++;
	for(auto i:g[p])
	if(a[i]<a[1])check(i);
	else
	{
		work(i);
		if(tim!=a[1])fuck();
	}
}
void print(int p)
{
	a[p]=tim++;
	for(auto i:g[p])print(i);
}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n-1){int x,y;scanf("%d%d",&x,&y);g[x].pb(y);}
	rep(i,n)sort(g[i].begin(),g[i].end(),cmp);
	dep[1]=0;
	dfs(1);
	if(a[1]>1)
	{
		int x;
		rep(i,n)if(a[i]==a[1]-1)x=i;
		for(;x!=1;)
		{
			int f=fa[x];
			if(a[f]<a[x])fuck();
			for(auto i:g[f])
			{
				if(i==x)break;
				if(a[i]>a[x])fuck();
			}
			swap(a[f],a[x]);
			ans++;
			x=f;
		}
		rep(i,n)
		{
			int last=0;
			for(auto j:g[i]){if(a[j]<last)fuck();last=a[j];}
		}
	}
	tim=1;now=a[1];
	work(1);
	tim=1;
	print(1);
	puts("YES");
	printf("%lld\n",ans);
	rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}