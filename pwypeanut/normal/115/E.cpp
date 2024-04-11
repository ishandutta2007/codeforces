#include <bits/stdc++.h>
using namespace std;

int N, M;
long long H[300005];

struct node {
	int s, e, m;
	long long val, lazy;
	node *l, *r;
	node(int _s, int _e) {
		s = _s;
		e = _e;
		m = (s+e)/2;
		val = 0;
		lazy = 0;
		if (s == e) return;
		l = new node(s, m);
		r = new node(m+1, e);
	}
	void propagate() {
		if (lazy == 0) return;
		if (s != e) {
			l->lazy += lazy;
			r->lazy += lazy;
			l->val += lazy;
			r->val += lazy;
		}
		lazy = 0;
	}
	long long query_max(int qs, int qe) {
		propagate();
		if (qs <= s && e <= qe) return val;
		else if (qs > e || s > qe) return -1000000000000000000ll;
		else return max(l->query_max(qs, qe), r->query_max(qs, qe));
	}
	void range_update(int qs, int qe, long long delta) {
		propagate();
		if (qs <= s && e <= qe) {
			val += delta;
			lazy += delta;
		} else if (qs > e || s > qe) return;
		else {
			l->range_update(qs, qe, delta);
			r->range_update(qs, qe, delta);
			val = max(l->val, r->val);
		} 
	}
} *root;

vector< pair<int, int> > V[300005];
long long dp[300005];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%lld", &H[i]);
	for (int i = 1; i < N; i++) H[i] += H[i-1];
	root = new node(0, N);
	for (int i = 0; i < M; i++) {
		int s, e, v;
		scanf("%d%d%d", &s, &e, &v);
		s--;
		e--;
		V[e].push_back(make_pair(s, v));
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < V[i-1].size(); j++) {
			root->range_update(0, V[i-1][j].first, V[i-1][j].second);
			//printf("range update %d %d %d\n", 0, V[i-1][j].first, V[i-1][j].second);
		}
		dp[i] = max(dp[i-1], root->query_max(0, i-1) - H[i-1]);
		//printf("dp[%d] = %lld\n", i, dp[i]);
		root->range_update(i, i, dp[i] + H[i-1]);
		//printf("range update %d %d %lld\n", i, i, dp[i] + H[i-1]);
	}
	printf("%lld\n", dp[N]);
}