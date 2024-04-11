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

int N, R = LLONG_MAX, A[1005], P[1005], S[1005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (i > 1) P[i] = max(P[i - 1], A[i] - A[i - 1]);
	}
	for (int i = N - 1; i >= 1; i--)
		S[i] = max(S[i + 1], A[i + 1] - A[i]);
	for (int i = 2; i < N; i++) {
		int x = max({P[i - 1], S[i + 1], A[i + 1] - A[i - 1]});
		R = min(R, x);
	}
	cout << R << '\n';
}