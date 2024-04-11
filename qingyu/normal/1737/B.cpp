#include <bits/stdc++.h>

using namespace std;

long long calc(long long n) {
	long long l = 1, r = sqrt(n) + 1000, ans = -1;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (mid * mid <= n) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}
long long calc1(long long n) {
	long long l = 1, r = sqrt(n) + 1000, ans = -1;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (mid * (mid + 1) <= n) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}
long long calc2(long long n) {
	long long l = 1, r = sqrt(n) + 1000, ans = -1;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (mid * (mid + 2) <= n) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}
long long solve(long long n) {
	if (n <= 100) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int z = sqrt(i);
			if (i % z == 0) {
				++ans;
			}
		}
		return ans;
	}
	const long long offset = 0;
	return calc(n) + calc1(n) + calc2(n) + offset;
}

void solve() {
	long long l, r;
	cin >> l >> r;
	cout << solve(r) - solve(l - 1) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}