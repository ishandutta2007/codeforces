
// Problem : E. President and Roads
// Contest : Codeforces - Codeforces Round #Pi (Div. 2)
// URL : https://codeforces.com/problemset/problem/567/E
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
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int k,c[501],pos[100001],t1,i,j;
 
const int maxn = 1e5 + 3;
 
struct edge {
	int u, v, w, id;
	char b;
	edge *n;
} ep[maxn * 2], *el[maxn], *er[maxn];
 
int epl;
void addEdge(int u, int v, int w, int id, edge **p) {
	p[u] = &(ep[epl++] = {u, v, w, id, 0, p[u]});
}
 
void spfa(int s, int t, ll *d, edge **p) {
	static std::deque<int> q;
	static char vis[maxn];
	q.clear();
	memset(vis, 0, sizeof(vis));
	q.push_back(s);
	vis[s] = 1;
	d[s] = 0;
	int u;
	while(!q.empty()) {
		u = q.front(); q.pop_front();
		for(edge *e = p[u]; e; e = e->n)
		if(d[e->v] > d[u] + e->w) {
			d[e->v] = d[u] + e->w;
			if(!vis[e->v]) {
				vis[e->v] = 1;
				if(!q.empty() && d[e->v] < d[q.front()])
					q.push_front(e->v);
				else
					q.push_back(e->v);
			}
		}
		vis[u] = 0;
	}
}
 
int n, m, s, t, la[maxn], lo[maxn];
ll da[maxn], db[maxn], dis;
 
void dfs(int u, int pe) {
	static int dclock = 0;
	lo[u] = la[u] = ++dclock;
	for(edge *e = el[u]; e; e = e->n)
	if(da[u] + e->w + db[e->v] == dis && e->id != pe) {
		if(la[e->v]) {
			lo[u] = std::min(lo[u], la[e->v]);
		} else {
			dfs(e->v, e->id);
			lo[u] = std::min(lo[u], lo[e->v]);
			if(lo[e->v] > la[u]) {
				ep[e->id * 2].b = 1;
			}
		}
	}
	for(edge *e = er[u]; e; e = e->n)
	if(db[u] + e->w + da[e->v] == dis && e->id != pe) {
		if(la[e->v]) {
			lo[u] = std::min(lo[u], la[e->v]);
		} else {
			dfs(e->v, e->id);
			lo[u] = std::min(lo[u], lo[e->v]);
			if(lo[e->v] > la[u]) {
				ep[e->id * 2].b = 1;
			}
		}
	}
}
 
int main() {
	fio;
	cin>>n>>m>>s>>t;
	for(int i = 0, u, v, w; i < m; ++i) {
		cin>>u>>v>>w;
		addEdge(u, v, w, i, el);
		addEdge(v, u, w, i, er);
	}
	memset(da, 0x7f, sizeof(da));
	memset(db, 0x7f, sizeof(db));
	spfa(s, t, da, el);
	spfa(t, s, db, er);
	dis = da[t];
	dfs(s, -1);
	for(int i = 0; i < epl; i += 2) {
		if(ep[i].b) {
			cout<<"YES\n";
		} else if(da[ep[i].u] + db[ep[i].v] + 1 < dis && ep[i].w > 1
				&& ep[i].w - (dis - da[ep[i].u] - db[ep[i].v] - 1) > 0) {
			cout<<"CAN "<< ep[i].w - (dis - da[ep[i].u] - db[ep[i].v] - 1)<<endl;
		} else {
			cout<<"NO\n";
		}
	}
}