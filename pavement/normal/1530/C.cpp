#include <bits/stdc++.h>
using namespace std;

#define int long long

int T, N, a[100005], b[100005], sa[100005], sb[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> a[i];
		for (int i = 1; i <= N; i++) cin >> b[i];
		sort(a + 1, a + 1 + N, greater<int>());
		sort(b + 1, b + 1 + N, greater<int>());
		for (int i = 0; i <= N + 1; i++) sa[i] = sb[i] = 0;
		for (int i = 1; i <= N; i++) {
			sa[i] = sa[i - 1] + a[i];
			sb[i] = sb[i - 1] + b[i];
		}
		int lo = 0, hi = 1e9, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			// need (N + mid) - (N + mid) / 4 - mid highest stages
			int asc = mid * 100 + sa[max(0ll, (N + mid) - (N + mid) / 4 - mid)];
			int bsc = sb[min(N, (N + mid) - (N + mid) / 4)];
			if (asc >= bsc) {
				ans = mid, hi = mid - 1;
				//cout << "ANS: " << ans << ' ' << asc << ' ' << bsc << '\n';
			} else lo = mid + 1;
		}
		cout << ans << '\n';
	}
}