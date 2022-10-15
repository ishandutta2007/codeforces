
// Problem : C. World Eater Brothers
// Contest : Codeforces - Codeforces Round #148 (Div. 1)
// URL : https://codeforces.com/problemset/problem/238/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
const int MAXN = 3e3 + 10;
 
int n, dp[MAXN], go[MAXN];
vector<pair<int, int>> adj[MAXN];
 
void dfs(int v, int par = 0, int val = 0) {
	dp[v] = dp[par];
	if (par && val)
		dp[v]--;
	else if (par)
		dp[v]++;
	go[v] = val;
	int happy = dp[v];
	for (auto i : adj[v])
		if (i.first != par) {
			dfs(i.first, v, i.second);
			go[v] += go[i.first];
			happy = min(happy, dp[i.first]);
		}
	dp[v] = happy;
	if (par == 0) {
		vector<int> vec;
		for (auto i : adj[v])
			vec.push_back(dp[i.first]);
		vec.push_back(0);
		swap(*min_element(vec.begin(), vec.end()), *vec.begin());
		swap(*min_element(vec.begin() + 1, vec.end()), *(vec.begin() + 1));
		dp[1] = vec[0]; dp[2] = vec[1];
	}
	return;
}
 
int main() {
	fio;
	cin >> n;
	if (n == 1)
		return cout << 0 << endl, 0;
	for (int i = 1; i < n; i++) {
		int v, u; cin >> v >> u;
		adj[v].push_back({ u, 0 });
		adj[u].push_back({ v , 1 });
	}
	int res = n;
	for (int i = 1; i <= n; i++) {
		dfs(i);
		res = min(res, go[i] + dp[1] + dp[2]);
	}
	cout << res << endl;
}