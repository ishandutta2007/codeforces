#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
char c[303][303];

void solve() {
	cin >> n;
	int cnt[2][3] = {};
	int k = n * n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> c[i][j];
		if (c[i][j] == 'X') cnt[0][(i + j) % 3]++;
		else if (c[i][j] == 'O') cnt[1][(i + j) % 3]++;
		else k--;
	}
	bool good = false;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
		if (good || i == j || cnt[0][i] + cnt[1][j] > k / 3) continue;
		for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) {
			if ((x + y) % 3 == i && c[x][y] == 'X') c[x][y] = 'O';
			if ((x + y) % 3 == j && c[x][y] == 'O') c[x][y] = 'X';
		}
		good = true;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << c[i][j];
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}