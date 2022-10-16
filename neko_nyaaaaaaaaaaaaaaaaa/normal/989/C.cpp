#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a--; b--; c--; d--;
	
	cout << "40 50\n";
	
	vector<vector<char>> ans(40, vector<char>(50, 'A'));
	for (int i = 10; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			ans[i][j] = 'B';
		}
	}
	for (int i = 10; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			ans[i][j] = 'B';
		}
	}
	for (int i = 20; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			ans[i][j] = 'C';
		}
	}
	for (int i = 30; i < 40; i++) {
		for (int j = 0; j < 50; j++) {
			ans[i][j] = 'D';
		}
	}
	
	while (a) {
		for (int i = 11; i < 40; i += 2) {
			for (int j = 0; j < 50; j += 4) {
				ans[i][j] = 'A';
				a--;
				if (a == 0) break;
			}
			if (a == 0) break;
		}
	}
	
	while (b) {
		for (int i = 0; i < 10; i += 2) {
			for (int j = 1; j < 50; j += 4) {
				ans[i][j] = 'B';
				b--;
				if (b == 0) break;
			}
			if (b == 0) break;
		}
		if (b) {
			for (int i = 21; i < 40; i += 2) {
				for (int j = 1; j < 50; j += 4) {
					ans[i][j] = 'B';
					b--;
					if (b == 0) break;
				}
				if (b == 0) break;
			}
		}
	}
	
	while (c) {
		for (int i = 0; i < 20; i += 2) {
			for (int j = 2; j < 50; j += 4) {
				ans[i][j] = 'C';
				c--;
				if (c == 0) break;
			}
			if (c == 0) break;
		}
		if (c) {
			for (int i = 31; i < 40; i += 2) {
				for (int j = 2; j < 50; j += 4) {
					ans[i][j] = 'C';
					c--;
					if (c == 0) break;
				}
				if (c == 0) break;
			}
		}
	}
	
	while (d) {
		for (int i = 0; i < 30; i += 2) {
			for (int j = 3; j < 50; j += 4) {
				ans[i][j] = 'D';
				d--;
				if (d == 0) break;
			}
			if (d == 0) break;
		}
	}
	
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 50; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}