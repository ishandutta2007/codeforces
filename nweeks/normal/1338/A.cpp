#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

ll solve(void)
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for (auto & v : a) cin >> v;

	ll ans(0);
	for (int i(0); i+1 < n; ++i)
	{
		ll diff = a[i]-a[i+1];
		if (diff <= 0) continue;
		ll p(0);
		while ((1LL<<p)-1 < diff)
			++p;
		ans = max(ans, p);
		a[i+1] = a[i];
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}