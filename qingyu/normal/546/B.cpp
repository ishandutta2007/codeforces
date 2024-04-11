#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 50;
int cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}
	for (int i = 1; i <= 2 * n; ++i) {
		if (cnt[i] > 1) {
			cnt[i + 1] += cnt[i] - 1;
			ans += cnt[i] - 1;
			cnt[i] = 1;
		}
	}
	cout << ans << '\n';
}