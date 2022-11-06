#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int t[n], sum[3] = {};
	bool used[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		sum[t[i] - 1]++;
	}
	int minT = min(sum[0], min(sum[1], sum[2]));
	cout << minT << '\n';
	for (int i = 0; i < minT; i++) {
		bool allDone[3] = {};
		for (int j = 0; j < n; j++) {
			if (!used[j] && !allDone[t[j] - 1]) {
				used[j] = allDone[t[j] - 1] = true;
				cout << j + 1 << ' ';
			}
		}
		cout << '\n';
	}
}