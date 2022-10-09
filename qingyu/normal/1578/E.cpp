#include <bits/stdc++.h>

using namespace std;
int a[2000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		int n, H;
		cin >> n >> H;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + n + 1, greater<int>());
		int s = a[1] + a[2], b = H / s, ans = 0;
		ans += b * 2; H -= b * s;
		if (H) 
		{
			if (H <= a[1]) ++ans;
			else ans += 2;
		}
		cout << ans << '\n';
	}
}