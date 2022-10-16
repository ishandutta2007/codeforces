#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;

int k, A, h, pw[35];

void init() {
	pw[0] = 1;
	for (int i = 1; i <= 32; i++) {
		pw[i] = (pw[i-1]*A) % M;
	}
}

int get_hs(vector<int> p, int l, int r) {
	int ans = 0;
	for (int i = l; i < r; i++) {
		ans = (ans + (i+1)*pw[p[i]]) % M;
	}
	return ans;
}

void gen(int l, int r, map<int, vector<int>> &mp) {
	int sz = r-l;

	for (int m = 0; m < (1 << (sz-1)); m++) {
		vector<int> res(1 << k);

		vector<int> surv;
		for (int i = l; i < r; i++) {
			surv.push_back(i);
		}
		
		int pl = (1 << (k-1));
		vector<int> nxt;
		for (int j = 0; j < sz; j++) {
			if (surv.empty()) {
				surv = nxt; nxt.clear();
				pl /= 2;
			}

			int u = surv.back(); surv.pop_back();
			int v = surv.back(); surv.pop_back();

			if (m & (1 << j)) {
				nxt.push_back(u);
				res[v] = pl+1;
			} else {
				nxt.push_back(v);
				res[u] = pl+1;
			}
		}

		mp[get_hs(res, l, r)] = res;
	}
}

void solve(int l, int r, map<int, vector<int>> m1, map<int, vector<int>> m2) {
	for (auto [hs, v]: m1) {
		for (int i = l; i < r; i++) {
			if (v[i] == 2) v[i] = 1;
		}

		int hl = get_hs(v, l, r);
		int hn = (h - hl + M) % M;

		if (m2.find(hn) != m2.end()) {
			for (int i = 0; i < (1 << k); i++) {
				cout << max(v[i], m2[hn][i]) << ' ';
			}
			exit(0);
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> k >> A >> h;
	init();

	map<int, vector<int>> m1, m2;
	gen(0, 1 << (k-1), m1);
	gen(1 << (k-1), 1 << k, m2);

	solve(0, 1 << (k-1), m1, m2);
	solve(1 << (k-1), 1 << k, m2, m1);

	cout << "-1\n";

	return 0;
}