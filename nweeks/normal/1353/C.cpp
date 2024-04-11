#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		cout << solve() << '\n';
}

ll solve(void)
{
	ll n; cin >> n;
	int nb_couches((n-1)/2);
	ll ans(0);
	for (ll i(1); i <= nb_couches; ++i)	
		ans += i * ((2*i+1) * (2*i+1) - (2*i-1)*(2*i-1));

	return ans;
}