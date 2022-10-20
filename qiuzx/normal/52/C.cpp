#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 900010
using namespace std;
struct ST{
	ll l,r,val,pd;//val denotes the minimum value of l~r, pd denotes the value that should be added to its sons
}segt[N];
ll n,a[N];
void build_tree(ll x,ll l,ll r)
{
	if(l>r)
	{
		return;
	}
	segt[x].l=l;
	segt[x].r=r;
	segt[x].pd=0;
	if(l==r)
	{
		segt[x].val=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build_tree((x<<(ll)1),l,mid);
	build_tree((x<<(ll)1)+1,mid+1,r);
	segt[x].val=min(segt[(x<<(ll)1)].val,segt[(x<<(ll)1)+1].val);
	return;
}
void push_down(ll x)
{
	segt[(x<<(ll)1)].val+=segt[x].pd;
	segt[(x<<(ll)1)].pd+=segt[x].pd;
	segt[(x<<(ll)1)+1].val+=segt[x].pd;
	segt[(x<<(ll)1)+1].pd+=segt[x].pd;
	segt[x].pd=0;
	return;
}
void update(ll x,ll l,ll r,ll val)
{
	if(segt[x].l>segt[x].r)
	{
		return;
	}
	if(l>segt[x].r||r<segt[x].l)
	{
		return;
	}
	if(l<=segt[x].l&&r>=segt[x].r)
	{
		segt[x].val+=val;
		segt[x].pd+=val;
		return;
	}
	if(segt[x].pd!=0)
	{
		push_down(x);
	}
	ll mid=(segt[x].l+segt[x].r)>>1;
	if(mid>=l)
	{
		update((x<<(ll)1),l,r,val);
	}
	if(mid<r)
	{
		update((x<<(ll)1)+1,l,r,val);
	}
	segt[x].val=min(segt[(x<<(ll)1)].val,segt[(x<<(ll)1)+1].val);
	return;
}
ll getans(ll x,ll l,ll r)
{
	if(segt[x].l>segt[x].r)
	{
		return LINF;
	}
	if(l>segt[x].r||r<segt[x].l)
	{
		return LINF;
	}
	if(l<=segt[x].l&&r>=segt[x].r)
	{
		return segt[x].val;
	}
	if(segt[x].pd!=0)
	{
		push_down(x);
	}
	ll mid=(segt[x].l+segt[x].r)>>1,ret=LINF;
	if(mid>=l)
	{
		ret=min(ret,getans((x<<(ll)1),l,r));
	}
	if(mid<r)
	{
		ret=min(ret,getans((x<<(ll)1)+1,l,r));
	}
	return ret;
}
int main(){
	ll i,q,l,r,val;
	char c;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	build_tree(1,0,n-1);
	scanf("%I64d",&q);
	while(q--)
	{
		scanf("%I64d%I64d",&l,&r);
		scanf("%c",&c);
		if(c==' ')
		{
			scanf("%I64d",&val);
			if(l<=r)
			{
				update(1,l,r,val);
			}
			else
			{
				update(1,0,r,val);
				update(1,l,n-1,val);
			}
		}
		else
		{
			if(l<=r)
			{
				printf("%I64d\n",getans(1,l,r));
			}
			else
			{
				printf("%I64d\n",min(getans(1,0,r),getans(1,l,n-1)));
			}
		}
	}
	return 0;
}