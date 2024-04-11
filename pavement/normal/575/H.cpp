#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 1e9 + 7;
int N, fac[2000005];

int exp_mod(int a, int b) {
	int r = 1ll;
	while (b) {
		if (b & 1ll) r = r * a % M;
		a = a * a % M;
		b >>= 1ll;
	}
	return r;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	N++;
	fac[0] = 1;
	for (int i = 1; i <= 2 * N; i++) fac[i] = fac[i - 1] * i % M;
	cout << 2 * fac[2 * N - 1] % M * exp_mod(fac[N] * fac[N - 1] % M, M - 2) % M - 1 << '\n';
}