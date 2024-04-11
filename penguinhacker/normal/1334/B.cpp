#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, x, a[100000];

void solve() {
	cin >> n >> x;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	int ans = 0;
	ll sum = 0;
	for (int i=n-1; i>=0; --i) {
		sum += a[i];
		if (sum<1ll*x*(n-i))
			break;
		else ans++;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}