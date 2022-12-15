#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const ll MOD = 998244353;

ll fact(int i)
{
	ll ret(1);
	for (int j(1); j <= i; ++j)
		ret = (ret * j)%MOD;
	return ret;
}

ll fastpow(ll a, ll b)
{
	ll ret(1);
	for (ll p=a; b; b/= 2, p=(p*p)%MOD)
		if(b%2)
			ret = (ret * p)%MOD;
	return ret;
}

ll inv(ll a)
{
	return fastpow(a, MOD-2);
}

ll binom(ll n, ll k)
{
	return ((fact(n)*inv(fact(k))%MOD) * inv(fact(n-k)))%MOD;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	if (n==2) cout<<0<<endl;
	else cout << (binom(m, n-1) * fastpow(2, n-3)%MOD*(n-2))%MOD<< endl; 


}