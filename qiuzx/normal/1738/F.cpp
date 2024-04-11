//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1010
using namespace std;
ll n,deg[N],ord[N],fa[N];
bool vis[N];
ll getf(ll x)
{
	return (x==fa[x])?x:fa[x]=getf(fa[x]);
}
bool cmp(ll x,ll y)
{
	return (deg[x]>deg[y]);
}
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&deg[i]);
			ord[i]=i;
			fa[i]=i;
			vis[i]=false;
		}
		sort(ord,ord+n,cmp);
		for(i=0;i<n;i++)
		{
			ll x=ord[i];
			if(vis[x])
			{
				continue;
			}
			vis[x]=true;
			for(j=0;j<deg[x];j++)
			{
				printf("? %lld\n",x+1);
				fflush(stdout);
				ll y;
				scanf("%lld",&y);
				y--;
				if(vis[y])
				{
					fa[getf(x)]=getf(y);
					break;
				}
				vis[y]=true;
				fa[getf(y)]=getf(x);
			}
		}
		printf("! ");
		for(i=0;i<n;i++)
		{
			printf("%lld ",getf(i)+1);
		}
		puts("");
		fflush(stdout);
	}
	return 0;
}