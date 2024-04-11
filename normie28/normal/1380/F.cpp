#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll,ll>
#define fi first
#define se second
#define MOD (ll(998244353))
#define _lr 0
#define _l 1
#define _r 2
#define _n 3
ll star[500001];
struct SegTree
{
	vector<ll> val[2000001];
	ll n;
	void qmod(ll cur)
	{
//		cout<<"qmod "<<cur<<endl;
		val[cur][_n]%=MOD;
		val[cur][_l]%=MOD;
		val[cur][_r]%=MOD;
		val[cur][_lr]%=MOD;
	}
	void merg (ll cur, ll l, ll r)
	{
//		cout<<"merg "<<l<<' '<<r<<' '<<' '<<cur<<endl;
		ll mult;
		if ((star[l]*10+star[r]<=18)and(star[l]*10+star[r]>=10))
		mult=19-(star[l]*10+star[r]);
		else mult=0;
		val[cur]={0,0,0,0};
		val[cur][_n]=(val[(cur<<1)][_r]*val[(cur<<1)+1][_l])%MOD+(val[(cur<<1)][_n]*val[(cur<<1)+1][_n])%MOD*mult;
		val[cur][_l]=(val[(cur<<1)][_lr]*val[(cur<<1)+1][_l])%MOD+(val[(cur<<1)][_l]*val[(cur<<1)+1][_n])%MOD*mult;
		val[cur][_r]=(val[(cur<<1)][_r]*val[(cur<<1)+1][_lr])%MOD+(val[(cur<<1)][_n]*val[(cur<<1)+1][_r])%MOD*mult;
		val[cur][_lr]=(val[(cur<<1)][_lr]*val[(cur<<1)+1][_lr])%MOD+(val[(cur<<1)][_l]*val[(cur<<1)+1][_r])%MOD*mult;
		qmod(cur);
		
	}
	void resetK(ll l, ll r, ll cur)
	{
//		cout<<"reset "<<l<<' '<<r<<' '<<' '<<cur<<endl;
		if (l==r)
		{
			val[cur]={star[l]+1,1,1,0};
		}
		else if (r-l==1)
		{
			val[cur]={0,star[l]+1,star[r]+1,1};
			val[cur][_lr]=val[cur][_l]*val[cur][_r];
			if ((star[l]*10+star[r]<=18)and(star[l]*10+star[r]>=10))
			val[cur][_lr]+=19-(star[l]*10+star[r]);
			qmod(cur);
			resetK(l,l,cur<<1);
			resetK(r,r,(cur<<1)+1);
		}
		else
		{
			ll mid=(l+r)/2;
			resetK(l,mid,cur<<1);
			resetK(mid+1,r,(cur<<1)+1);
			merg(cur,mid,mid+1);
		}
	}
	void reset(ll nn)
	{
		n=nn;
		resetK(1,n,1);
	}
	void updateK(ll l, ll r, ll x, ll cur)
	{
//		cout<<"update "<<l<<' '<<r<<' '<<x<<' '<<cur<<endl;
		if ((l>x)or(r<x)) return;
		if (l==r)
		{
			val[cur]={star[l]+1,1,1,0};
		}
		else if (r-l==1)
		{
			val[cur]={0,star[l]+1,star[r]+1,1};
			val[cur][_lr]=val[cur][_l]*val[cur][_r];
			if ((star[l]*10+star[r]<=18)and(star[l]*10+star[r]>=10))
			val[cur][_lr]+=19-(star[l]*10+star[r]);
			qmod(cur);
			updateK(l,l,x,cur<<1);
			updateK(r,r,x,(cur<<1)+1);
		}
		else
		{
			ll mid=(l+r)/2;
			updateK(l,mid,x,cur<<1);
			updateK(mid+1,r,x,(cur<<1)+1);
			merg(cur,mid,mid+1);
		}
	}
	void update(ll x)
	{
		updateK(1,n,x,1);
	}
};
SegTree st;
vector<ll> buc[500001];
ll arr[500001],presum[500001];
ll n,m,i,j,k,t,u,v,a,b,res;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	
	for (i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		star[i]=c-48;
	}
	st.reset(n);
	for (i=1;i<=m;i++)
	{
		cin>>a>>b;
		star[a]=b;
		st.update(a);
		cout<<st.val[1][_lr]<<endl;
	}
}