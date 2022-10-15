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
//---------END-------//
ll star[1000001];
struct seg
{
	ll val[4000401],lazy[4000401];
	ll n;
	void resetK(ll l, ll r, ll cur)
	{
		if (l==r)
		{
			lazy[cur]=0;
			val[cur]=star[l];
		}
		else
		{
			lazy[cur]=0;
			ll mid=(l+r)/2;
			resetK(l,mid,(cur<<1));
			resetK(mid+1,r,(cur<<1)+1);
			val[cur]=max(val[(cur<<1)],val[(cur<<1)+1]);
		}
	}
	void reset(ll nn)
	{
		n=nn;
		resetK(1,n,1);
	}
	void flusha(ll cur)
	{
	//	cout<<"flusha "<<cur<<endl;
	//	cout<<"before: "<<lazy[(cur<<1)]<<' '<<val[(cur<<1)]<<' '<<lazy[(cur<<1)+1]<<' '<<val[(cur<<1)+1]<<endl;
		lazy[(cur<<1)]+=lazy[cur];
		val[(cur<<1)]+=lazy[cur];
		lazy[(cur<<1)+1]+=lazy[cur];
		val[(cur<<1)+1]+=lazy[cur];
	//	cout<<"after: "<<lazy[(cur<<1)]<<' '<<val[(cur<<1)]<<' '<<lazy[(cur<<1)+1]<<' '<<val[(cur<<1)+1]<<endl;
		lazy[cur]=0;
	}
	void updateK(ll l, ll r, ll cur, ll tl, ll tr, ll d)
	{
		if ((tl>r)or(tr<l)) return;
		if ((tl<=l)and(tr>=r)) 
		{
	//		cout<<"update directly "<<cur<<' '<<d<<endl;
	//		cout<<"before: "<<val[cur]<<' '<<lazy[cur]<<endl;
			val[cur]+=d;
			lazy[cur]+=d;
	//		cout<<"after: "<<val[cur]<<' '<<lazy[cur]<<endl;
		}
		else
		{
			ll mid=(l+r)/2;
			flusha(cur);
			updateK(l,mid,(cur<<1),tl,tr,d);
			updateK(mid+1,r,(cur<<1)+1,tl,tr,d);
			val[cur]=max(val[(cur<<1)],val[(cur<<1)+1]);
		}
	}
	void update(ll l, ll r, ll d)
	{
		if (l>r) return;
		updateK(1,n,1,l,r,d);
	//	debug();
	}
	void debugK(ll l, ll r, ll cur)
	{
		cout<<"---------------------------------\n";
		cout<<"Now crawling node: "<<cur<<endl;
		cout<<"Covering range: ("<<l<<","<<r<<")"<<endl;
		cout<<"It's values: "<<"val = "<<val[cur]<<" lazy = "<<lazy[cur]<<endl;
		cout<<"---------------------------------\n";
		ll mid=(l+r)/2;
		if (l<r)
		{
		debugK(l,mid,(cur<<1));
		debugK(mid+1,r,(cur<<1)+1);
		}
	}
	void debug()
	{
		debugK(1,n,1);
	}
	ll getK(ll l, ll r, ll cur, ll tl, ll tr)
	{
		if ((tl>r)or(tr<l)) return -1e18;
		if ((tl<=l)and(tr>=r)) 
		{
//			cout<<"val gotten: "<<val[cur]<<endl;
			return val[cur];
		}
		else
		{
			ll mid=(l+r)/2;
			flusha(cur);
			ll aa=getK(l,mid,(cur<<1),tl,tr);
			ll bb=getK(mid+1,r,(cur<<1)+1,tl,tr);
			return max(aa,bb);
		}
	}
	ll get(ll l, ll r)
	{
//		cout<<"get "<<l<<' '<<r<<endl;
		if (l>r) return -1e18;
		return getK(1,n,1,l,r);
	}
	ll bsK(ll l, ll r, ll cur, ll x)
	{
		if (l==r)
		{
			if (val[cur]<=x) return l+1;
			else return l;
		}
		else
		{
			ll mid=(l+r)/2;
			flusha(cur);
			if (val[(cur<<1)]>x) return bsK(l,mid,(cur<<1),x);
			else return bsK(mid+1,r,(cur<<1)+1,x);
		}
	}
	ll bs(ll x)
	{
		return bsK(1,n,1,x);
	}
};
seg st;
ll nxtl[400001];
ll nxtr[400001];
ll arr[400001];
ll n,m,i,j,k,t,t1,u,v,a,b,res,pos;
vector<ll> stacc;
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++) cin>>arr[i];
	for (i=n+1;i<2*n;i++) arr[i]=arr[i-n];
	for (i=1;i<2*n;i++)
	{
		nxtl[i]=-1;
		nxtr[i]=-1;
	}
	res=1e18;
	pos=0;
	stacc.clear();
	for (i=1;i<2*n;i++)
	{
		while ((stacc.size())and(arr[stacc[stacc.size()-1]]>=arr[i])) stacc.pop_back();
		if (stacc.size()) nxtl[i]=stacc[stacc.size()-1];
		stacc.push_back(i);
	}
	stacc.clear();
	for (i=2*n-1;i>=1;i--)
	{
		while ((stacc.size())and(arr[stacc[stacc.size()-1]]>=arr[i])) stacc.pop_back();
		if (stacc.size()) nxtr[i]=stacc[stacc.size()-1];
		stacc.push_back(i);
	}
//	for (i=1;i<=2*n-1;i++) cout<<nxtl[i]<<' '; cout<<endl;
//	for (i=1;i<=2*n-1;i++) cout<<nxtr[i]<<' '; cout<<endl;
	st.reset(2*n-1);
	for (i=1;i<=2*n-1;i++)
	{
		if (nxtl[i]!=-1)
		{
			u=st.get(nxtl[i],nxtl[i]);
			st.update(i,i,u+1);
		}
			st.update(nxtl[i]+1,i-1,1);
		if ((i>n)) if (nxtr[i-n]!=-1)
		{
			st.update(i-n+1,nxtr[i-n]-1,-1);
		}
		else
		{
			st.update(i-n+1,i-1,-1);
		}
		if (i>=n)
		{
			u=st.get(i-n+1,i);
			if (u<res)
			{
				res=u;
				pos=i-n;
			}
		}
	//	cout<<"crawling at iteration "<<i<<endl;
	//	for (j=1;j<=2*n-1;j++) cout<<st.get(j,j)<<' ';
	//	cout<<endl;
	}
	cout<<res+1<<' '<<pos<<endl;
}