#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll star[400001];
map<ll,ll> mp[200001];
set<ll> pos;
ll n,m,i,j,k,t,t1,u,v,a,b,x,y;
struct seg
{
	ll val[1600001],lazy[1600001];
	ll n;
	void resetK(ll l, ll r, ll cur)
	{
		lazy[cur]=0;
		if (l==r)
		{
			val[cur]=star[l];
		}
		else
		{
			ll mid=(l+r)/2;
			resetK(l,mid,(cur<<1));
			resetK(mid+1,r,(cur<<1)+1);
			val[cur]=min(val[(cur<<1)],val[(cur<<1)+1]);
			
		}
	}
	void reset(ll nn)
	{
		n=nn;
		resetK(1,n,1);
	}
	void flusha(ll cur)
	{
		lazy[(cur<<1)]+=lazy[cur];
		lazy[(cur<<1)+1]+=lazy[cur];
		val[(cur<<1)]+=lazy[cur];
		val[(cur<<1)+1]+=lazy[cur];
		lazy[cur]=0;
	}
	void updateK(ll l, ll r, ll cur, ll tl, ll tr, ll diff)
	{
		if ((tl>r)or(tr<l)) return;
		if ((tl<=l)and(tr>=r)) 
		{
			val[cur]+=diff;
			lazy[cur]+=diff;
		}
		else
		{
			flusha(cur);
			ll mid=(l+r)/2;
			updateK(l,mid,(cur<<1),tl,tr,diff);
			updateK(mid+1,r,(cur<<1)+1,tl,tr,diff);
			val[cur]=min(val[(cur<<1)],val[(cur<<1)+1]);
		}
	//		cout<<"after update: "<<l<<' '<<r<<' '<<val[cur]<<endl;
	}
	void update(ll l, ll r, ll diff)
	{
		if (l>r) return;
		updateK(1,n,1,l,r,diff);
	}
	ll getK(ll l, ll r, ll cur, ll tl, ll tr)
	{
		if ((tl>r)or(tr<l)) return 1e18;
		if ((tl<=l)and(tr>=r)) 
		{
			return val[cur];
		}
		else
		{
			flusha(cur);
			ll mid=(l+r)/2;
			ll aa=getK(l,mid,(cur<<1),tl,tr);
			ll bb=getK(mid+1,r,(cur<<1)+1,tl,tr);
			return min(aa,bb);
		}
	}
	ll get(ll l, ll r)
	{
		if (l>r) return 1e18;
		return getK(1,n,1,l,r);
	}
};
seg st;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k>>m;
	for (i=1;i<=2*n;i++)
	{
		star[i]=2*n+1-i;
	}
	st.reset(2*n);
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		if (mp[x][y])
		{
			st.update(1,y+ll(abs(x-k)),1);
//			cout<<"del "<<y+ll(abs(x-k))<<endl;
			pos.erase((y+ll(abs(x-k)))*1e9+mp[x][y]);
			mp[x][y]=0;
		}
		else
		{
			mp[x][y]=i;
//			cout<<"add "<<y+ll(abs(x-k))<<endl;
			st.update(1,y+ll(abs(x-k)),-1);
			pos.insert((y+ll(abs(x-k)))*1e9+mp[x][y]);
		}
		if (pos.size()==0) cout<<0<<endl;
		else
		{
			auto it=(pos.end());
			it--;
			u=(*it)/1e9;
	//		cout<<u<<endl;
			v=st.get(1,u);
			a=2*n-v;
//			cout<<v<<endl;
			cout<<max(ll(0),a-n)<<endl;
		}
	}
}