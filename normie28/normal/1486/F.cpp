
// Problem : F. Pairs of Paths
// Contest : Codeforces - Codeforces Round #703 (Div. 2)
// URL : https://codeforces.com/contest/1486/problem/F
// Memory Limit : 512 MB
// Time Limit : 6000 ms
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
		return (a.fi<b.fi);
	}
};

vector<int> gt[300001];
int point[300001];
int used[300001];
set<pii(int),cmp> cur[300001];
int n,m,i,j,k,t,t1,u,v,a,b;
ll res;
int dfs(int x)
{
//	cout<<"dfs "<<x<<endl;
	used[x]=1;
	vector<int> cand;
	vector<int> candsz;
	vector<pii(int)> span2;
	cand.push_back(x);
	for (auto g : gt[x]) if (!used[g]) cand.push_back(dfs(g));
	sort(cand.begin(),cand.end(),[](int a, int b){return (cur[a].size()>cur[b].size());});
	for (auto g : cand) candsz.push_back(cur[g].size());
	for (int i=1;i<cand.size();i++)
	{
		for (auto g : cur[cand[i]])
		{
			auto it=cur[cand[0]].lower_bound({g.fi,g.se});
			if ((it!=cur[cand[0]].end())and(it->fi==g.fi))
			{
				candsz[i]--;
				candsz[it->se]--;
				span2.push_back({i,it->se});
				cur[cand[0]].erase(it);
			}
			else cur[cand[0]].insert({g.fi,i});
		}
	}
	for (int i=1;i<cand.size();i++)
	{
		for (auto g : cur[cand[i]])
		{
			auto it=cur[cand[0]].lower_bound({g.fi,g.se});
			if ((it!=cur[cand[0]].end())and(it->fi==g.fi))
			{
				cur[cand[0]].erase(it);
				cur[cand[0]].insert(g);
			}
		}
		cur[cand[i]].clear();
	}
	// COUNTING
	//cout<<"stats for vertex "<<x<<":\n";
	//for (int i=0;i<cand.size();i++) cout<<cand[i]<<' '<<candsz[i]<<endl;
	//for (auto g : span2) cout<<"s "<<g.fi<<' '<<g.se<<endl;
	ll all=0;
	ll root=0;
	for (int i=0;i<cand.size();i++) if (cand[i]==x) root=i;
	for (auto g : candsz) all+=g;
	for (auto g : span2) 
	{
		res+=all;
		if (g.fi!=root) res-=candsz[g.fi];
		if (g.se!=root) res-=candsz[g.se];
	}
	map<int,int> bruh;
	map<ll,int> bruh2;
	all=-1; 
	for (auto g : span2)
	{
		all++;
		res+=all;
		if (g.fi==root)
		{
			res-=bruh[g.se];
		}
		else if (g.se==root)
		{
			res-=bruh[g.fi];
		}
		else 
		{
			res-=bruh[g.fi];
			res-=bruh[g.se];
			res+=bruh2[g.fi*1e9+g.se];
			res+=bruh2[g.se*1e9+g.fi];
		}
		bruh[g.fi]++;
		bruh[g.se]++;
		bruh2[g.fi*1e9+g.se]++;
	}
	all=0;
	for (auto g : candsz) all+=g;
	all+=span2.size();
	res+=all*point[x];
	res+=(ll)point[x]*(point[x]-1)/2;
	//cout<<res<<endl;
	// END COUNTING
	return cand[0];
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
	cin>>m;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v;
		if (u-v)
		{
		cur[u].insert({i,0});
		cur[v].insert({i,0});
		}
		else point[u]++;
	}
	dfs(1);
	cout<<res;
}