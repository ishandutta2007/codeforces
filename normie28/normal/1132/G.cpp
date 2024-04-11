/*
khoi orz, go check out his algo
-normie-
Tested with library-checker.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "birds.inp"
#define FILE_OUT "birds.out"
#define prev prv
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
#define pi 3.1415926535897
//------START-----------//
struct seg
{
	int val[4000401],lazy[4000401];
	ll n;
	void resetK(ll l, ll r, ll cur)
	{
		if (l==r)
		{
			lazy[cur]=0;
			val[cur]=0;
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
	//	cout<<"get "<<l<<' '<<r<<' '<<cur<<' '<<tl<<' '<<tr<<endl;
		if ((tl>r)or(tr<l)) return -1;
		if ((tl<=l)and(tr>=r)) 
		{
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
		if (l>r) return -1;
		return getK(1,n,1,l,r);
	}
};
seg st;
int n,m,i,j,k,t,t1,u,v,a,b,res=0;
vector<int> gt[1000001];
int arr[1000001];
int tl[1000001];
int mk[1000001];
int tr[1000001];
int dep[1000001];
int cur[1000001];
int par[1000001][20];
struct cmp
{
	int operator()(int a, int b) const
	{
		if (cur[a]-cur[b]) return (cur[a]>cur[b]);
		 return (a<b);
	}
};
set<int,cmp> roots;
vector<int> stacc;
void dfs(int x, int p)
{
//	cout<<"dfs "<<x<<' '<<p<<endl;
	t++;
	dep[x]=dep[p]+1;
	tl[x]=t;
	par[x][0]=p;
	for (int i=1;i<20;i++) par[x][i]=par[par[x][i-1]][i-1];
	for (int g : gt[x]) dfs(g,x);
	tr[x]=t;
}
void add_node(int x)
{
	mk[x]=1;
	st.update(tl[x],tl[x],dep[x]);
	cur[x]=st.get(tl[x],tr[x])-dep[x];
	for (int g : gt[x]) roots.erase(g);
//	cout<<x<<endl;
	roots.insert(x);
}
void del_node(int x)
{
	int p=x;
	for (int i=19;i>=0;i--) if (mk[par[p][i]]) p=par[p][i];
	st.update(tl[x],tl[x],-dep[x]);
	roots.erase(p);
	cur[p]=st.get(tl[p],tr[p])-dep[p];
	if (cur[p]>=0) roots.insert(p);
	mk[x]=0;
}
//------END-----------//
int main()
{
//    ofile;
    fio;
    cin>>n>>m;
    st.reset(n);
    for (i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for (i=n;i>=1;i--)
    {
    	while((stacc.size())and(arr[stacc[stacc.size()-1]]<=arr[i])) stacc.pop_back();
		if (stacc.size())
		{
//			cout<<i<<"'s parent is "<<stacc[stacc.size()-1]<<endl;
			gt[stacc[stacc.size()-1]].push_back(i);
		}
		stacc.push_back(i);    	
	}
	for (i=n;i>=1;i--) if (!tl[i]) dfs(i,i);
//		for (j=1;j<=n;j++) cout<<dep[j]<<' '; cout<<endl;
	for (i=1;i<=n;i++)
	{
		add_node(i);
//		for (j=1;j<=n;j++) cout<<cur[j]<<' '; cout<<endl;
		if (i>m) 
		{
		
		del_node(i-m);
	//	for (j=1;j<=n;j++) cout<<cur[j]<<' '; cout<<endl;
		}
	//	cout<<"roots:\n";
	//	for (int g : roots) cout<<g<<' ';
	//	cout<<endl;
		if (i>=m) {
		cout<<cur[(*(roots.begin()))]+1<<' '; }
	}
}