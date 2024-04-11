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
#define N 200010
using namespace std;
struct SegT{
	ll l,r,val,pd;
}segt[8*N];
ll n,q,l[N],r[N];
char buf[N];
string s,t;
void build_tree(ll x,ll l,ll r)
{
	segt[x].val=0;
	segt[x].pd=-1;
	if(l>r)
	{
		return;
	}
	segt[x].l=l;
	segt[x].r=r;
	if(l==r)
	{
		segt[x].val=(t[l]-'0');
		return;
	}
	ll mid=(l+r)>>1,a=x<<1;
	build_tree(a,l,mid);
	build_tree(a|1,mid+1,r);
	segt[x].val=segt[a].val+segt[a|1].val;
	return;
}
void push_down(ll x)
{
	ll a=x<<1;
	segt[a].val=segt[x].pd*(segt[a].r-segt[a].l+1);
	segt[a].pd=segt[x].pd;
	segt[a|1].val=segt[x].pd*(segt[a|1].r-segt[a|1].l+1);
	segt[a|1].pd=segt[x].pd;
	segt[x].pd=-1;
	return;
}
void update(ll x,ll l,ll r,ll v)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(tl>r||tr<l)
	{
		return;
	}
	if(segt[x].pd!=-1)
	{
		push_down(x);
	}
	if(l<=tl&&tr<=r)
	{
		segt[x].val=(tr-tl+1)*v;
		segt[x].pd=v;
		push_down(x);
		return;
	}
	ll a=x<<1,mid=(tl+tr)>>1;
	if(mid>=l)
	{
		update(a,l,r,v);
	}
	if(mid<r)
	{
		update(a|1,l,r,v);
	}
	segt[x].val=segt[a].val+segt[a|1].val;
	return;
}
ll query(ll x,ll l,ll r)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(tl>r||tr<l)
	{
		return 0;
	}
	if(segt[x].pd!=-1)
	{
		push_down(x);
	}
	if(l<=tl&&tr<=r)
	{
		return segt[x].val;
	}
	ll ret=0,mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		ret+=query(a,l,r);
	}
	if(mid<r)
	{
		ret+=query(a|1,l,r);
	}
	return ret;
}
int main(){
	ll T,i,z,o;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&q);
		scanf("%s",&buf);
		s=buf;
		scanf("%s",&buf);
		t=buf;
		for(i=0;i<q;i++)
		{
			scanf("%lld%lld",&l[i],&r[i]);
			l[i]--;
			r[i]--;
		}
		build_tree(1,0,n-1);
		for(i=q-1;i>=0;i--)
		{
			o=query(1,l[i],r[i]);
			z=r[i]-l[i]+1-o;
			if(z==o)
			{
				i=INF;
				break;
			}
			if(z<o)
			{
				update(1,l[i],r[i],1);
			}
			else
			{
				update(1,l[i],r[i],0);
			}
		}
		if(i==INF)
		{
			puts("NO");
			continue;
		}
		z=0;
		for(i=0;i<n;i++)
		{
			o=query(1,0,i);
			z+=(s[i]-'0');
			if(o!=z)
			{
				i=INF;
				break;
			}
		}
		if(i==INF)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
		}
	}
	return 0;
}