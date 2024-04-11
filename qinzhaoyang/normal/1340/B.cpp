#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int vis[10][7] = {{1, 1, 1, 0, 1, 1, 1},
				{0, 0, 1, 0, 0, 1, 0},
				{1, 0, 1, 1, 1, 0, 1},
				{1, 0, 1, 1, 0, 1, 1},
				{0, 1, 1, 1, 0, 1, 0},
				{1, 1, 0, 1, 0, 1, 1},
				{1, 1, 0, 1, 1, 1, 1},
				{1, 0, 1, 0, 0, 1, 0},
				{1, 1, 1, 1, 1, 1, 1},
				{1, 1, 1, 1, 0, 1, 1}};

int n, k, f[N][7], ans[N];
string s;
bool dp[N][N];

int need(int x[7], int y[7]) {
	int cnt = 0;
	for (int i = 0; i < 7; i++)
		if (x[i] != y[i]) {
			if (x[i] == 0) cnt++;
			else return -1;
		}
	return cnt;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < 7; j++)
			f[i][j] = s[j] - '0';
	}
	dp[n + 1][0] = 1;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 10; j++) {
			int t = need(f[i], vis[j]);
			if (t != -1)
				for (int o = 0; o <= k - t; o++)
					dp[i][o + t] |= dp[i + 1][o];
		}
	}
	if (!dp[1][k]) return puts("-1") * 0;
	for (int i = 1; i <= n; i++)
		for (int j = 9; j >= 0; j--) {
			int t = need(f[i], vis[j]);
			if (t != -1 && k >= t && dp[i + 1][k - t]) {
				ans[i] = j, k -= t;
				break;
			}
		}
	for (int i = 1; i <= n; i++)
		cout << ans[i];
	cout << endl;
	return 0;
}