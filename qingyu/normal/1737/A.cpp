#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> arr(26);
	for (int i = 0; i < n; i++) {
		++arr[s[i] - 'a'];
	}
	for (int i = 0; i < k; ++i) {
		int j = 0;
		while (j < 26 && arr[j] && j < n / k) {
			--arr[j];
			++j;
		}
		cout << char('a' + j);
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}