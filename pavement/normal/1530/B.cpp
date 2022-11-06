#include <bits/stdc++.h>
using namespace std;

int T, H, W;
char a[25][25];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> H >> W;
		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++) a[i][j] = '0';
		for (int i = 1; i <= W; i += 2) a[1][i] = '1';
		for (int i = 3; i <= H; i += 2) a[i][W] = '1';
		for (int i = W - 2; i >= 1; i -= 2) a[H][i] = '1';
		for (int i = H - 2; i >= 3; i -= 2) a[i][1] = '1';
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) cout << a[i][j];
			cout << '\n';
		}
	}
}