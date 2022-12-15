#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const ll MOD = 998244353 ;

ll binpow(ll a, ll b)
{
	a %= MOD;
	if (a<0) a += MOD;
	ll p = a;
	ll ret = 1;
	while (b > 0)
	{
		if (b&1)
			ret = (ret*p)%MOD;
		p = (p*p)%MOD;
		b /= 2;
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, m, L, R;
	cin >> n >> m >> L >> R;	
	ll cnt_even;
	ll cnt_odd;

	if (L%2 == 0)
		cnt_even = 1 + (R-L)/2;
	else
		cnt_even = (L == R ? 0 : 1+(R-L-1)/2);
	cnt_odd= R-L+1 - cnt_even;

	ll inv_2 = binpow(2, MOD-2);
	assert( (2*inv_2)%MOD == 1);

	ll s = binpow(cnt_even + cnt_odd, n*m);
	ll d = binpow(cnt_even - cnt_odd, n*m);

	ll even_sum = inv_2*(s + d)%MOD;
	ll odd_sum = inv_2 * (s-d)%MOD;
	if (odd_sum < 0) odd_sum += MOD;

	ll ans = even_sum;
	if ((n*m)%2 == 1)
	{
		ans += odd_sum;
		ans %= MOD;
	}
	cout << ans << endl;
}