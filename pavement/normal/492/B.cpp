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

int N, L, A[1005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L;
	for (int i = 1; i <= N; i++) cin >> A[i];
	sort(A + 1, A + 1 + N);
	ld lo = A[1], hi = 1e9, ans = -1;
	for (int i = 1; i <= 10000; i++) {
		bool v = 0;
		ld mid = (lo + hi) / 2, fr = A[1] + mid;
		for (int i = 2; i <= N; i++)
			if (A[i] - mid <= fr) fr = A[i] + mid;
			else v = 1;
		v |= fr < L;
		if (v) lo = mid;
		else ans = mid, hi = mid;
	}
	cout << fixed << setprecision(10) << ans << '\n';
}