#include <stdio.h>
#define N 100001
char B[1<<26],*S=B;
int F(){for(;*S<'-';S++);register int x=*S++-'0';for(;*S>='0';x=(x<<3)+(x<<1)+*S++-'0');return x;}
struct Edge {
	int u, v;
	Edge *next;
} *head[N] = {}, edges[N << 1];
void add(register int x, register int y) {
	static Edge *e = edges;
	e->u = x;
	e->v = y;
	e->next = head[x];
	head[x] = e++;
}
int n, fa[N] = {}, dep[N] = {}, size[N] = {}, heavy[N] = {}, top[N] = {}, vis[N] = {};
long long tosub[N] = {}, toall[N] = {};
void dfs1(register int x) {
	size[x] = 1;
	heavy[x] = -1;
	vis[x] = 1;
	for(register Edge *i = head[x]; i; i = i->next) if(!vis[i->v]) {
		dep[i->v] = dep[x] + 1;
		fa[i->v] = x;
		dfs1(i->v);
		tosub[x] += tosub[i->v] + size[i->v];
		size[x] += size[i->v];
		if(heavy[x] == -1 || size[i->v] > size[heavy[x]]) {
			heavy[x] = i->v;
		}
	}
}
void dfs2(register int x) {
	vis[x] = 0;
	for(register Edge *i = head[x]; i; i = i->next) if(vis[i->v]) {
		top[i->v] = heavy[x] == i->v ? top[x] : i->v;
		toall[i->v] = toall[x] + n - size[i->v] * 2;
		dfs2(i->v);
	}
}
int lca(register int x, register int y) {
	while(top[x] != top[y]) {
		dep[top[x]] < dep[top[y]] ? (y = fa[top[y]]) : (x = fa[top[x]]);
	}
	return dep[x] < dep[y] ? x : y;
}
int son(register int x, register int y) {
	while(fa[top[y]] != x && top[x] != top[y]) {
		y = fa[top[y]];
	}
	return fa[top[y]] == x ? top[y] : heavy[x];
}
int main() {
	register int q, x, y, i, d;
	fread(B,1,1<<26,stdin);
	n = F();
	q = F();
	for(i = 1; i < n; ++i) {
		x = F();
		y = F();
		add(x, y);
		add(y, x);
	}
	top[1] = 1;
	dfs1(1);
	toall[1] = tosub[1];
	dfs2(1);
	typedef double L;
	while(q--) {
		i = lca(x = F(), y = F());
		d = dep[x] + dep[y] - 2 * dep[i];
		if(x == i || y == i) {
			y ^= x ^ i;
			x = i;
			i = son(x, y);
			printf("%.10lf\n",(L)tosub[y]/size[y]+(L)(toall[x]-tosub[i]-size[i])/(n-size[i])+1+d);
		}
		else {
			printf("%.10lf\n", (L)tosub[y] / size[y] + (L)tosub[x] / size[x] + 1 + d);
		}
	}
	return 0;
}