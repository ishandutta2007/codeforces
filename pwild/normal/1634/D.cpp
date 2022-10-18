#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int query(int i, int j, int k) {
	cout << "? " << i << " " << j << " " << k << endl;
	int res; cin >> res;
	if (res == -1) exit(0);
	return res;
}

void solve() {
	int n; cin >> n;
	deque<int> v;
	for (int i = 1; i <= n; i++) v.push_back(i);
	while (size(v) >= 4) {
		vector<int> ans(4);
		for (int i = 0; i < 4; i++) {
			vector<int> w(begin(v), begin(v)+4);
			w.erase(begin(w)+i);
			ans[i] = query(w[0], w[1], w[2]);
		}

		int max_ans = *max_element(begin(ans), end(ans));

		for (int i = 3; i >= 0; i--) {
			if (ans[i] == max_ans) v.erase(begin(v)+i);
		}

		if (size(v) == 3) {
			for (int i = 1; i <= n; i++) {
				if (find(begin(v), end(v), i) != end(v)) continue;
				v.push_back(i);
				break;
			}
		}
	}

	cout << "! " << v[0] << " " << v[1] << endl;
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}