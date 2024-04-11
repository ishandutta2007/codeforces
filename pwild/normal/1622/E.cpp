#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<int> e(n);
	for (int &x: e) cin >> x;

	vector<string> a(n);
	for (string &s: a) cin >> s;

	vector<int> perm(m);
	auto consider = [&](int mask) {
		vector<int> sign(n);
		for (int i = 0; i < n; i++) {
			sign[i] = mask & (1 << i) ? 1 : -1;
		}

		vector<vector<int>> indices(2*n+1);
		for (int j = 0; j < m; j++) {
			int value = 0;
			for (int i = 0; i < n; i++) {
				value += sign[i] * (a[i][j]-'0');
			}
			indices[n+value].push_back(j);
		}
		int sum = 0, k = 1;
		for (int v = -n; v <= n; v++) {
			for (int j: indices[n+v]) {
				perm[j] = k;
				sum += v*k++;
			}
		}
		for (int i = 0; i < n; i++) {
			sum -= sign[i]*e[i];
		}
		return sum;
	};

	int best = 0, best_mask = -1;
	for (int mask = 0; mask < (1 << n); mask++) {
		int cur = consider(mask);
		if (cur > best) best = cur, best_mask = mask;
	}

	consider(best_mask);
	for (int j = 0; j < m; j++) {
		cout << perm[j] << " \n"[j+1==m];
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}