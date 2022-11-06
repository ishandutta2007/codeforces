#include <bits/stdc++.h>
using namespace std;
#define int long long

int T, L, R, mem[20][5][2];
string S;

int dp(int n, int k, bool b) {
	if (k > 3) return 0;
	if (n == S.size()) return 1;
	if (mem[n][k][b] != -1) return mem[n][k][b];
	int r = 0;
	if (b) {
		for (int j = 0; j <= S[n] - '0'; j++)
			r += dp(n + 1, k + !!j, j == S[n] - '0');
	} else {
		for (int j = 0; j <= 9; j++)
			r += dp(n + 1, k + !!j, 0);
	}
	return mem[n][k][b] = r;
}

int f(int x) {
	memset(mem, -1, sizeof mem);
	S = to_string(x);
	int r = 0;
	for (int i = 0; i < S.size(); i++)
		for (int j = 1; j <= (i ? 9 : S[i] - '0'); j++)
			r += dp(i + 1, 1, (i ? 0 : j == S[i] - '0'));
	return r + 1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> L >> R;
		cout << f(R) - f(L - 1) << '\n';
	}
}