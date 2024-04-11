
// Problem : C. Weak Memory
// Contest : Codeforces - Codeforces Round #119 (Div. 1)
// URL : https://codeforces.com/problemset/problem/187/C
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
const int N = 1e5 + 100;
 
vector<int> adj[N], g[N];
int a[N], d[N], src[N];
queue<int> q;
bool mark[N];
int n, m, k, st, fh;
 
void dfs(int v) {
    mark[v] = true;
    for (auto u : g[v]) {
	if (mark[u])
	    continue;
	dfs(u);
    }
}
 
bool check(int dis) {
    memset(mark, 0, sizeof mark);
    for (int i = 0; i < N; i++)
	g[i].clear();
    while (!q.empty())
	q.pop();
    for (int i = 0; i < k; i++) {
	q.push(a[i]);
	d[a[i]] = 0;
	src[a[i]] = a[i];
	mark[a[i]] = true;
    }
    src[fh] = fh;
    mark[fh] = true;
    d[fh] = 0;
    while (!q.empty()) {
	auto v = q.front();
	q.pop();
	for (auto u : adj[v]) {
	    if (mark[u] && src[u] != src[v] && d[v] + d[u] + 1 <= dis) {
		    g[src[v]].push_back(src[u]);
		    g[src[u]].push_back(src[v]);
	    }
	    else if (!mark[u]) {
		d[u] = d[v] + 1;
		src[u] = src[v];
		q.push(u);
		mark[u] = true;
	    }
	}
    }
    memset(mark, 0, sizeof mark);
    dfs(st);
    return mark[fh];
}
 
int main() {
	fio;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
	cin >> a[i];
	a[i]--;
    }
    for (int i = 0; i < m; i++) {
	int v, u;
	cin >> v >> u;
	adj[--v].push_back(--u);
	adj[u].push_back(v);
    }
    cin >> st >> fh;
    st--; fh--;
    int s = 0, e = n + 1;
    while (e - s > 1) {
	int mid = (s + e) / 2;
	if (check(mid))
	    e = mid;
	else
	    s = mid;
    }
    return cout << (e == n + 1 ? -1 : e), 0;
}