#include <stdio.h>
#include <stdlib.h>
#define N 100001
#define M 300000
int n, to[M], next[M], prev[M], c[N], cdown[N], cup[N];
int color(int x, int y) {return x && y ? x != y ? -1 : x : x + y;}
void dfs(int x, int f) {
	cdown[x] = c[x];
	for(int i = next[x]; i != x; i = next[i]) if(to[i] != f) {
		dfs(to[i], x);
		cup[to[i]] = cdown[x];
		cdown[x] = color(cdown[x], cdown[to[i]]);
	}
	cdown[x] = c[x];
	for(int i = prev[x]; i != x; i = prev[i]) if(to[i] != f) {
		cup[to[i]] = color(cup[to[i]], cdown[x]);
		cdown[x] = color(cdown[x], cdown[to[i]]);
	}
}
void solve(int x, int f, int col) {
	if(col == -1) return;
	int flag = 1;
	for(int i = next[x]; i != x && flag; i = next[i]) if(to[i] != f && cdown[to[i]] == -1) flag = 0;
	if(flag) exit(!printf("YES\n%d", x));
	for(int i = next[x]; i != x; i = next[i]) if(to[i] != f) solve(to[i], x, color(col, cup[to[i]]));
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) next[i] = prev[i] = i;
	for(int i = 1, j = N + 1; i < n; ++i) {
		scanf("%d%d", &to[j], &to[j^1]);
		next[j] = to[j^1], prev[j] = prev[to[j^1]], next[prev[to[j^1]]] = j, prev[to[j^1]] = j, ++j;
		next[j] = to[j^1], prev[j] = prev[to[j^1]], next[prev[to[j^1]]] = j, prev[to[j^1]] = j, ++j;
	}
	for(int i = 1; i <= n; ++i) scanf("%d", &c[i]);
	dfs(1, -1);
	solve(1, -1, 0);
	puts("NO");
	return 0;
}