#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, O, A[40];
vector<int> P;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 0; i < 1<<(N>>1); i++) {
		int Y = 0;
		for (int j = 0; j < (N>>1); j++)
			if (i & (1<<j)) {
				Y += A[j + 1];
				Y %= M;
			}
		P.push_back(Y);
	}
	sort(P.begin(), P.end());
	for (int i = 0; i < 1<<((N>>1) + (N&1)); i++) {
		int Y = 0;
		for (int j = 0; j < ((N>>1) + (N&1)); j++)
			if (i & (1<<j)) {
				Y += A[j + (N>>1) + 1];
				Y %= M;
			}
		auto it = upper_bound(P.begin(), P.end(), M - Y - 1);
		if (it != P.begin()) {
			--it;
			O = max(O, Y + *it);
		}
	}
	cout << O << '\n';
}