#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int f[1000010], sum[1000010];

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i + i; j <= n; j += i) {
			f[j]++;
		}
	}
	f[0] = 1, sum[0] = 1;
	for (int i = 1; i <= n; i++) {
		ADD(f[i], sum[i - 1]), ADD(sum[i] = sum[i - 1], f[i]);
	}
	cout << f[n] << endl; 
	return 0;
}