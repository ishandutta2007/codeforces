
 
// Problem : E. Santa Claus and Tangerines
// Contest : Codeforces - Technocup 2017 - Elimination Round 3
// URL : https://codeforces.com/problemset/problem/748/E
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
#define pll pair<ll,ll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define MAX_N 200005
typedef long long ll;
//-------END-------//
 
queue<int> que;
int n;
vector<int> G[MAX_N];
int d[MAX_N];
int a[MAX_N];
bool vis[MAX_N];
set<int> se[MAX_N];
 
int bfs() {
	while (que.size()) {
		int u = que.front();
		que.pop();
		vis[u] = 1;
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			if (vis[v]) continue;
			se[v].insert((*se[u].begin()) + 1);
			d[v]--;
			if (d[v] == 1 && se[v].size() == 1) que.push(v);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (se[i].size() > 2) return -1;
		if (se[i].size() == 2 && res != 0) return -1;
		if (se[i].size() == 2) for (auto h : se[i]) res += h;
	}
	if (res == 0) {
		for (int i = 1; i <= n; i++)
			res = std::max(res, *se[i].begin());
		res = res * 2;
	}
	while (res % 2 == 0 && res > 0) res >>= 1;
	return res;
}
 
int main() {
    fio;
    cin>>n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		d[i] = G[i].size();
		if (d[i] == 1) {
			que.push(i);
			se[i].insert(0);
		}
	}
	cout<<bfs()<<endl;
}