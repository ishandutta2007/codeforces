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
#define MOD (ll(1000000007))
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
struct node
{
	vector<ll> dests;
	node* nxt[10]={0,0,0,0,0,0,0,0,0,0};
};
node start;
vector<pii(ll)> gt[100001],gtt[100001];
ll dis[100001];
ll done[100001];
ll res[100001];
vector<ll> events[600001];
ll n,m,i,j,k,t,t1,u,v,a,b;
ll eu[100001],ev[100001];
void dfs(node* cur, ll val)
{
//	cout<<"dfs "<<val<<endl;
	for (ll g : cur->dests) if (!done[g])
	{
//		cout<<"trans "<<g<<endl;
		res[g]=val;
		done[g]=1;
		for (pii(ll) gg : gtt[g])
		{
	//		cout<<"to: "<<gg.fi<<' '<<gg.se<<endl;
			node* po=cur;
			string s=to_string(gg.se);
			for (int i=0;i<s.size();i++)
			{
				if (!po->nxt[int(s[i]-48)]) po->nxt[int(s[i]-48)]=new(node);
				po=po->nxt[int(s[i]-48)];
			}
			po->dests.push_back(gg.fi);
		}
	}
	for (int i=0;i<10;i++) if (cur->nxt[i]) dfs(cur->nxt[i],(val*10+i)%MOD);
}
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>eu[i]>>ev[i];
		gt[eu[i]].push_back({ev[i],i});
		gt[ev[i]].push_back({eu[i],i});
	}
	for (i=1;i<=n;i++)
	{
		dis[i]=1e9;
	}
	dis[1]=0;
	events[0].push_back(1);
	for (t=0;t<=6*n;t++)
	{
		for (ll g : events[t]) if (!done[g])
		{
			for (pii(ll) gg : gt[g]) if (dis[g]+(ll)floor(log10(gg.se))+1<dis[gg.fi])
			{
				dis[gg.fi]=dis[g]+(ll)floor(log10(gg.se))+1;
				events[dis[gg.fi]].push_back(gg.fi);
			}
			done[g]=1;
		}
	}
	for (i=1;i<=n;i++) done[i]=0;
	for (i=1;i<=m;i++)
	{
		if (dis[eu[i]]+(ll)floor(log10(i))+1==dis[ev[i]]) gtt[eu[i]].push_back({ev[i],i});
		if (dis[ev[i]]+(ll)floor(log10(i))+1==dis[eu[i]]) gtt[ev[i]].push_back({eu[i],i});
	}
	start.dests.push_back(1);
	dfs(&start,0);
	for (i=2;i<=n;i++) cout<<res[i]<<endl;
}