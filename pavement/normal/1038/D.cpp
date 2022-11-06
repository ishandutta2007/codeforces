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

int N, T, A[500005];
bool pos, neg;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		pos |= A[i] >= 0;
		neg |= A[i] < 0;
	}
	if (N == 1) return cout << A[1] << '\n', 0;
	if (pos && neg) {
		for (int i = 1; i <= N; i++)
			T += llabs(A[i]);
	} else if (pos) {
		sort(A + 1, A + 1 + N);
		for (int i = 2; i <= N; i++)
			T += A[i];
		T -= A[1];
	} else {
		sort(A + 1, A + 1 + N, greater<int>());
		for (int i = 2; i <= N; i++)
			T -= A[i];
		T += A[1];
	}
	cout << T << '\n';
}