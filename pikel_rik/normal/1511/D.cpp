#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> circuit = {0};
	for (int i = 0; i + 1 < k; i++) {
		for (int j = i + 2; j < k; j++) {
			circuit.push_back(j);
			circuit.push_back(i);
		}
		circuit.push_back(i + 1);
	}

	for (int i = k - 1; i > 0; i--) {
		circuit.push_back(i);
		circuit.push_back(i - 1);
	}

	string ans;
	for (int i = 0; ans.length() < n; i = (i + 1) % circuit.size()) {
		ans += 'a' + circuit[i];
	}
	cout << ans << '\n';
	return 0;
}