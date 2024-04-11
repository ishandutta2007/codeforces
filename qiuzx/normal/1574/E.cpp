//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
ll n,m,k,pw2[N],hv_ok=0,hv_bad=0,rw_ok=0,rw_bad=0,col_ok=0,col_bad=0,rw_rt[N],rw_wr[N],col_rt[N],col_wr[N];
map<pair<ll,ll>,ll> mp;
void upd(ll x,ll y,bool tp,ll v)
{
	if(tp)
	{
		hv_ok+=v;
		rw_rt[x]+=v;
		col_rt[y]+=v;
	}
	else
	{
		hv_bad+=v;
		rw_wr[x]+=v;
		col_wr[y]+=v;
	}
	return;
}
void recalc(ll x,ll y,ll v)
{
	if(rw_rt[x]>0&&rw_wr[x]>0)
	{
		rw_bad+=v;
	}
	if(rw_rt[x]==0&&rw_wr[x]==0)
	{
		rw_ok+=v;
	}
	if(col_rt[y]>0&&col_wr[y]>0)
	{
		col_bad+=v;
	}
	if(col_rt[y]==0&&col_wr[y]==0)
	{
		col_ok+=v;
	}
	return;
}
void rem(ll x,ll y,ll c)
{
	ll sld_plc=((x&1)^(y&1));
	recalc(x,y,-1);
	upd(x,y,(sld_plc==c),-1);
	recalc(x,y,1);
	return;
}
void modify(ll x,ll y,ll c)
{
	ll sld_plc=((x&1)^(y&1));
	recalc(x,y,-1);
	upd(x,y,(sld_plc==c),1);
	recalc(x,y,1);
	return;
}
ll calc()
{
	ll ret=0;
	if(rw_bad==0)
	{
		ret=(ret+pw2[rw_ok])%mod;
	}
	if(col_bad==0)
	{
		ret=(ret+pw2[col_ok])%mod;
	}
	if(hv_ok==0&&hv_bad==0)
	{
		ret=(ret+mod-2)%mod;
	}
	else if(hv_ok==0||hv_bad==0)
	{
		ret=(ret+mod-1)%mod;
	}
	return ret;
}
int main(){
	ll i,x,y,tp;
	pw2[0]=1;
	for(i=1;i<N;i++)
	{
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
	scanf("%lld%lld%lld",&n,&m,&k);
	rw_ok=n;
	col_ok=m;
	while(k--)
	{
		scanf("%lld%lld%lld",&x,&y,&tp);
		if(mp.count(make_pair(x,y))&&mp[make_pair(x,y)]!=-1)
		{
			rem(x,y,mp[make_pair(x,y)]);
		}
		if(tp!=-1)
		{
			modify(x,y,tp);
		}
		mp[make_pair(x,y)]=tp;
		printf("%lld\n",calc());
	}
	return 0;
}