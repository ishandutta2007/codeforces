#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define int long long

int N, A, U, P, X[200005], DC[200005], M[200005][35], dp[35];
map<int, int> pos;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i];
	sort(X + 1, X + 1 + N);
	for (int i = 1, c = 0; i <= N; i++) {
		if (X[i] != X[i - 1]) c++;
		DC[i] = c;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 30; j++) {
			if (binary_search(X + 1, X + 1 + N, X[i] - (1<<j))) dp[j] = M[pos[X[i] - (1<<j)]][j] + 1;
			else dp[j] = 1;
			M[DC[i]][j] = max(M[DC[i]][j], dp[j]);
			if (dp[j] > A) {
				A = dp[j];
				U = X[i];
				P = j;
			}
		}
		pos[X[i]] = DC[i];
	}
	cout << min(3ll, A) << '\n';
	for (int i = 1; i <= min(3ll, A); i++) {
		cout << U << ' ';
		U -= (1<<P);
	}
	cout << '\n';
}