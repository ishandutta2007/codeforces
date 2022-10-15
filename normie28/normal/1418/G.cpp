#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll,ll>
#define fi first
#define se second
struct SegTree
{
	ll val[2000001],sto[2000001],cnt[2000001];
	ll n;
	void resetK(ll l, ll r, ll cur)
	{
		sto[cur]=0;
		if (l==r)
		{
			val[cur]=-1;
			cnt[cur]=1;
		}
		else
		{
			ll mid=(l+r)/2;
			resetK(l,mid,cur<<1);
			resetK(mid+1,r,(cur<<1)+1);
			if (val[cur<<1]>val[(cur<<1)+1])
			{
				val[cur]=val[cur<<1];
				cnt[cur]=cnt[cur<<1];
			}
			else
			if (val[cur<<1]<val[(cur<<1)+1])
			{
				val[cur]=val[(cur<<1)+1];
				cnt[cur]=cnt[(cur<<1)+1];
			}
			else
			{
				val[cur]=val[cur<<1];
				cnt[cur]=cnt[cur<<1]+cnt[(cur<<1)+1];
			}
		}
	}
	void reset(ll nn)
	{
		n=nn;
		resetK(0,n,1);
	}
	void flusha(ll cur)
	{
		sto[(cur<<1)]+=sto[cur];
		sto[(cur<<1)+1]+=sto[cur];
		val[(cur<<1)]+=sto[cur];
		val[(cur<<1)+1]+=sto[cur];
		sto[cur]=0;
	}
	void updateK(ll l, ll r, ll tl, ll tr, ll cur, ll diff)
	{
//		cout<<"updateK "<<l<<' '<<r<<' '<<tl<<' '<<tr<<' '<<cur<<' '<<diff<<endl;
		if ((l>tr)or(r<tl)) return;
		if ((l>=tl)and(r<=tr))
		{
			val[cur]+=diff;
			sto[cur]+=diff;
		}
		else
		{
			flusha(cur);
			ll mid=(l+r)/2;
			updateK(l,mid,tl,tr,(cur<<1),diff);
			updateK(mid+1,r,tl,tr,(cur<<1)+1,diff);
			if (val[cur<<1]>val[(cur<<1)+1])
			{
				val[cur]=val[cur<<1];
				cnt[cur]=cnt[cur<<1];
			}
			else
			if (val[cur<<1]<val[(cur<<1)+1])
			{
				val[cur]=val[(cur<<1)+1];
				cnt[cur]=cnt[(cur<<1)+1];
			}
			else
			{
				val[cur]=val[cur<<1];
				cnt[cur]=cnt[cur<<1]+cnt[(cur<<1)+1];
			}
		}
//		cout<<val[cur]<<' '<<sto[cur]<<' '<<cnt[cur]<<endl;
	}
	void update(ll l, ll r, ll diff)
	{
		if (l>r) return;
		updateK(0,n,l,r,1,diff);
	}
	pll getK(ll l, ll r, ll tl, ll tr, ll cur)
	{
//		cout<<"getK "<<l<<' '<<r<<' '<<tl<<' '<<tr<<' '<<cur<<endl;
		if ((l>tr)or(r<tl)) return {-1e18,0};
		if ((l>=tl)and(r<=tr))
		{
			return {val[cur],cnt[cur]};
		}
		else
		{
			flusha(cur);
			ll mid=(l+r)/2;
			pll aa=getK(l,mid,tl,tr,(cur<<1));
			pll bb=getK(mid+1,r,tl,tr,(cur<<1)+1);
			if (aa.fi>bb.fi) return aa;
			else if (aa.fi<bb.fi) return bb;
			else return {aa.fi,aa.se+bb.se};
		}
	}
	pll get(ll l, ll r)
	{
		if (l>r) return {-1e18,0};
		return getK(0,n,l,r,1);
	}
};
SegTree st;
vector<ll> buc[500001];
ll arr[500001];
ll n,m,i,j,k,t,u,v,a,b,res;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	st.reset(n);
	for (i=1;i<=n;i++) buc[i].push_back(0);
	for (i=1;i<=n;i++) 
	{
		cin>>arr[i];
		st.update(i-1,i-1,1);
		st.update(buc[arr[i]][buc[arr[i]].size()-1],i-1,-1);
		if (buc[arr[i]].size()>=3)st.update(buc[arr[i]][buc[arr[i]].size()-3],buc[arr[i]][buc[arr[i]].size()-2]-1,1);
		if (buc[arr[i]].size()>=4)st.update(buc[arr[i]][buc[arr[i]].size()-4],buc[arr[i]][buc[arr[i]].size()-3]-1,-1);
		pll pp=st.get(0,i-1);
		buc[arr[i]].push_back(i);
		if (pp.fi==0) res+=pp.se;
	}
	cout<<res;
}