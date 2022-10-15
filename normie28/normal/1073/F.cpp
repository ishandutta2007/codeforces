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
ll n,m,i,j,k,t,t1,u,v,a,b,res1,res2;
ll ch1,ch2;
vector<ll> gt[200001],down[200001];
ll spl[200001],cnt[200001];
vector<ll> mk[200001];
ll maxx[200001];
ll dep[200001];
void dfs(ll x, ll d)
{
	dep[x]=d;
	cnt[x]=spl[x];
	maxx[x]=x;
	for (auto g : gt[x]) if (dep[g]==-1)
	{
		down[x].push_back(g);
		dfs(g,d+1);
		cnt[x]+=cnt[g];
		if (dep[maxx[g]]>dep[maxx[x]]) maxx[x]=maxx[g];
	}
}
ll calc(ll x)
{
	vector<ll> v;
	ll c1,c2;
	for (auto g : down[x])
	{
		ll u=calc(g);
		if (u>=0) v.push_back(u);
	}
	sort(v.begin(),v.end(),[](ll a, ll b){
		if (dep[a]-dep[b]) return (dep[a]>dep[b]);
		return (mk[a][0]>mk[b][0]);
	});
  
	if (v.size()>=2)
	{
		c1=dep[v[0]]+dep[v[1]]-2*dep[x];
		c2=mk[v[0]][0]+mk[v[1]][0];
		if ((res1<c1)or((res1==c1)and(res2<c2)))
		{
			res1=c1;
			res2=c2;
			ch1=v[0];
			ch2=v[1];
		}
	}
	if ((v.size()>=1)and(mk[x].size()))
	{
		c1=dep[v[0]]-dep[x];
		c2=mk[v[0]][0]+mk[x][0];
		if ((res1<c1)or((res1==c1)and(res2<c2)))
		{
			res1=c1;
			res2=c2;
			ch1=x;
			ch2=v[0];
		}
	}
  /*
  */
	if (v.size()) return v[0];
	else if (mk[x].size()) return x;
	else return -1;
}
int main()
{
	fio;
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	for (i=1;i<=n;i++) {dep[i]=-1; down[i].clear();}
	for (i=1;i<=n;i++) if (gt[i].size()>=3) spl[i]=1;
  	dfs(1,0);
	for (i=1;i<=n;i++)
	{
		u=0;
		for (ll g : down[i]) if (cnt[g]) u++;
		if (cnt[i]<cnt[1]) u++;
  //    cout<<i<<' '<<u<<endl;
		if ((u==1)and(spl[i])) {mk[i]={1}; v=i;}
	}
  
	for (i=1;i<=n;i++) {dep[i]=-1; down[i].clear();};
	dfs(v,0);
  
	for (i=1;i<=n;i++) if (mk[i].size())
	{
		vector<ll> v;
		for (ll g : down[i]) if (!cnt[g]) v.push_back(maxx[g]);
		sort(v.begin(),v.end(),[](ll a, ll b){return (dep[a]>dep[b]);});
		mk[i]={dep[v[0]]+dep[v[1]]-2*dep[i],v[0],v[1]};
	}
//  for (i=1;i<=n;i++) cout<<spl[i]<<' '<<mk[i].size()<<endl;
	calc(v);
 //   cout<<endl;
  //cout<<ch1<<' '<<ch2<<endl;
	cout<<mk[ch1][1]<<' '<<mk[ch2][2]<<' '<<mk[ch1][2]<<' '<<mk[ch2][1];
  
}