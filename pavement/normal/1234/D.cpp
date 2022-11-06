#include <bits/stdc++.h>
using namespace std;

string s;

int numUnique(string ss) {
	bool isThere[26] = {};
	for (char c : ss) {
		isThere[c - 'a'] = true;
	}
	int r = 0;
	for (bool i : isThere) r += i;
	return r;
}

struct node {
	node *left, *right;
	int S, E, bm = 0;
	
	node(int _s, int _e) {
		S = _s;
		E = _e;
		if (S == E) {
			bm |= (1<<(s[S] - 'a'));
			return;
		}
		int M = (S + E) / 2;
		left = new node(S, M);
		right = new node(M + 1, E);
		bm = left->bm | right->bm;
	}
	
	void update(int pos, string v) {
		if (S == E) {
			bm = 0;
			bm |= (1<<(v[0] - 'a'));
			return;
		}
		int M = (S + E) / 2;
		if (pos <= M) left->update(pos, v);
		else right->update(pos, v);
		bm = left->bm | right->bm;
	}
	
	int query(int l, int r) {
		if (l > E || r < S) return 0;
		if (l <= S && E <= r) return bm;
		return left->query(l, r) | right->query(l, r);
	}
} *root;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	root = new node(0, s.length() - 1);
	int q, t, x, y;
	string tmp;
	cin >> q;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> x >> tmp;
			x--;
			root->update(x, tmp);
		} else {
			cin >> x >> y;
			x--, y--;
			cout << __builtin_popcount(root->query(x, y)) << '\n';
		}
	}
}