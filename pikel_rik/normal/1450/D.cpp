#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

bool is_permutation(const vector<int> &v) {
	int n = int(v.size());
	vector<bool> visited(n);
	for (int x : v) visited[x] = true;
	for (bool b : visited) {
		if (!b) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i], --a[i];

		vector<int> st, l(n, -1), r(n, n);

		for (int i = 0; i < n; i++) {
			while (!st.empty() && a[st.back()] >= a[i]) {
				st.pop_back();
			}
			l[i] = st.empty() ? -1 : st.back();
			st.push_back(i);
		}

		st.clear();
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && a[st.back()] >= a[i]) {
				st.pop_back();
			}
			r[i] = st.empty() ? n : st.back();
			st.push_back(i);
		}

		vector<vector<int>> add(n + 1), rem(n + 1);
		for (int i = 0; i < n; i++) {
			int ql = l[i] + 1, qr = r[i] - 1;
			if (ql == i || qr == i) {
				add[1].push_back(i);
				rem[qr - ql + 1].push_back(i);
			} else {
				add[1].push_back(i);
				rem[1].push_back(i);
				add[qr - ql + 1].push_back(i);
				rem[qr - ql + 1].push_back(i);
			}
		}

		vector<int> ans(n + 1);

		map<int, int> mp;
		for (int k = 1; k <= n; k++) {
			for (int i : add[k]) {
				mp[a[i]]++;
			}
			if (mp.size() == n - k + 1 && mp.begin()->first == 0 && mp.rbegin()->first == n - k) {
				ans[k] = 1;
			}
			for (int i : rem[k]) {
				if ((--mp[a[i]]) == 0) {
					mp.erase(a[i]);
				}
			}
		}

		for (int i = 1; i <= n; i++) cout << ans[i]; cout << '\n';
	}
	return 0;
}