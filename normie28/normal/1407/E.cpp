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
int n,m,i,j,k,t,t1,u,v,a,b;
int dis[500001],db[500001],dw[500001],col[500001];
vector<pii(int)> gt[500001];
deque<int> dq;
int main()
{
    fio;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v>>a;
		gt[v].emplace_back(u,a);
	}
	for (i=1;i<=n;i++)
	{
		dis[i]=1e9;
		db[i]=1e9;
		dw[i]=1e9;
		col[i]=0;
	}
	i--;
	dis[i]=0;
	db[i]=0;
	dw[i]=0;
	dq.push_back(i);
	while(dq.size())
	{
		u=dq.front();
		for (pii(int) g : gt[u])
		{
			if (g.se==0) db[g.fi]=min(db[g.fi],dis[u]+1);
			if (g.se==1) dw[g.fi]=min(dw[g.fi],dis[u]+1);
			v=dis[g.fi];
			dis[g.fi]=max(db[g.fi],dw[g.fi]);
			if (dis[g.fi]==db[g.fi]) col[g.fi]=0;
			else col[g.fi]=1;
			if (dis[g.fi]<v) dq.push_back(g.fi);
		}
		dq.pop_front();
	}
	if (dis[1]==1e9) cout<<-1; else cout<<dis[1];
	cout<<endl;
	for (i=1;i<=n;i++) cout<<col[i];
}