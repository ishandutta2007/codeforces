#include <bits/stdc++.h>
using namespace std;

struct trie{
	trie* child[2];
	int val = -1, cnt = 0;
	trie() {
		child[0] = child[1] = nullptr;
	}
};

trie *t = new trie();

void insert(int k, int id) {
	trie *p = t;
	for (int i = 29; i >= 0; i--) {
		int bt = (1 << i) & k;
		
		if (p->child[bt > 0] == nullptr) {p->child[bt > 0] = new trie();}
		p->cnt++; p = p->child[bt > 0];
	}
	p->cnt++; p->val = id;
}

void delet(int k) {
	trie *p = t;
	for (int i = 29; i >= 0; i--) {
		int bt = (1 << i) & k;
		
		if (p->child[bt > 0] == nullptr) {p->child[bt > 0] = new trie();}
		p->cnt--; p = p->child[bt > 0];
	}
	p->cnt--; p->val = -1;
}

pair<int, int> go(int k) {
	trie *p = t;
	int ans = 0;
	for (int i = 29; i >= 0; i--) {
		int bt = (1 << i) & k;
	
		if (bt == 0) {
			if (p->child[1] != nullptr && p->child[1]->cnt > 0) {
				ans |= (1 << i);
				p = p->child[1];
			} else {
				p = p->child[0];
			}
		} else {
			if (p->child[0] != nullptr && p->child[0]->cnt > 0) {
				ans |= (1 << i);
				p = p->child[0];
			} else {
				p = p->child[1];
			}
		}
	}
	return {ans, p->val};
}

int n, k, a[300005];

vector<int> solve_trie(vector<int> l, vector<int> r) {
	if (l.empty()) {
		return vector<int>(1, r[0]);
	}
	if (r.empty()) {
		return vector<int>(1, l[0]);
	}

	for (int i: l) {
		insert(a[i], i);
	}

	int lf = -1, rf = -1;
	for (int i: r) {
		auto [val, id] = go(a[i]);
		if (val >= k) {
			lf = id, rf = i; break;
		}
	}

	for (int i: l) {
		delet(a[i]);
	}

	vector<int> ans;
	if (rf == -1) {
		ans.push_back(l[0]);
	} else {
		ans.push_back(lf);
		ans.push_back(rf);
	}
	return ans;
}

vector<int> solve(int b, vector<int> p) {
	if (p.empty()) return p;
	if (b == -1) {
		return p;
	}

	vector<int> l, r;
	for (int i: p) {
		if (a[i] & (1 << b)) {
			l.push_back(i);
		} else {
			r.push_back(i);
		}
	}

	if (k < (1 << b)) {
		// bit 0

		// different groups are DEFINITELY connected
		vector<int> ans1 = solve(b-1, l);
		vector<int> ans2 = solve(b-1, r);

		for (int i: ans2) ans1.push_back(i);
		return ans1;

	} else {
		// bit 1
		
		// from different group ONLY
		// find biggest xor sum elements
		return solve_trie(l, r);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (k == 0) {
		cout << n << '\n';
		for (int i = 1; i <= n; i++) {
			cout << i << ' ';
		}
		cout << '\n';
		return 0;
	}

	vector<int> p;
	for (int i = 0; i < n; i++) {
		p.push_back(i);
	}

	vector<int> ans = solve(29, p);
	if (ans.size() <= 1) {
		cout << "-1\n";
	} else {
		cout << ans.size() << '\n';
		for (int i: ans) {
			cout << i+1 << ' ';
		}
	}

	return 0;
}