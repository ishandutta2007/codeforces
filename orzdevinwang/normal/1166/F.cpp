#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 2e5 + 7;
map<int, int> mp[N];
set<int> e[N];
int n, m, c, q, to[N], f[N], siz[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	if(e[x].size() < e[y].size()) swap(x, y);
	for(int i : e[y]) e[x].insert(i); 
	f[y] = x;
}
void add_edge(int u, int v, int col) {
	e[find(u)].insert(v);
	if(mp[u][col]) merge(mp[u][col], v);
	else mp[u][col] = v;
}
void add(int x, int y, int col) {
	add_edge(x, y, col), add_edge(y, x, col);
}
int main() {
	scanf("%d%d%d%d", &n, &m, &c, &q);
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++) {
		int u, v, col;
		scanf("%d%d%d", &u, &v, &col);
		add(u, v, col);
	}
	while(q--) {
		char s[9];
		int u, v, col;
		scanf("%s%d%d", s, &u, &v);
		if(s[0] == '?') printf("%s\n", find(u) == find(v) ? "Yes" : (*e[find(u)].lower_bound(v) == v ? "Yes" : "No")); 
		else scanf("%d", &col), add(u, v, col);
	} 
	return 0;
}