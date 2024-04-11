#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, A[105], B[105], V[105][105];
vector<int> U, H;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) cin >> B[i];
	for (int k = 0; k < 30; k++) {
		int C = 0;
		for (int i = 1; i <= N; i++) C ^= !!(A[i] & (1<<k));
		for (int i = 1; i <= M; i++) C ^= !!(B[i] & (1<<k));
		if (C) return cout << "NO\n", 0;
	}
	for (int k = 0; k < 30; k++) {
		while (!U.empty()) U.pop_back();
		while (!H.empty()) H.pop_back();
		for (int i = 1; i <= M; i++)
			if (B[i] & (1<<k)) U.push_back(i);
		for (int i = 1; i <= N; i++)
			if (A[i] & (1<<k)) {
				if (U.size()) V[i][U.back()] |= (1<<k), U.pop_back();
				else H.push_back(i);
			}
		if (U.size()) {
			for (int i = 0; i < U.size() / 2; i++) {
				if (V[1][U[i]] & (1<<k)) V[2][U[i]] |= (1<<k);
				else V[1][U[i]] |= (1<<k);
				if (V[1][U[U.size() - i - 1]] & (1<<k)) V[2][U[U.size() - i - 1]] |= (1<<k);
				else V[1][U[U.size() - i - 1]] |= (1<<k);
			}
		} else {
			for (int i = 0; i < H.size() / 2; i++) {
				if (V[H[i]][1] & (1<<k)) V[H[i]][2] |= (1<<k);
				else V[H[i]][1] |= (1<<k);
				if (V[H[H.size() - i - 1]][1] & (1<<k)) V[H[H.size() - i - 1]][2] |= (1<<k);
				else V[H[H.size() - i - 1]][1] |= (1<<k);
			}
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cout << V[i][j] << ' ';
		cout << '\n';
	}
}