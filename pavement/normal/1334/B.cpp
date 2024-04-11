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

int T, N, X, A[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> X;
		for (int i = 1; i <= N; i++) cin >> A[i];
		sort(A + 1, A + 1 + N);
		int S = 0, R = 0;
		for (int i = 1; i <= N; i++) S += A[i];
		for (int i = 1; i <= N; i++) {
			if (S >= X * (N - i + 1)) R = max(R, N - i + 1);
			S -= A[i];
		}
		cout << R << '\n';
	}
}