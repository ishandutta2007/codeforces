#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mt make_tuple
#define mp make_pair

int N, C[1005], mem[1005][2][2][2];
bool HA[1005], HB[1005], HC[1005];
string S;

int dp(int n, bool a, bool b, bool c) {
	if (n == 0) return (a && b && c ? 0 : 1e9);
	if (mem[n][a][b][c] != -1) return mem[n][a][b][c];
	bool ca = a | HA[n], cb = b | HB[n], cc = c | HC[n];
	return mem[n][a][b][c] = min(dp(n - 1, ca, cb, cc) + C[n], dp(n - 1, a, b, c));
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> C[i] >> S;
		for (char c : S)
			if (c == 'A') HA[i] = 1;
			else if (c == 'B') HB[i] = 1;
			else HC[i] = 1;
	}
	cout << (dp(N, 0, 0, 0) == 1e9 ? -1 : dp(N, 0, 0, 0)) << '\n';
}