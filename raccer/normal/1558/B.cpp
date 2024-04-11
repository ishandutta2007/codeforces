#include <bits/stdc++.h>
using namespace std;

int n, mod;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int sum[4000010];

int main() {
	cin >> n >> mod;
	ADD(sum[1], 1), ADD(sum[2], mod - 1);
	for (int i = 1; i <= n; i++) {
		ADD(sum[i], sum[i - 1]);
		int val = sum[i];
		ADD(sum[i + 1], val);
		for (int j = 2; i * j <= n; j++) {
			int l = i * j, r = min(n, i * j + j - 1);
			ADD(sum[l], val), ADD(sum[r + 1], mod - val);
		}
	}
	printf("%d\n", sum[n]);
	return 0;
}