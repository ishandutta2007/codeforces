#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
typedef long double ld;

int M, N, L[200005], P[200005];
bool V[200005];

struct node {
	node *left, *right;
	int S, E, val = 0, pv = 0;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void prop() {
		if (S == E || !pv) return;
		left->val = right->val = left->pv = right->pv = pv;
		pv = 0;
	}
	void upd(int l, int r, int v) {
		if (l > E || r < S ) return;
		if (l <= S && r >= E) {
			pv = v;
			val = v;
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
	}
	int qry(int p) {
		if (S == E) return val;
		int M = (S + E) >> 1;
		prop();
		if (p <= M) return left->qry(p);
		else return right->qry(p);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	root = new node(1, N);
	for (int i = 1; i <= M; i++) cin >> L[i];
	for (int i = 1; i <= M; i++) P[i] = i;
	bool c = 0;
	for (int i = M, des = N; i >= 1; i--) {
		if (P[i] + L[i] - 1 < des) {
			P[i] = des - L[i] + 1;
		} else c = 1;
		des = P[i] - 1;
	}
	for (int i = 1; i <= N; i++)
		if (P[i] > N - L[i] + 1) return cout << "-1\n", 0;
	if (!c) return cout << "-1\n", 0;
	for (int i = 1; i <= M; i++) root->upd(P[i], min(N, P[i] + L[i] - 1), i);
	for (int i = 1; i <= N; i++)
		V[root->qry(i)] = 1;
	for (int i = 1; i <= M; i++) if (!V[i]) return cout << "-1\n", 0;
	for (int i = 1; i <= M; i++) cout << P[i] << ' ';
	cout << '\n';
}