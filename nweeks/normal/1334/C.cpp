#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

ll solve(void)
{
	int nb_monstres;
	cin >> nb_monstres;
	vector<pair<ll, ll> > monstres(nb_monstres);
	for (auto &[health, bomb] : monstres)
		cin >> health >> bomb;
	
	ll tot(0);
	for (int i(0); i < nb_monstres; ++i)
		tot += max(0LL, monstres[(i+1)%nb_monstres].first - monstres[i].second);
	
	ll ans(1e18);
	for (int i(0); i < nb_monstres; ++i)
		ans = min(ans, tot -max(0LL,monstres[(i+1)%nb_monstres].first-monstres[i].second)+monstres[(i+1)%nb_monstres].first);
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