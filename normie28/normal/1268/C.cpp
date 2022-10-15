/*
        Normie's Template v2.0
*/

// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;

// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)

//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"

//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))

//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320

//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>

//Quick power of 2.
#define pow2(x) (ll(1)<<x)

//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)

//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//#define DEBUG
//---------END-------//
ll star[200001];
struct seg
{
	ll cnt[800001],val[800001],lazy[800001];
	ll n;
	void resetK(ll l, ll r, ll cur)
	{
		#ifdef DEBUG
		cout<<"reset: "<<l<<' '<<r<<' '<<cur<<endl;
		#endif
		cnt[cur]=0;
		val[cur]=0;
		lazy[cur]=0;
		if (l<r)
		{
			ll mid=(l+r)/2;
			resetK(l,mid,(cur<<1));
			resetK(mid+1,r,(cur<<1)+1);
		}
	}
	void reset(ll nn)
	{
		n=nn;
		resetK(1,n,1);
	}
	void flusha(ll cur)
	{
		#ifdef DEBUG
		cout<<"flusha: "<<cur<<endl;
		#endif
		val[(cur<<1)]+=lazy[cur]*cnt[(cur<<1)];
		val[(cur<<1)+1]+=lazy[cur]*cnt[(cur<<1)+1];
		lazy[(cur<<1)]+=lazy[cur];
		lazy[(cur<<1)+1]+=lazy[cur];
		lazy[cur]=0;
	}
	void addK(ll l, ll r, ll cur, ll t, ll x)
	{
		#ifdef DEBUG
		cout<<"add: "<<l<<' '<<r<<' '<<cur<<' '<<t<<' '<<x<<endl;
		#endif
		if ((l<=t)and(t<=r))
		{
			cnt[cur]++;
			val[cur]+=x;
			if (l<r)
			{
				flusha(cur);
			ll mid=(l+r)/2;
			addK(l,mid,(cur<<1),t,x);
			addK(mid+1,r,(cur<<1)+1,t,x);
			}
		}
	}
	void add(ll t, ll x)
	{
		addK(1,n,1,t,x);
	}
	void updateK(ll l, ll r, ll cur, ll tl, ll tr, ll d)
	{
		#ifdef DEBUG
		cout<<"update: "<<l<<' '<<r<<' '<<cur<<' '<<tl<<' '<<tr<<' '<<d<<endl;
		#endif
		if ((tl>r)or(tr<l)) return;
		if ((tl<=l)and(tr>=r))
		{
			lazy[cur]+=d;
			val[cur]+=d*cnt[cur];
		}
		else
		{
			flusha(cur);
			ll mid=(l+r)/2;
			updateK(l,mid,(cur<<1),tl,tr,d);
			updateK(mid+1,r,(cur<<1)+1,tl,tr,d);
			val[cur]=val[(cur<<1)]+val[(cur<<1)+1];
		}
	}
	void update(ll l, ll r, ll d)
	{
		if (l>r) return;
		updateK(1,n,1,l,r,d);
	}
	pii(ll) getK(ll l, ll r, ll cur, ll tl, ll tr)
	{
		#ifdef DEBUG
		cout<<"reset: "<<l<<' '<<r<<' '<<cur<<' '<<tl<<' '<<tr<<endl;
		#endif
		if ((tl>r)or(tr<l)) return {0,0};
		if ((tl<=l)and(tr>=r))
		{
			return pii(ll)({cnt[cur],val[cur]});
		}
		else
		{
				flusha(cur);
			ll mid=(l+r)/2;
			pii(ll) aa=getK(l,mid,(cur<<1),tl,tr);
			pii(ll) bb=getK(mid+1,r,(cur<<1)+1,tl,tr);
			return pii(ll)({aa.fi+bb.fi,aa.se+bb.se});
		}
	}
	pii(ll) get(ll l, ll r)
	{
		if (l>r) return pii(ll)({0,0});
		return getK(1,n,1,l,r);
	}
	ll order_of_key_K(ll l, ll r, ll cur, ll x)
	{
		#ifdef DEBUG
		cout<<"ook: "<<l<<' '<<r<<' '<<cur<<' '<<x<<endl;
		#endif
		if (l==r)
		{
			if (l<x) return cnt[cur];
			else return 0;
		}
		else
		{
			flusha(cur);
			ll mid=(l+r)/2;
			if (mid<x) return cnt[(cur<<1)]+order_of_key_K(mid+1,r,(cur<<1)+1,x);
			else return order_of_key_K(l,mid,(cur<<1),x);
		}
	}
	ll order_of_key(ll x)
	{
		return order_of_key_K(1,n,1,x);
	}
	ll find_by_order_K(ll l, ll r, ll cur, ll x)
	{
		#ifdef DEBUG
		cout<<"fbo: "<<l<<' '<<r<<' '<<cur<<' '<<x<<endl;
		#endif
		if (l==r) return l;
		else
		{
			flusha(cur);
			ll mid=(l+r)/2;
			if (cnt[(cur<<1)]-1>=x) return find_by_order_K(l,mid,(cur<<1),x);
			else return find_by_order_K(mid+1,r,(cur<<1)+1,x-cnt[cur<<1]);
		}
	}
	ll find_by_order(ll x)
	{
		return find_by_order_K(1,n,1,x);
	}
	
};
seg st;
ll n,m,i,j,k,t,t1,u,v,a,b,inv;
ll arr[200001],pos[200001];
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
		pos[arr[i]]=i;
	}
	st.reset(n);
	for (i=1;i<=n;i++)
	{
		u=st.order_of_key(pos[i]);
		inv+=st.cnt[1]-u;
		st.add(pos[i],pos[i]-u);
		st.update(pos[i]+1,n,-1);
		v=st.cnt[1];
		a=st.find_by_order(v/2);
	//	cout<<a<<' ';
		pii(ll) aa=st.get(1,a-1);
		pii(ll) bb=st.get(a+1,n);
		b=st.get(a,a).se;
	//	cout<<b<<' ';
	//	cout<<endl;
	//	cout<<inv<<' ';
	//	cout<<aa.fi<<' '<<aa.se<<' '<<bb.fi<<' '<<bb.se<<endl;
		cout<<inv+(aa.fi)*b-(aa.se)+(bb.se)-(bb.fi)*b<<' ';
	}
}