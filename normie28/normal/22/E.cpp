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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "tree.inp"
#define FILE_OUT "tree.out"
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
#define pi 3.1415926535897
typedef long long ll;
//------------xc xch normie tm muoi tm phan tram no----------//
const int maxn = 1e5+10;
int tipo[maxn], chain[maxn], ciclo[maxn];
int in[maxn];
int f[maxn];
int main()
{
	fio;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> f[i], in[f[i]]++;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] != 0) continue;
 
		int x = i;
		tipo[x] = 1;
 
		while (chain[x] == 0)
		{
			chain[x] = i;
			x = f[x];
		}
 
		ciclo[i] = x;
	}
	for (int i = 1; i <= n; i++)
	{
		if (chain[i]) continue;
 
		int x = f[i];
		tipo[i] = 1, chain[x] = chain[i] = i;
 
		while (x != i)
		{
			chain[x] = i;
			x = f[x];
		}
 
		ciclo[i] = i;
	}
	vector<pii> comp;
	for (int i = 1; i <= n; i++)
		if (tipo[i]) comp.push_back({ciclo[i], i});
 
	if (comp.size() == 1 && comp[0].first == comp[0].second)
	{
		cout << "0\n";
		return 0;
	}
 
	cout << comp.size() << "\n";
 
	for (int i = 0; i < comp.size()-1; i++)
		cout << comp[i].first << " " << comp[i+1].second << "\n";
	cout << comp.back().first << " " << comp[0].second << "\n";
}