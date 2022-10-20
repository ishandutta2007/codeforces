#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 1600010
using namespace std;
ll n,m,c[N],inum[N],onum[N],dn[N],num=-1;
vector<ll> vt[N];
struct segt{
	ll l,r,val,lz;
}st[N];
void dfs(ll x,ll lst)
{
	inum[x]=++num;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x);
		}
	}
	onum[x]=num;
	return;
}
void build_tree(ll x,ll y,ll nd)
{
	st[nd].l=x;
	st[nd].r=y;
	st[nd].lz=0;
	if(x==y)
	{
		st[nd].val=((ll)1<<(dn[x]-1));
		return;
	}
	build_tree(x,((y+x)>>1),(nd<<1));
	build_tree(((y+x)>>1)+1,y,(nd<<1)+1);
	st[nd].val=st[(nd<<1)].val|st[(nd<<1)+1].val;
	return;
}
void push_down(ll x)
{
	st[(x<<1)].val=st[x].lz;
	st[(x<<1)+1].val=st[x].lz;
	st[(x<<1)].lz=st[x].lz;
	st[(x<<1)+1].lz=st[x].lz;
	st[x].lz=0;
	return;
}
void update(ll x,ll a,ll b,ll v)
{
	if(st[x].l>=a&&st[x].r<=b)
	{
		st[x].val=v;
		st[x].lz=v;
		return;
	}
	if(st[x].lz!=0)
	{
		push_down(x);
	}
	ll mid=((st[x].l+st[x].r)>>1);
	st[x].val=0;
	if(a<=mid)
	{
		update((x<<1),a,b,v);
	}
	if(b>mid)
	{
		update((x<<1)+1,a,b,v);
	}
	st[x].val|=st[(x<<1)].val;
	st[x].val|=st[(x<<1)+1].val;
}
ll calc(ll x,ll a,ll b)
{
	if(st[x].l>=a&&st[x].r<=b)
	{
		return st[x].val;
	}
	if(st[x].lz!=0)
	{
		push_down(x);
	}
	ll mid=((st[x].l+st[x].r)>>1),ret=0;
	if(a<=mid)
	{
		ret|=calc((x<<1),a,b);
	}
	if(b>mid)
	{
		ret|=calc((x<<1)+1,a,b);
	}
	return ret;
}
int main(){
	ll i,x,y;
	scanf("%I64d%I64d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&c[i]);
	}
	for(i=0;i+1<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,-1);
	for(i=0;i<n;i++)
	{
		dn[inum[i]]=c[i];
	}
	build_tree(0,n-1,1);
	while(m--)
	{
		scanf("%I64d",&i);
		if(i==1)
		{
			scanf("%I64d%I64d",&x,&y);
			x--;
			update(1,inum[x],onum[x],((ll)1<<(y-1)));
		}
		else
		{
			scanf("%I64d",&x);
			x--;
			printf("%d\n",__builtin_popcountll(calc(1,inum[x],onum[x])));
		}
	}
	return 0;
}