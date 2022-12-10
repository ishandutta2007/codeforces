//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

const int maxm = 1000 + 10;
long long cnt[maxm], n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int r = i * i % m;
		cnt[r] += max(0LL, (n - i + m)) / m;
	}
	cnt[0]--;
	long long ans = 0;
	for (int i = 0; i < m; i++)
		ans += 1LL * cnt[i] * cnt[(m - i)%m];
	cout << ans << endl;
	return 0;
}