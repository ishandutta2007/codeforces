#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
typedef long double ld;

int T, N, A, F, K, M = LLONG_MIN, B, C, X, Y, Z;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> F >> T;
		if (T <= K) M = max(M, F);
		else M = max(M, F - (T - K));
	}
	cout << M << '\n';
}