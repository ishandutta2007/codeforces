/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

string D[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };

int const BITS = 7;

int encode(const string &s) {
	int ret = 0;
	for (int j = 0; j < BITS; j++) {
		ret |= (s[j] - '0') << j;
	}
	return ret;
}

vector<int> F(1 << BITS);

int popcnt(int x) {
	return F[x];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	vector<int> dMasks(10);
	for (int i = 0; i < 10; i++) {
		dMasks[i] = encode(D[i]);
	}
	F[0] = 0;
	for (int i = 1; i < 1 << BITS; i++) {
		F[i] = F[i & (i - 1)] + 1;
	}
	int n, broken;
	cin >> n >> broken;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a[i] = encode(s);
	}
	vector<int> ans(n);
	vector<vector<int>> canMake(n + 1, vector<int>(broken + 1));
	canMake[n][0] = 1;
	for (int i = n; i > 0; i--) {
		int x = a[i - 1];
		for (int j = broken; j >= 0; j--) {
			if (!canMake[i][j]) continue;
			for (int d = 0; d < 10; d++) {
				if ((x & dMasks[d]) != x) continue;
				int turnon = popcnt(dMasks[d] & ~x);
				if (j + turnon <= broken) {
					canMake[i - 1][j + turnon] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ans[i] = -1;
		for (int dig = 9; dig >= 0; dig--) {
			if ((a[i] & dMasks[dig]) != a[i]) {
				continue;
			}
			int leftBroken = broken - popcnt(dMasks[dig] & ~a[i]);
			if (leftBroken >= 0 && canMake[i + 1][leftBroken]) {
				ans[i] = dig;
				broken = leftBroken;
				break;
			}
		}
		if (ans[i] == -1) {
			cout << "-1\n";
			return 0;
		}
	}
	for (int i = 0; i < n; i++) cout << ans[i];
		cout << '\n';
}