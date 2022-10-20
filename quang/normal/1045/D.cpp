#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
double p[N];
vector<int> adj[N];
int par[N];
double sum[N];

void dfs(int u, int pa) {
	par[u] = pa;
	for (int v : adj[u]) {
		if (v == pa) {
			continue;
		}
		dfs(v, u);
		sum[u] += (1. - p[v]);
	}
}

double preCalc() {
	double res = 1. - p[0];
	for (int i = 1; i < n; i++) {
		res += p[par[i]] * (1. - p[i]);
	}
	return res;
}

double getVal(int u) {
	double res = u ? p[par[u]] * (1. - p[u]) : (1. - p[u]);
	res += p[u] * sum[u];
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", p + i);
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, -1);
	double res = preCalc();
	int q;
	scanf("%d", &q);
	while (q--) {
		int u;
		double x;
		scanf("%d %lf", &u, &x);
		res -= getVal(u);
		if (u) sum[par[u]] -= (1. - p[u]);
		p[u] = x;
		if (u) sum[par[u]] += (1. - p[u]);
		res += getVal(u);
		printf("%0.14f\n", res);
	}
	return 0;
}