#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, L[200005], R[200005], A[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	A[N + 1] = LLONG_MAX;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++)
		if (A[i] > A[i - 1]) L[i] = L[i - 1] + 1;
		else L[i] = 1;
	for (int i = N; i >= 1; i--)
		if (A[i] < A[i + 1]) R[i] = R[i + 1] + 1;
		else R[i] = 1;
	for (int i = 1; i <= N; i++) M = max({M, L[i], R[i]});
	for (int i = 1; i <= N; i++)
		if (A[i + 1] > A[i - 1]) M = max(M, L[i - 1] + R[i + 1]);
	cout << max(M, L[N]) << '\n';
}