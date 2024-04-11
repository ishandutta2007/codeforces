#include <bits/stdc++.h>

using namespace std;

const int N = 1050;
int a[N][N], dp[N][N][2], val[N][N][2], sx = 1, sy = 1;

void goR() {
	++sy;
	cout << 'R';
}
void goD() {
	++sx;
	cout << 'D';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int px = -1, py = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (!a[i][j]) {
				px = i, py = j;
				val[i][j][0] = val[i][j][1] = 0;
			}
			else {
				int x = a[i][j];
				while (x % 2 == 0) {
					++val[i][j][0];
					x /= 2;
				}
				while (x % 5 == 0) {
					++val[i][j][1];
					x /= 5;
				}
			}
		}
	}
	memset(dp, 0x3f, sizeof dp);
	dp[1][1][0] = val[1][1][0];
	dp[1][1][1] = val[1][1][1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == 1 && j == 1) continue;
			for (int k : {0, 1}) {
				dp[i][j][k] = min(dp[i - 1][j][k], dp[i][j - 1][k]) + val[i][j][k];
			}
		}
	}
	int okk = min(dp[n][n][0], dp[n][n][1]);
	if (px != -1 && okk > 0) {
		cout << 1 << "\n";
		while (sy < py) goR();
		while (sx < px) goD();	
		while (sy < n) goR();
		while (sx < n) goD();
		cout << '\n';
	}
	else {
		cout << okk << '\n';
		int o = -1;
		if (dp[n][n][0] < dp[n][n][1])
			o = 0;
		else
			o = 1;
		vector<char> steps;
		sx = n, sy = n;
		while (sx != 1 || sy != 1) {
			if (sx == 1) steps.push_back('R'), --sy;
			else if (sy == 1) steps.push_back('D'), --sx;
			else if (dp[sx][sy][o] == dp[sx - 1][sy][o] + val[sx][sy][o]) {
				steps.push_back('D');
				--sx;
			}
			else {
				steps.push_back('R');
				--sy;
			}
		}
		reverse(steps.begin(), steps.end());
		for (char ch : steps)
			cout << ch;
		cout << '\n';
	}
}