#include <bits/stdc++.h>
using namespace std;

int N, score[300005], nodes[300005], par[300005], depth[300005];
vector< pair<char, int> > v[300005], v1[300005];

void dfs(int x, int p, int d) {
	nodes[d]++;
	par[x] = p;
	depth[x] = d;
	score[d] += v[x].size() - 1;
	for (int i = 0; i < v[x].size(); i++) dfs(v[x][i].second, x, d + 1);
}

void dfs2(vector<int> x, int credit) {
	score[credit] += x.size() - 1;
	//printf("%d: + %d\n", credit, x.size() - 1);
	vector<int> store[26];
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < v[x[i]].size(); j++) {
			store[v[x[i]][j].first - 'a'].push_back(v[x[i]][j].second);
		}
	}
	for (int i = 0; i < 26; i++) if (store[i].size() > 1) dfs2(store[i], credit);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int a, b;
		char c;
		scanf("%d%d %c", &a, &b, &c);
		a--;
		b--;
		v[a].push_back(make_pair(c, b));
	}
	dfs(0, -1, 0);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < v[i].size(); j++) v1[par[i]].push_back(v[i][j]);
	}
	for (int i = 0; i < N; i++) {
		vector<int> store[26];
		for (int j = 0; j < v1[i].size(); j++) {
			store[v1[i][j].first - 'a'].push_back(v1[i][j].second);
		}
		for (int j = 0; j < 26; j++) if (store[j].size() > 1) dfs2(store[j], depth[i]);
	}
	int best = 1000000000, val = 0;
	for (int i = 0; i < N; i++) {
		int n = N - nodes[i] - score[i];
		if (n < best) {
			best = n;
			val = i + 1;
		}
	}
	printf("%d\n%d\n", best,val);
}