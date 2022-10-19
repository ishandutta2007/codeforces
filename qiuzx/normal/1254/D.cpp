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
#define N 150010
using namespace std;
ll n,q,din[N],dout[N],dv,vv[N],sonsz[N],par[N],bit1[N],bit2[N],hea[N],tp[N],cnt=0,sum=0;
vector<ll> vt[N],bg;
ll ksm(ll x,ll y)
{
	if(y==0)
	{
		return 1;
	}
	ll ret=ksm(x,y>>1);
	ret=(ret*ret)%mod;
	if(y%2==1)
	{
		return (ret*x)%mod;
	}
	return ret;
}
ll dfs(ll x,ll lst)
{
	ll i,mx=0,j=-1,sz=1,st;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			st=dfs(vt[x][i],x);
			sz+=st;
			if(mx<st)
			{
				mx=st;
				j=vt[x][i];
			}
		}
	}
	hea[x]=j;
	return sz;
}
void dfs2(ll x,ll lst)
{
	din[x]=++cnt;
	par[x]=lst;
	if(tp[x]==-1)
	{
		tp[x]=x;
	}
	ll i;
	if(hea[x]!=-1)
	{
		tp[hea[x]]=tp[x];
		dfs2(hea[x],x);
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst&&vt[x][i]!=hea[x])
		{
			dfs2(vt[x][i],x);
		}
	}
	dout[x]=cnt;
	sonsz[x]=dout[x]-din[x]+1;
	return;
}
void cge(ll x,ll val)
{
	while(x<N)
	{
		bit1[x]=(bit1[x]+val)%mod;
		x+=(x&(-x));
	}
	return;
}
void update(ll l,ll r,ll val)
{
	cge(l,val);
	cge(r+1,mod-val);
	return;
}
void upd2(ll x,ll val)
{
	while(x<N)
	{
		bit2[x]=(bit2[x]+val)%mod;
		x+=(x&(-x));
	}
	return;
}
void upd(ll x,ll val)
{
	update(1,din[x]-1,(((val*dv)%mod)*(n-sonsz[x]))%mod);
	update(dout[x]+1,cnt,(((val*dv)%mod)*(n-sonsz[x]))%mod);
	if(hea[x]!=-1)
	{
		vv[x]=(vv[x]+val)%mod;
		upd2(din[x]+1,sonsz[hea[x]]*((dv*val)%mod)%mod);
	}
	return;
}
ll getans(ll x)
{
	ll ret=0;
	while(x>0)
	{
		ret=(ret+bit1[x])%mod;
		x-=(x&(-x));
	}
	return ret;
}
ll g2(ll x)
{
	ll ret=0;
	while(x>0)
	{
		ret=(ret+bit2[x])%mod;
		x-=(x&(-x));
	}
	return ret;
}
ll ga2(ll l,ll r)
{
	ll a=g2(l-1),b=g2(r);
	return b-a;
}
ll ga(ll x)
{
	ll ret=sum;
	ret-=getans(din[x]);
	while(tp[x]!=0)
	{
		ret=(ret+mod-ga2(din[tp[x]],din[x]))%mod;
		x=tp[x];
		ret=(ret+mod-(vv[par[x]]*((sonsz[x]*dv)%mod))%mod)%mod;
		x=par[x];
	}
	ret=(ret+mod-ga2(din[tp[x]],din[x]))%mod;
	while(ret<0)
	{
		ret+=mod;
	}
	return ret;
}
int main(){
	ll i,x,y,ty;
	memset(tp,-1,sizeof(tp));
	memset(hea,-1,sizeof(hea));
	scanf("%lld%lld",&n,&q);
	dv=ksm(n,mod-2);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,-1);
	dfs2(0,-1);
	while(q--)
	{
		scanf("%lld%lld",&ty,&x);
		x--;
		if(ty==1)
		{
			scanf("%lld",&y);
			sum+=y;
			upd(x,y);
		}
		else
		{
			printf("%lld\n",ga(x));
		}
	}
	return 0;
}