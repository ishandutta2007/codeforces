#include <bits/stdc++.h>
using namespace std;

int TC, N, Q, A[200005], B[200005];
char S[200005], T[200005];

struct node {
	int s, e, m;
	int lazy, sum;
	node *l, *r;
	node(int _s, int _e) {
		s = _s;
		e = _e;
		m = (s + e) / 2;
		lazy = -1;
		sum = 0;
		if (s == e) return;
		l = new node(s, m);
		r = new node(m+1, e);
	}
	void propagate() {
		if (lazy == -1) return;
		if (s == e) return;
		l->lazy = lazy;
		r->lazy = lazy;
		l->sum = (l->e - l->s + 1) * lazy;
		r->sum = (r->e - r->s + 1) * lazy;
		lazy = -1;
	}
	void update(int qs, int qe, int v) {
		propagate();
		if (qs <= s && e <= qe) {
			sum = (e - s + 1) * v;
			lazy = v;
			return;
		} else if (qs > e || s > qe) return;
		else {
			l->update(qs, qe, v);
			r->update(qs, qe, v);
			sum = l->sum + r->sum;
		}
	}
	int query(int qs, int qe) {
		propagate();
		if (qs <= s && e <= qe) return sum;
		else if (s > qe || qs > e) return 0;
		else return l->query(qs, qe) + r->query(qs, qe);
	}
} *root;

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d%d", &N, &Q);
		scanf(" %s", S);
		scanf(" %s", T);
		for (int i = 0; i < Q; i++) scanf("%d%d", &A[i], &B[i]);
		for (int i = 0; i < Q; i++) {
			A[i]--;
			B[i]--;
		}
		
		root = new node(0, N-1);
		for (int i = 0; i < N; i++) {
			root->update(i, i, T[i] == '1');
		}
		bool fail = 0;
		for (int i = Q - 1; i >= 0; i--) {
			int cnt = root->query(A[i], B[i]);
			if (cnt * 2 == B[i] - A[i] + 1) {
				fail = 1;
				break;
			}
			if (cnt * 2 < B[i] - A[i] + 1) {
				root->update(A[i], B[i], 0);
			} else root->update(A[i], B[i], 1);
		}
		for (int i = 0; i < N; i++) {
			if (S[i] - '0' != root->query(i, i)) {
				fail = 1;
				break;
			}
		}
		if (fail) printf("NO\n");
		else printf("YES\n");
	}
}