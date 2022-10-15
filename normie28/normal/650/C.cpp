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
#define N 1000000
 
 
int n, m, c, p, v[N + 9], f[N + 9], o[N + 9];
list<pair<int, int>> s[N + 9];
int ax[N + 9], ay[N + 9];
map<int, int> g;
 
inline
int idx(const int &a, const int &b) {
	return a * m + b;
}
 
int find(int e) {
	return f[e] == e? f[e] : f[e] = find(f[e]);
}
 
void join(int a, int b) {
	int x = find(a), y = find(b);
	if (x == y) return;
	f[y] = x;
	s[x].splice(s[x].end(), s[y]);
}
 
#define X first
#define Y second
 
int main() {
    nfio;
	int a;
	cin>>n>>m;
	c = n * m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
		    cin>>a;
			int id = idx(i, j);
			v[id] = a;
			f[id] = id;
			s[id].push_back(make_pair(i, j));
		}
	for (int i = 0; i < n; ++i) {
		g.clear();
		for (int j = 0; j < m; ++j) {
			int id = idx(i, j);
			if (g.count(v[id])) join(g[v[id]], id);
			else g[v[id]] = id;
		}
	}
	for (int j = 0; j < m; ++j) {
		g.clear();
		for (int i = 0; i < n; ++i) {
			int id = idx(i, j);
			if (g.count(v[id])) join(g[v[id]], id);
			else g[v[id]] = id;
		}
	}
	for (int i = 0; i < c; ++i)
		if (f[i] == i) o[p++] = i;
	sort(o, o + p, [](int a, int b){return v[a] < v[b];});
	for (int i = 0; i < p; ++i) {
		a = 0;
		for (const auto &pos: s[o[i]]) {
			if (a < ax[pos.X]) a = ax[pos.X];
			if (a < ay[pos.Y]) a = ay[pos.Y];
		}
		++a;
		for (const auto &pos: s[o[i]]) {
			int id = idx(pos.X, pos.Y);
			v[id] = a;
			ax[pos.X] = a;
			ay[pos.Y] = a;
		}
	}
	for (int i = 0; i < c; ++i)
		printf("%d%c", v[i], " \n"[(i + 1) % m == 0]);
}