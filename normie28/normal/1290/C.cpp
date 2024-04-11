
// Problem : C. Prefix Enlightenment
// Contest : Codeforces - Codeforces Round #616 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1290/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
int par[300001];
int col[300001];
int forced[300001];
int minn[300001];
vector<int> buc[300001][2];
vector<int> insett[300001];
vector<int> sett[300001];
int val[300001];
int n,m,i,j,k,t,t1,u,v,pu,pv,a,b,cur=0;
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		val[i]=c-48;
	}
	for (i=1;i<=m;i++)
	{
		cin>>u;
		for (j=0;j<u;j++)
		{
			cin>>v;
			insett[v].push_back(i);
		}
		forced[i]=-1;
		minn[i]=0;
		buc[i][0]={i};
		par[i]=i;
		col[i]=0;
	}
	for (i=1;i<=n;i++)
	{
		if (insett[i].size()==1)
		{
			u=insett[i][0];
			pu=par[u];
			cur-=minn[pu];
			if (val[i]==0)
			{
				forced[pu]=col[u];
			}
			else 
			{
				forced[pu]=1-col[u];
			}
			minn[pu]=buc[pu][forced[pu]].size();
			cur+=minn[pu];
		}
		else
		if (insett[i].size()==2)
		{
			
			u=insett[i][0];
			v=insett[i][1];
			pu=par[u];
			pv=par[v];
			if (pu!=pv)
			{ 
			int sw=(1^val[i])^col[u]^col[v];
			if (forced[pu]>=0)
			{
				cur-=minn[pv];
				forced[pv]=forced[pu]^sw;
				minn[pv]=buc[pv][forced[pv]].size();
				cur+=minn[pv];
			}
			else if (forced[pv]>=0)
			{
				cur-=minn[pu];
				forced[pu]=forced[pv]^sw;
				minn[pu]=buc[pu][forced[pu]].size();
				cur+=minn[pu];
			}
			
			cur-=minn[pu];
			cur-=minn[pv];
			
			if (buc[pv][0].size()+buc[pv][1].size()<buc[pu][0].size()+buc[pu][1].size())
			{
				for (j=0;j<2;j++) for (int g : buc[pv][j])
				{
					par[g]=pu;
					col[g]=col[g]^sw;
					buc[pu][col[g]].push_back(g);
				}
				buc[pv][0].clear();
				buc[pv][1].clear();
				if (forced[pu]>=0) minn[pu]=buc[pu][forced[pu]].size();
				else minn[pu]=min(buc[pu][0].size(),buc[pu][1].size());
				cur+=minn[pu];
			}
			else
			{
				for (j=0;j<2;j++) for (int g : buc[pu][j])
				{
					par[g]=pv;
					col[g]=col[g]^sw;
					buc[pv][col[g]].push_back(g);
				}
				buc[pu][0].clear();
				buc[pu][1].clear();
				if (forced[pv]>=0) minn[pv]=buc[pv][forced[pv]].size();
				else minn[pv]=min(buc[pv][0].size(),buc[pv][1].size());
				cur+=minn[pv];
			}
			}
		}
		cout<<cur<<endl;
	}
}