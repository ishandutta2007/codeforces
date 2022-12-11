//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB emplace_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e6;
bool mark[maxn];
int A[maxn],
	comp[maxn],
	indeg[maxn],
	h[maxn];
int n, m, compocnt, nn;
vector<int> adj1[maxn],
	cadj[maxn];
vector<int> adj2[maxn],
	stc;
set<pii> rset[maxn],
	cset[maxn];

int &a(int i, int j){
	return A[i * m + j];
}

void add_edge1(int v, int u){
	adj1[v].PB(u);
	cadj[u].PB(v);
}

void add_edge2(int v, int u){
	add_edge1(v, u);
	add_edge1(u, v);
}

void dfs1(int v){
	mark[v] = true;
	for(auto u : adj1[v])
		if(!mark[u])
			dfs1(u);
	stc.PB(v);
}

void dfs2(int v){
	mark[v] = true;
	comp[v] = compocnt;
	for(auto u : cadj[v])
		if(!mark[u])
			dfs2(u);
}

void scc(void){
	stc.reserve(1 << 20);
	for(int i = 0; i < n * m; i++)
		if(!mark[i])
			dfs1(i);
	memset(mark, false, sizeof mark);
	while(sz(stc)){
		int v = stc.back();
		stc.pop_back();
		if(mark[v])
			continue;
		dfs2(v);
		compocnt++;
	}
	for(int v = 0; v < n * m; v++){
		for(auto u : adj1[v])
			if(comp[u] != comp[v]){
				adj2[comp[v]].PB(comp[u]);
				indeg[comp[u]]++;
			}
		adj1[v].clear();
	}
	nn = compocnt;
	return;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			int x;
			scanf("%d", &x);
			a(i, j) = x;
			rset[i].insert({a(i, j), i * m + j});
			cset[j].insert({a(i, j), i * m + j});
		}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int val = a(i, j);
			auto it = rset[i].lower_bound(MP(val, -1));
			add_edge2(it->R, i * m + j);
			it = rset[i].lower_bound(MP(val + 1, -1));
			if(it != rset[i].end()) add_edge1(i * m + j, it->R);

			it = cset[j].lower_bound(MP(val, -1));
			add_edge2(it->R, i * m + j);
			it = cset[j].lower_bound(MP(val + 1, -1));
			if(it != cset[j].end()) add_edge1(i * m + j, it->R);
		}
	}
	for(int i = 0; i < maxn; i++)
		rset[i].clear(), cset[i].clear();
	scc();
	queue<int> q;
	for(int i = 0; i < nn; i++)
		if(indeg[i] == 0)
			q.push(i);
	while(sz(q)){
		int v = q.front();
		q.pop();
		for(auto u : adj2[v]){
			indeg[u]--;
			if(!indeg[u]){
				q.push(u);
				h[u] = h[v] + 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			printf("%d ", h[comp[i * m + j]] + 1);
		printf("\n");
	}
	return 0;
}