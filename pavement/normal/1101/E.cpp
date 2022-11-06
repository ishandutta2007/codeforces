#include <bits/stdc++.h>
using namespace std;
#define mt make_tuple
#define int long long

int N, X, Y, H, W;
char C;
tuple<char, int, int> Q[500005];
tuple<int, int, bool> T[2000005];

struct node {
	node *left, *right;
	int S, E, val = 0;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void upd(int p, int v) {
		if (S == E) {
			val = max(val, v);
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = max(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > r || l > E || r < S) return 0;
		if (l <= S && r >= E) return val;
		return max(left->qry(l, r), right->qry(l, r));
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		cin >> C;
		if (C == '+') {
			cin >> X >> Y;
			Q[i] = mt(C, X, Y);
			T[++idx] = mt(X, i, 0);
			T[++idx] = mt(Y, i, 1);
		} else {
			cin >> H >> W;
			Q[i] = mt(C, H, W);
			T[++idx] = mt(H, i, 0);
			T[++idx] = mt(W, i, 1);
		}
	}
	sort(T + 1, T + 1 + idx);
	for (int i = 1, c = 0; i <= idx; i++) {
		if (get<0>(T[i - 1]) != get<0>(T[i])) c++;
		if (!get<2>(T[i])) get<1>(Q[get<1>(T[i])]) = c;
		else get<2>(Q[get<1>(T[i])]) = c;
	}
	root = new node(1, idx);
	for (int i = 1; i <= N; i++) {
		if (get<0>(Q[i]) == '+') tie(C, X, Y) = Q[i];
		else tie(C, H, W) = Q[i];
		if (C == '+') {
			root->upd(X, Y);
		} else {
			if (H > W) swap(H, W);
			if (root->qry(W + 1, idx)) cout << "NO\n";
			else if (root->qry(1, H) > W) cout << "NO\n";
			else if (root->qry(H + 1, W) > H) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}