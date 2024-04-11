#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int m;

vector<pair<int, int>> solution(int n) {
	if (n == 2) {
		return{ {1, 1} };
	}
	vector<pair<int, int>> ans;
	int first = n / 3;
	int start = n / 3 + 1;
	for (int i = 0; i < first; i++) {
		ans.emplace_back(start + first - 1 - i, start + i);
	}
	start += first;
	for (int i = 0; i < first + 1; i++) {
		ans.emplace_back(start + first - i, start + i);
	}
	return ans;
}

void solve() {
	cin >> m;
	if (m == 1) {
		cout << "1\n1 1\n";
		return;
	}
	if (m == 2) {
		cout << "1\n1 1\n";
		return;
	}
	int n = m;
	while (n % 3 != 2) n--;
	auto ans = solution(n);
	for (int i = n; i < m; i++) {
		ans.emplace_back(i, i);
	}

	cout << ans.size() << '\n';
	for (const auto &i : ans)
		cout << i.first + 1 << " " << i.second + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}