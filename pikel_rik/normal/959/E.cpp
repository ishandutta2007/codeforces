#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;

	long long ans = 0;
	for (long long pw = 1; pw <= n; pw *= 2) {
		long long temp = (n + pw - 1) / pw;
		ans += (temp / 2) * pw;
	}
	cout << ans << '\n';
	return 0;
}