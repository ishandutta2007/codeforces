#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, W, a, b, c, C[1000005], L[1000005], P[1000005], Y[1000005];
vector<int> A[1000005], D[1000005];
vector<tuple<int, int, int> > U[1000005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> W;
	for (int i = 1; i <= N; i++) {
		cin >> L[i];
		C[i] = 1;
		A[i].resize(L[i] + 1);
		for (int j = 1; j <= L[i]; j++) cin >> A[i][j];
		U[L[i] + 1].emplace_back(i, -1ll, 1ll);
		U[W - L[i] + 1].emplace_back(i, -1ll, -1ll);
		if (L[i] <= 1 - L[i] + W) {
			for (int j = 1; j < L[i]; j++)
				U[j].emplace_back(i, max(1ll, j + L[i] - W), min(j, L[i]));
			U[L[i]].emplace_back(i, 1ll, L[i]);
			for (int j = 2 - L[i] + W; j <= W; j++)
				U[j].emplace_back(i, max(1ll, j + L[i] - W), min(j, L[i]));
		} else {
			for (int j = 1; j <= W; j++)
				U[j].emplace_back(i, max(1ll, j + L[i] - W), min(j, L[i]));
		}
	}
	for (int i = 1; i <= W; i++) {
		for (auto j : U[i]) {
			tie(a, b, c) = j;
			if (b == -1)
				C[a] += c;
			else {
				while (D[a].size() - Y[a] && D[a][Y[a]] < b) Y[a]++;
				while (D[a].size() - Y[a] && A[a][D[a].back()] <= A[a][c]) D[a].pop_back();
				D[a].push_back(c);
				M -= P[a];
				if (C[a]) P[a] = max(0ll, A[a][D[a][Y[a]]]);
				else P[a] = A[a][D[a][Y[a]]];
				M += P[a];
			}
		}
		cout << M << ' ';
	}
}