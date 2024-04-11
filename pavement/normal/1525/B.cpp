#include <bits/stdc++.h>
using namespace std;

int T, N, A[55];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> A[i];
		if (is_sorted(A + 1, A + 1 + N)) cout << "0\n";
		else if (A[1] == 1 || A[N] == N) cout << "1\n";
		else if (A[1] == N && A[N] == 1) cout << "3\n";
		else cout << "2\n";
	}
}