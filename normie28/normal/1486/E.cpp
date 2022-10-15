
// Problem : E. Paired Payment
// Contest : Codeforces - Codeforces Round #703 (Div. 2)
// URL : https://codeforces.com/contest/1486/problem/E
// Memory Limit : 512 MB
// Time Limit : 4000 ms
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
struct cmp
{
	int operator()(pii(int) a, pii(int) b) const
	{
		return (a.se>b.se);
	}
};
priority_queue<pii(int),vector<pii(int)>,cmp> pq;
int dis[5100000];
vector<pii(int)> gt[100001];
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	cin>>n>>m;
	for (i=0;i<m;i++)
	{
		cin>>u>>v>>a;
		u--;
		v--;
		gt[u].push_back({v,a});
		gt[v].push_back({u,a});
	}
	for (i=0;i<51*n;i++) dis[i]=2e9;
	dis[0]=0;
	pq.push({0,0});
	while(pq.size())
	{
		auto pp=pq.top(); pq.pop();
	//	cout<<pp.fi/51<<' '<<pp.fi%51<<' '<<pp.se<<endl;
		if (dis[pp.fi]-pp.se) continue;
		u=pp.fi/51;
		v=pp.fi%51;
		if (v==0)
		{
			for (auto g : gt[u])
			{
				if (dis[g.fi*51+g.se]>dis[pp.fi]+g.se*g.se)
				{
					dis[g.fi*51+g.se]=dis[pp.fi]+g.se*g.se;
	//				cout<<"relax "<<g.fi<<' '<<g.se<<' '<<dis[pp.fi]+g.se*g.se;
					pq.push({g.fi*51+g.se,dis[pp.fi]+g.se*g.se});
				}
			}
		}
		else
		{
			for (auto g : gt[u])
			{
				if (dis[g.fi*51]>dis[pp.fi]+g.se*g.se+2*g.se*v)
				{
					dis[g.fi*51]=dis[pp.fi]+g.se*g.se+2*g.se*v;
			//		cout<<"relax "<<g.fi<<' '<<0<<' '<<dis[pp.fi]+g.se*g.se+2*g.se*v;
					pq.push({g.fi*51,dis[pp.fi]+g.se*g.se+2*g.se*v});
				}
			}
		}
	}
	for (i=0;i<n;i++) if (dis[i*51]==2e9) cout<<-1<<' '; else cout<<dis[i*51]<<' ';
}