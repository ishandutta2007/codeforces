
// Problem : E. Bear and Forgotten Tree 2
// Contest : Codeforces - IndiaHacks 2016 - Online Edition (Div. 1 + Div. 2)
// URL : https://codeforces.com/problemset/problem/653/E
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
set<int> bruh;
vector<int> buc[300001],gt[300001],cur;
int par[300001],cnt[300001];
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	cin>>n>>m>>k;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v;
		if (u>v) swap(u,v);
		gt[u].push_back(v);
	}
	bruh.insert(n);
	buc[n]={n};
	par[n]=n;
	for (i=n-1;i>=1;i--)
	{
		if ((bruh.size()>k)and(i==1)) return cout<<"impossible",0;
		cur.clear();
		for (int g : gt[i]) cnt[par[g]]++;
		for (int g : bruh) if (cnt[g]<buc[g].size()) cur.push_back(g);
		for (int g : gt[i]) cnt[par[g]]--;
		if (cur.size()==0)
		{
			par[i]=i;
			buc[i]={i};
			bruh.insert(i);
		}
		else
		{
			for (j=1;j<cur.size();j++)
			{
				u=par[cur[j-1]],v=par[cur[j]];
				if (u!=v)
				{
					if (buc[u].size()<buc[v].size())
					{
						for (int g : buc[u])
						{
							par[g]=v;
							buc[v].push_back(g);
						}
						buc[u].clear();
						bruh.erase(u);
					}
					else
					{
						for (int g : buc[v])
						{
							par[g]=u;
							buc[u].push_back(g);
						}
						buc[v].clear();
						bruh.erase(v);
					}
				}
			}
			u=par[cur[0]];
			par[i]=u;
			buc[u].push_back(i);
		}
		
		if ((bruh.size()>1)and(i==1)) return cout<<"impossible",0;
		if ((n-1-gt[i].size()<k)and(i==1)) return cout<<"impossible",0;
	}
	cout<<"possible";
}