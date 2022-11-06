#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, P[100005], S, F, m, ans;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i], P[i] += P[i - 1];
	cin >> S >> F;
	for (int i = 1; i <= N; i++) {
		int s = S - i + 1, e = F - i, tmp;
		if (s <= 0) s += N;
		if (e <= 0) e += N;
		if (s > e) tmp = P[N] - P[s - 1] + P[e];
		else tmp = P[e] - P[s - 1];
		if (tmp > m) m = tmp, ans = i;
	}
	cout << ans << '\n';
}