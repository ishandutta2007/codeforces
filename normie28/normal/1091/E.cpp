
// Problem : E. New Year and the Acquaintance Estimation
// Contest : Codeforces - Good Bye 2018
// URL : https://codeforces.com/problemset/problem/1091/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
struct seg
{
	ll val[2000011],cnt[2000011];
	ll n;
	void update(ll l, ll r, ll cur, ll t)
	{
		if ((l<=t)and(t<=r))
		{
			val[cur]+=t;
			cnt[cur]++;
			if (l<r)
			{
				ll mid=(l+r)/2;
				update(l,mid,(cur<<1),t);
				update(mid+1,r,(cur<<1)+1,t);
			}
		}
	}
	pii(ll) get(ll l, ll r, ll cur, ll tl, ll tr)
	{
		if ((tl>r)or(tr<l)) return {0,0};
		if ((tl<=l)and(tr>=r)) return {val[cur],cnt[cur]};
		else
		{
				ll mid=(l+r)/2;
			pii(ll) aa=get(l,mid,(cur<<1),tl,tr);
			pii(ll) bb=get(mid+1,r,(cur<<1)+1,tl,tr);
			return {(aa.fi+bb.fi),(aa.se+bb.se)};
		}
	}
};
seg st;
ll arr[500011];
ll pre[500011];
ll thl[500011],thr[500011];
ll n,m,i,j,k,t,t1,u,v,a,b,par;
set<ll> setle,setge;
vector<ll> res;
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+n+1,[](ll a, ll b) {
		return (a>b);
	});
	for (i=1;i<=n+1;i++)
	{
		thl[i]=n;
		thr[i]=0;
		pre[i]=pre[i-1]+arr[i];
	}
	for (i=n+1;i>=1;i--)
	{
		if (i==n+1)
		{
			u=pre[i-1];
			thl[i]=min(thl[i],i*(i-1)-u);
		}
		else 
		{
			u=pre[i];
			v=st.get(0,n,1,0,i-1).fi+st.get(0,n,1,i,n).se*i;
			thr[i]=max(thr[i],-i*(i-1)+u-v);
			st.update(0,n,1,arr[i]);
			u=pre[i-1];
			v=st.get(0,n,1,0,i-1).fi+st.get(0,n,1,i,n).se*i;
			thl[i]=min(thl[i],i*(i-1)-u+v);
			par+=arr[i];
			par%=2;
		}
	}
	for (i=1;i<=n+1;i++)
	{
	//	cout<<i<<": "<<thl[i]<<' '<<thr[i]<<endl;
	}
	setge.insert(-1e18);
	setle.insert(1e18);
	for (i=1;i<=n+1;i++) setle.insert(thl[i]*1e9+i);
	j=1;
	for (i=n;i>=0;i--)
	{
		while ((j<=n)and(i<arr[j]))
		{
			setle.erase(thl[j]*1e9+j);
			setge.insert(thr[j]*1e9+j);
			j++;
		}
		u=(*(setle.begin()))/1e9;
		v=(*(--setge.end()))/1e9;
		if ((i<=u)and(i>=v)and(i%2==par)) 
		{
			res.push_back(i);
			a++;
		}
	}
	if (!a) cout<<-1;
	else
	{
		sort(res.begin(),res.end());
		for (ll g : res) cout<<g<<' ';
	}
}