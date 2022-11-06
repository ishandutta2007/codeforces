#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
typedef long double ld;

int N, M;
bool A[105][105], can[10005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	can[N] = 1;
	for (int k = N - 1; k >= 1; k--) {
		if (N % k != 0) continue;
		can[k] = can[k << 1];
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= M; j++)
				if (A[i][j] != A[2 * k - i + 1][j]) can[k] = 0;
	}
	for (int i = 1; i <= N; i++)
		if (can[i]) return cout << i << '\n', 0;
}