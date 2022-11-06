#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int T, N, A[300005], B[300005], C[300005], PC[300005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int M = LLONG_MAX;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> A[i] >> B[i];
			if (i > 1) C[i] = max(0ll, A[i] - B[i - 1]);
		}
		C[1] = max(0ll, A[1] - B[N]);
		for (int i = 1; i <= N; i++)
			PC[i] = PC[i - 1] + C[i];
		for (int i = 1; i <= N; i++)
			M = min(M, PC[i - 1] + PC[N] - PC[i] + A[i]);
		cout << M << '\n';
	}
}