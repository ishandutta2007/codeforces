#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		vector<int> szs;

		int cur = 1;
		for (int i = 2; i < n; i++) {
			if (a[i] < a[i - 1]) {
				szs.push_back(cur);
				cur = 1;
			} else {
				cur++;
			}
		}

		szs.push_back(cur);
		vector<int> lvl(szs.size());

		queue<int> q;
		q.push(0);
		lvl[0] = 1;

		int last = 1;
		while (!q.empty()) {
			int i = q.front();
			int x = szs[i];
			q.pop();

			for (int ii = last; ii < min(last + x, (int)szs.size()); ii++) {
				lvl[ii] = 1 + lvl[i];
				q.push(ii);
			}
			last = min(last + x, (int)szs.size());
		}

		cout << lvl.back() << '\n';
	}
	return 0;
}