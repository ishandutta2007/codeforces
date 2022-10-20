#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define LINF 1000000000000000000
#define F first
#define S second
#define mod 777777777
#define N 80010
using namespace std;
struct SegT{
	ll l,r,val[4][4];
}segt[8*N];
ll n,q,w[4][4],ans;
void merg(ll x)
{
	ll a=x<<1;
	ll b=a|1;
	ll i,j,k,l;
	memset(segt[x].val,0,sizeof(segt[x].val));
	for(k=1;k<=3;k++)
	{
		for(l=1;l<=3;l++)
		{
			for(i=1;i<=3;i++)
			{
				for(j=1;j<=3;j++)
				{
					if(w[i][j])
					{
						segt[x].val[k][l]=(segt[x].val[k][l]+((segt[a].val[k][i]*segt[b].val[j][l])%mod))%mod;
					}
				}
			}
		}
	}
	return;
}
void build_tree(ll x,ll l,ll r)
{
	if(l>r)
	{
		return;
	}
	segt[x].l=l;
	segt[x].r=r;
	ll i;
	if(l==r)
	{
		for(i=1;i<=3;i++)
		{
			segt[x].val[i][i]=1;
		}
		return;
	}
	ll mid=(l+r)>>1,a=x<<1;
	build_tree(a,l,mid);
	build_tree(a|1,mid+1,r);
	merg(x);
	return;
}
void upd(ll x,ll l,ll v)
{
	ll tl=segt[x].l,tr=segt[x].r,i;
	if(tl>l||tr<l)
	{
		return;
	}
	if(tl==l&&tr==l)
	{
		memset(segt[x].val,0,sizeof(segt[x].val));
		for(i=1;i<=3;i++)
		{
			if(i==v||v==0)
			{
				segt[x].val[i][i]=1;
			}
		}
		return;
	}
	ll mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		upd(a,l,v);
	}
	else
	{
		upd(a|1,l,v);
	}
	merg(x);
	return;
}
int main(){
	ll i,j,k,l,r,x,v;
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			scanf("%lld",&w[i][j]);
		}
	}
	build_tree(1,0,n-1);
	while(q--)
	{
		scanf("%lld%lld",&x,&v);
		x--;
		upd(1,x,v);
		ans=0;
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				ans=(ans+segt[1].val[i][j])%mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}