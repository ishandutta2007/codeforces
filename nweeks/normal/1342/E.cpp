#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const ll MOD = 998244353;
const int MAXN = 2e5+1;
ll fact[MAXN];
ll inv[MAXN];


ll fast_pow(ll a, ll b)
{
	ll ret(1);
	for (ll p(a); b; p=(p*p)%MOD, b/=2)
		if (b%2)
			ret = (ret * p)%MOD;
	return ret;
}

void pre(void)
{
	fact[0]=inv[0] = 1;
	for (int i(1); i < MAXN; ++i)
	{
		fact[i] = (i*fact[i-1])%MOD;
		inv[i] = fast_pow(fact[i], MOD-2);
	}
}

ll binom(ll n, ll k)
{
	ll ans = fact[n] *inv[k];
	ans %= MOD;
	ans = (ans * inv[n-k])%MOD;
	return ans;
	return (fact[n]*inv[k]%MOD*inv[n-k])%MOD;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, k;
	cin >> n >> k;

	pre();
	if (k >= n)
	{
		cout << 0 << endl;
		return 0;
	}
	if (k==0)
	{
		cout << fact[n] << endl;
		return 0;
	}
	ll nb_surje(0);
	for (int i(0); i <= n-k; ++i)
	{
		ll add = binom(n-k, i)*fast_pow(i, n)%MOD;
		if ((n-k-i)%2) add = MOD-add;
		nb_surje = (nb_surje + add)%MOD;
	}
	ll ans = (2 * nb_surje%MOD)* binom(n, k)%MOD;
	cout << ans << endl;
}