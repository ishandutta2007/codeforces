#include <bits/stdc++.h>
using namespace std;

int n;
long long T;
string s;

int pos(char c) {
	return c - 'a';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> T >> s;

	T -= (1 << pos(s[n - 1]));
	T += (1 << pos(s[n - 2]));

	long long sum = 0;
	for (int i = 0; i < n - 2; i++) {
		sum += (1 << pos(s[i]));
	}

	long long target = sum - T;

	if (target < 0) {
		cout << "No\n";
		return 0;
	}

	vector<int> cnt(60);
	for (int i = 0; i < n - 2; i++) {
		cnt[pos(s[i]) + 1]++;
	}

	for (int i = 0; i < 60; i++) {
		if (target & (1ll << i)) {
			if (cnt[i] == 0) {
				cout << "No\n";
				return 0;
			}
			cnt[i] -= 1;
		}
		if (i + 1 < 60) {
			cnt[i + 1] += cnt[i] / 2;
		}
	}

	cout << "Yes\n";
	return 0;
}