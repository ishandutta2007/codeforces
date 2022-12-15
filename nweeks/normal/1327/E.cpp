#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const ll MOD = 998244353;

ll pow_mod(ll a, ll b)
{
	ll ans(1);
	ll p = a;
	while (b >= 1)
	{
		if (b&1)
			ans = (ans*p)%MOD;
		b /= 2;
		p = (p*p)%MOD;
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;

	for (int i(1); i <= n; ++i)
	{
		ll ans = (i < n ? 2 : 1) * 10 * (i < n ? 9 : 1);
		if (i < n)
			ans *= pow_mod(10, n-i-1);
		if (i < n-1)
			ans += (n-i-1) * 10LL * 81 * pow_mod(10, n-i-2);
		ans %= MOD;
		cout << ans << ' ';
	}

	cout << endl;
}