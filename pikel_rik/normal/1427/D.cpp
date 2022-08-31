#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

void do_op(vector<int>& a, const vector<int>& op) {
	vector<vector<int>> temp;
	for (int i = 0, j = 0; i < a.size();) {
		temp.emplace_back(a.begin() + i, a.begin() + i + op[j]);
		i += op[j];
		j++;
	}

	reverse(temp.begin(), temp.end());
	a.clear();

	for (auto& v : temp) {
		for (int i : v) {
			a.push_back(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int& i : a) cin >> i;

	vector<vector<int>> ans;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == n) {
			ans.push_back({i + 1, n - i - 1});
			rotate(a.begin(), a.begin() + i + 1, a.end());
		}
	}

	for (int x = n - 1; x > 1; x--) {
		if ((n - x) & 1) {
			vector<int> op;
			for (int i = 0; i < n; i++) {
				if (a[i] == x) {
					if (i > 0) {
						op.push_back(i);
					}
					op.push_back(x - i);
				}
			}
			for (int i = 0; i < n - x; i++) {
				op.push_back(1);
			}
			ans.push_back(op);
			do_op(a, op);
		} else {
			vector<int> op;
			for (int i = 0; i < n - x; i++) {
				op.push_back(1);
			}
			for (int i = n - x; i < n; i++) {
				if (a[i] == x) {
					op.push_back(i - (n - x) + 1);
					if (n - i - 1 > 0) {
						op.push_back(n - i - 1);
					}
				}
			}
			ans.push_back(op);
			do_op(a, op);
		}
	}

	if (n > 1 and n & 1) {
		ans.emplace_back(n, 1);
	}

	cout << ans.size() << '\n';
	for (auto& v : ans) {
		cout << v.size() << ' ';
		for (int i : v) cout << i << ' ';
		cout << '\n';
	}
	return 0;
}