#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

	constexpr int lcm = 720720;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ((i + j) % 2 == 0 ? lcm : lcm + a[i][j] * a[i][j] * a[i][j] * a[i][j]) << ' ';
		}
		cout << '\n';
	}
	return 0;
}