#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll q,a[N],c[N],fa[N],f[N][24],sumc[N],suma[N];
bool vis[N];
int main(){
	ll i,tp,p,num,beg,x,v,w;
	scanf("%lld%lld%lld",&q,&a[0],&c[0]);
	for(num=1;num<=q;num++)
	{
		scanf("%lld",&tp);
		if(tp==1)
		{
			scanf("%lld%lld%lld",&p,&a[num],&c[num]);
			sumc[num]=sumc[p]+a[num]*c[num];
			suma[num]=suma[p]+a[num];
			fa[num]=p;
			f[num][0]=p;
			for(i=1;i<24;i++)
			{
				f[num][i]=f[f[num][i-1]][i-1];
			}
		}
		else
		{
			scanf("%lld%lld",&v,&w);
			beg=v;
			for(i=20;i>=0;i--)
			{
				if(!vis[f[beg][i]])
				{
					beg=f[beg][i];
					assert(!vis[beg]);
				}
			}
			//assert(!vis[beg]);
			assert(beg==0||vis[fa[beg]]);
			if(a[beg]>w)
			{
				a[beg]-=w;
				printf("%lld %lld\n",w,w*c[beg]);
				fflush(stdout);
				continue;
			}
			vis[beg]=true;
			if(suma[v]-suma[beg]+a[beg]<w)
			{
				printf("%lld %lld\n",suma[v]-suma[beg]+a[beg],a[beg]*c[beg]+sumc[v]-sumc[beg]);
				fflush(stdout);
				while(!vis[v])//a[v]>0)
				{
					a[v]=0;
					vis[v]=true;
					v=fa[v];
				}
				a[beg]=0;
				continue;
			}
			printf("%lld ",w);
			w-=a[beg];
			ll ans=a[beg]*c[beg];
			a[beg]=0;
			x=v;
			for(i=20;i>=0;i--)
			{
				if(suma[f[x][i]]-suma[beg]>w)
				{
					x=f[x][i];
				}
			}
			ans+=sumc[fa[x]]-sumc[beg];
			w-=(suma[fa[x]]-suma[beg]);
			ans+=c[x]*w;
			a[x]-=w;
			x=fa[x];
			while(!vis[x])
			{
				a[x]=0;
				vis[x]=true;
				x=fa[x];
			}
			printf("%lld\n",ans);
			fflush(stdout);
		}
	}
	return 0;
}