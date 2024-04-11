
// Problem : E. Wrong Floyd
// Contest : Codeforces - Codeforces Round #203 (Div. 2)
// URL : https://codeforces.com/problemset/problem/350/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
/*
The whole thing literally dented the LCL's reputation, like seriously why the fuck were they 
allowed to compete in the first place, they were literally a bunch of diamonds, i remember when this roster was first announced, 
some people already predicted that its gonna flop, yet you had some morons arguing that people are being sexist lol
*/
int n,m,k,c[501],pos[100001],t,t1,i,j;
vector<int> mk,unmk;
vector<pii> res;
int main()
{
	fio;
	cin>>n>>m>>k;
	if (k==n)
	{ 
	cout<<-1;
	return 0;
	}
	for (i=0;i<k;i++)
	{
		cin>>j;
		c[j]=1;
	}
	for (i=1;i<=n;i++)
	{
		if (c[i]) mk.push_back(i);
		else unmk.push_back(i);
	}
	for (i=1;i<=n;i++)
	{
		if (res.size()==m) break;
		if (i==unmk[unmk.size()-1]) continue;
		res.push_back({unmk[unmk.size()-1],i});
	}
	for (i=1;i<=n;i++)
	{
		for (j=i+1;j<=n;j++)
		{
			if (res.size()==m) break;
			if (((i==mk[0])or(j==mk[1]))or(((i==mk[1])or(j==mk[0])))or(i==unmk[unmk.size()-1])or(j==unmk[unmk.size()-1])) continue;
			res.push_back({i,j});
		}
	}
	
	unmk.pop_back();
	for (i=0;i<2;i++) for (j=0;j<unmk.size();j++)
	{
		if (res.size()==m) break;
		res.push_back({mk[i],unmk[j]});
	}
	
	for (i=0;i<1;i++) for (j=2;j<mk.size();j++)
	{
		if (res.size()==m) break;
		res.push_back({mk[i],mk[j]});
	}
	if (res.size()<m)
	{
		cout<<-1;
	}
	else for (auto g: res) cout<<g.fi<<' '<<g.se<<endl;
}