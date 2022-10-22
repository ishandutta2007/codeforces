#include <bits/stdc++.h>
using namespace std;

int N, A[200005], renum[200005], cur, end1[200005], unnum[200005];
long long dis[200005], newd[200005];
vector< pair<int, int> > V[200005];

struct node {
	vector<long long> v;
	int s, e;
	node *l, *r;
	node(int _s, int _e) {
		s = _s;
		e = _e;
		for (int i = s; i <= e; i++) v.push_back(newd[i] - A[unnum[i]]);
		sort(v.begin(), v.end());
		if (s == e) return;
		int m = (s + e) / 2;
		l = new node(s, m);
		r = new node(m+1, e);
	}
	int query(int qs, int qe, long long mx) {
		if (qs > qe) return 0;
		if (qs <= s && e <= qe) return upper_bound(v.begin(), v.end(), mx) - v.begin();
		else if (qs > e || s > qe) return 0;
		else return l->query(qs, qe, mx) + r->query(qs, qe, mx);
	}
} *root;

void dfs(int node, long long d) {
	dis[node] = d;
	renum[node] = cur;
	unnum[cur] = node;
	cur++;
	for (int i = 0; i < V[node].size(); i++) dfs(V[node][i].first, d + V[node][i].second);
	end1[node] = cur;
	//printf("node %d = (%d, %d)\n", node, renum[node], end[node]);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 1; i < N; i++) {
		int p, w;
		scanf("%d%d", &p, &w);
		V[p - 1].push_back(make_pair(i, w));
	}
	dfs(0, 0);
	for (int i = 0; i < N; i++) newd[renum[i]] = dis[i];
	root = new node(0, N - 1);
	for (int i = 0; i < N; i++) {
		if (i) printf(" ");
		printf("%d", root->query(renum[i] + 1, end1[i] - 1, dis[i]));
	}
	printf("\n");
}