#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn = int(1e5) + 10;

int n;
int d[maxn];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int tc; cin >> tc;
for(;tc--;) {
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> d[i];
	sort(d+1, d+n+1);
	ll ans = d[n];
	ll ps = 0;
	for (int i=2; i<=n; ++i) {
		ans -= d[i] * 1ll * (i-1) - ps;
		ps += d[i];
	}

	cout << ans << '\n';
}
	return 0;
}