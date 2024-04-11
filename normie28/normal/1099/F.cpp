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
	ll stim[400001];
	ll scnt[400001];
	ll cnt[400001];
	ll tim[400001];
	void reset(ll l, ll r, ll cur)
	{
		stim[cur]=0;
		scnt[cur]=0;
		tim[cur]=1;
		cnt[cur]=0;
		if (l<r)
		{
			ll mid=(l+r)/2;
			reset(l,mid,(cur<<1));
			reset(mid+1,r,(cur<<1)+1);
		}
	}
	void update(ll l, ll r, ll cur, ll x, ll a, ll b)
	{
	//	cout<<"update "<<l<<' '<<r<<' '<<cur<<' '<<x<<' '<<a<<' '<<b<<endl;
		if ((l<=x)and(x<=r))
		{
			if (l<r)
			{
				ll mid=(l+r)/2;
				update(l,mid,(cur<<1),x,a,b);
				update(mid+1,r,(cur<<1)+1,x,a,b);
				stim[cur]=stim[(cur<<1)]+stim[(cur<<1)+1];
				scnt[cur]=scnt[(cur<<1)]+scnt[(cur<<1)+1];
			}
			else
			{
				cnt[cur]=a;
				tim[cur]=b;
				stim[cur]=a*b;
				scnt[cur]=a;
			}
		}
	}
	ll bs(ll l, ll r, ll cur, ll x)
	{
	//	cout<<"bs "<<l<<' '<<r<<' '<<cur<<' '<<x<<endl;
		if (l==r) return min(cnt[cur],x/tim[cur]);
		else
		{
			ll mid=(l+r)/2;
			if (stim[(cur<<1)]<=x)
			{
				return scnt[(cur<<1)]+bs(mid+1,r,(cur<<1)+1,x-stim[(cur<<1)]);
			}
			else
			{
				return bs(l,mid,(cur<<1),x);
			}
		}
	}
	void debug(ll l, ll r, ll cur)
	{
		cout<<"debug "<<l<<' '<<r<<' '<<cur<<": "<<stim[cur]<<' '<<scnt[cur]<<' '<<tim[cur]<<' '<<cnt[cur]<<endl;
		if (l<r)
		{
			debug(l,(l+r)/2,(cur<<1));
			debug((l+r)/2+1,r,(cur<<1)+1);
		}
	}
};
seg st;
ll coo[100001],tim[100001],val[100001],dp[100001];
ll par[100001],len[100001];
ll pos[100001];
vector<ll> lis;
vector<ll> gt[100001];
ll n,m,i,j,k,t,t1,u,v,a,b;
void dfs(ll x)
{
//	cout<<"dfs "<<x<<endl;
	t-=2*len[x];
	st.update(1,n,1,pos[x],coo[x],tim[x]);
//	st.debug(1,n,1);
	val[x]=st.bs(1,n,1,t);
	for (ll g : gt[x]) dfs(g);
	st.update(1,n,1,pos[x],0,1);
	t+=2*len[x];
//	cout<<"end "<<x<<endl;
}
void calc(ll x)
{
	dp[x]=val[x];
	ll b1=0,b2=0;
	for (int g : gt[x])
	{
		calc(g);
		if (dp[g]>b1)
		{
			b2=b1;
			b1=dp[g];
		}
		else if (dp[g]>b2)
		{
			b2=dp[g];
		}
	}
	if (x>1) dp[x]=max(dp[x],b2);
	else dp[x]=max(dp[x],b1);
}
int main()
{
	fio;
	cin>>n>>t;
	st.reset(1,n,1);
	for (i=1;i<=n;i++)
	{
		cin>>coo[i];
		lis.push_back(i);
	}
	for (i=1;i<=n;i++)
	{
		cin>>tim[i];
	}
	sort(lis.begin(),lis.end(),[](ll a, ll b){
		return (tim[a]<tim[b]);
	});
	for (i=0;i<n;i++) pos[lis[i]]=i+1;
	par[1]=1;
	len[1]=0;
	for (i=2;i<=n;i++)
	{
		cin>>par[i]>>len[i];
		gt[par[i]].push_back(i);
	}
	
	dfs(1);
	
	calc(1);
//	for (i=1;i<=n;i++) cout<<val[i]<<' '; cout<<endl;
//	for (i=1;i<=n;i++) cout<<pos[i]<<' '; cout<<endl;
//	for (i=1;i<=n;i++) cout<<dp[i]<<' '; cout<<endl;
	
	cout<<dp[1];
	
}