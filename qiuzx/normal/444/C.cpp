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
#define N 1000010
using namespace std;
struct ST{
	ll l,r,col,val,pd;
	bool sm;
}segt[N];
ll n;
void build_tree(ll x,ll l,ll r)
{
	if(l>r)
	{
		return;
	}
	segt[x].l=l;
	segt[x].r=r;
	segt[x].val=0;
	segt[x].pd=0;
	segt[x].sm=false;
	segt[x].col=-1;
	if(l==r)
	{
		segt[x].sm=true;
		segt[x].col=l;
		return;
	}
	ll mid=(l+r)>>1;
	build_tree((x<<(ll)1),l,mid);
	build_tree((x<<(ll)1)+1,mid+1,r);
	return;
}
void push_down(ll x)
{
	ll l=segt[x].l,r=segt[x].r;
	segt[x].val+=segt[x].pd*(r-l+1);
	segt[(x<<(ll)1)].pd+=segt[x].pd;
	segt[(x<<(ll)1)+1].pd+=segt[x].pd;
	segt[x].pd=0;
	if(segt[x].sm)
	{
		segt[(x<<(ll)1)].sm=true;
		segt[(x<<(ll)1)+1].sm=true;
		segt[(x<<(ll)1)].col=segt[x].col;
		segt[(x<<(ll)1)+1].col=segt[x].col;
	}
	return;
}
void update(ll x,ll l,ll r,ll v)
{
	ll tl,tr,mid=(l+r)>>1,tv;
	tl=segt[x].l;
	tr=segt[x].r;
	if(tl>tr)
	{
		return;
	}
	push_down(x);
	if(l>tr||r<tl)
	{
		return;
	}
	tv=abs(segt[x].col-v);
	if(l<=tl&&r>=tr)
	{
		segt[x].col=v;
		if(segt[x].sm)
		{
			segt[x].pd+=tv;
			push_down(x);
			return;
		}
		else
		{
			segt[x].sm=true;
		}
	}
	else
	{
		if(segt[x].col!=v)
		{
			segt[x].sm=0;
			segt[x].col=-1;
		}
	}
	update((x<<(ll)1),l,r,v);
	update((x<<(ll)1)+1,l,r,v);
	segt[x].val=segt[(x<<(ll)1)].val+segt[(x<<(ll)1)+1].val;
	return;
}
ll getans(ll x,ll l,ll r)
{
	ll tl,tr,mid=(l+r)>>1;
	tl=segt[x].l;
	tr=segt[x].r;
	if(tl>tr)
	{
		return 0;
	}
	push_down(x);
	if(l>tr||r<tl)
	{
		return 0;
	}
	if(l<=tl&&r>=tr)
	{
		return segt[x].val;
	}
	return getans((x<<(ll)1),l,r)+getans((x<<(ll)1)+1,l,r);
}
int main(){
	ll i,QQ,tp,l,r,x;
	scanf("%I64d%I64d",&n,&QQ);
	build_tree(1,0,n-1);
	while(QQ--)
	{
		scanf("%I64d%I64d%I64d",&tp,&l,&r);
		l--;
		r--;
		if(tp==1)
		{
			scanf("%I64d",&x);
			x--;
			update(1,l,r,x);
		}
		else
		{
			printf("%I64d\n",getans(1,l,r));
		}
	}
	return 0;
}