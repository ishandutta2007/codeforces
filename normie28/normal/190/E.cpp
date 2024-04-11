
// Problem : E. Counter Attack
// Contest : Codeforces - Codeforces Round #120 (Div. 2)
// URL : https://codeforces.com/problemset/problem/190/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
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
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
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
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int n;
vector<vector<int> > g;
set<int> st;
vector<vector<int> > res;
vector<int> cur;
 
bool yes(int v, int u)
{
	if(g[v].size() == 0)
	{
		return false;
	}
	int l = 0,
		r = int(g[v].size()) - 1;
	while(l != r)
	{
		int mid = (l + r) / 2;
		if(g[v][mid] >= u)
		{
			r = mid;
		} else
		{
			l = mid + 1;
		}
	}
	return g[v][l] == u;
}
 
void dfs(int v)
{
	st.erase(st.find(v));
	cur.push_back(v);
	int u = 1;
	while(st.upper_bound(u) != st.end())
	{
		int to = *st.upper_bound(u);
		if(!yes(v, to))
		{
			dfs(to);
		}
		u = to;
	}
}
 
int main ()
{
	fio;
	int m;
	cin>>n>>m;
	g.resize(n + 1);
	while(m--)
	{	
		int from, to;
		cin>>from>>to;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	for(int i = 1; i <= n; ++i)
	{
		sort(g[i].begin(), g[i].end());
		st.insert(i);
	}
	for(int i = 1; i <= n; ++i)
	{
		if(st.find(i) != st.end())
		{
			cur.clear();
			dfs(i);
			res.push_back(cur);
		}
	}
	cout<<res.size()<<endl;
	for(int i = 0; i < res.size(); ++i)
	{
		cout<<res[i].size()<<' ';
		for(int j = 0; j < res[i].size(); ++j)
		{
			cout<<res[i][j]<<' ';
		}
		cout<<endl;
	}
}