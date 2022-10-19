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
#define ll int
#define N 300010
using namespace std;
struct SegT{
	ll l,r,id;
}segt[4*N];
ll n,q,a[N];
vector<ll> vt[N];
ll get_app(ll l,ll r,ll x)
{
	return upper_bound(vt[x].begin(),vt[x].end(),r)-lower_bound(vt[x].begin(),vt[x].end(),l);
}
void build_tree(ll x,ll l,ll r)
{
	if(l>r)
	{
		return;
	}
	segt[x].l=l;
	segt[x].r=r;
	if(l==r)
	{
		segt[x].id=a[l];
		return;
	}
	ll mid=(l+r)>>1,a=x<<1;
	build_tree(a,l,mid);
	build_tree(a|1,mid+1,r);
	if(get_app(l,r,segt[a].id)>get_app(l,r,segt[a|1].id))
	{
		segt[x].id=segt[a].id;
	}
	else
	{
		segt[x].id=segt[a|1].id;
	}
	return;
}
ll query(ll x,ll l,ll r)
{
	ll tl=segt[x].l,tr=segt[x].r;
	if(l>tr||tl>r)
	{
		return -1;
	}
	if(l<=tl&&tr<=r)
	{
		return get_app(l,r,segt[x].id);
	}
	ll a=x<<1;
	return max(query(a,l,r),query(a|1,l,r));
}
int main(){
	ll i,v,l,r;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		vt[a[i]].push_back(i);
	}
	build_tree(1,0,n-1);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		l--;
		r--;
		v=query(1,l,r);
		if(v<=(r-l+2)/2)
		{
			puts("1");
		}
		else
		{
			printf("%d\n",2*v-(r-l+1));
		}
	}
	return 0;
}