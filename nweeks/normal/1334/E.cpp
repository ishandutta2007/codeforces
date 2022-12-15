#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 1e6;
ll D;
vector<ll> divi;
int nb_divi;
const ll MOD = 998244353;
ll fact[MAXN];
ll fact_inv[MAXN];


ll pow_mod(ll a, ll b)
{
	ll ans(1);
	ll p = a;
	while (b )
	{
		if (b%2)
			ans = (ans * p)%MOD;
		b /= 2;
		p = (p*p)%MOD;	
	}
	return ans;
}

void calc_frac(void)
{
	fact[0] = fact_inv[0] = 1;
	for (int i(0); i+1 < MAXN; ++i)
	{
		fact[i+1] = (fact[i]*(i+1))%MOD;
		fact_inv[i+1] = pow_mod(fact[i+1], MOD-2);
	}
}

void comp_divi(void)
{
	ll DD = D;
	for (ll d(2); d*d <= DD; ++d)
		if (DD%d==0)
		{
			while (DD%d==0)
				DD/=d;
			divi.push_back(d);
		}
	if (DD >1)
		divi.push_back(DD);
	nb_divi = SZ(divi);
}

vector<int> get_decomp(ll u)
{
	vector<int> deco(nb_divi);
	for (int i(0); i < nb_divi; ++i)
	{
		while (u%divi[i]==0)
		{
			u /= divi[i];
			deco[i]++;
		}
	}
	return deco;
}

ll solve_query(ll u, ll v)
{
	auto decomp_u = get_decomp(u);
	auto decomp_v = get_decomp(v);

	ll ways(1);
	ll down(0);
	for (int i(0); i < nb_divi; ++i)
		if (decomp_u[i] > decomp_v[i])
		{
			down += decomp_u[i] - decomp_v[i];
			ways = (ways * fact_inv[decomp_u[i] - decomp_v[i]])%MOD;
		}
	ways = (ways * fact[down])%MOD;
	ll up(0);
	for (int i(0); i < nb_divi; ++i)
		if (decomp_v[i] > decomp_u[i])
		{
			up += decomp_v[i] - decomp_u[i];
			ways = (ways *fact_inv[decomp_v[i] -decomp_u[i]])%MOD;
		}
	ways = (ways * fact[up])%MOD;
	return ways%MOD;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> D;
	int q;
	cin >> q;
	comp_divi();
	calc_frac();
	while (q--)
	{
		ll u, v;
		cin >> u >> v;
		cout << solve_query(u,v) << '\n';
	}
}