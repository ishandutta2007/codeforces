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
		solve();
}

ll solve(void)
{
	ll a, b, c;
	cin >> a >> b >> c;

	ll best_sol(1e18);
	int asol(-1), bsol(-1), csol(-1);

	for (int pick_a(1); pick_a <= 2e4; ++pick_a)
		for (int pick_b(pick_a); pick_b <= 2e4; pick_b += pick_a)
			for (int pick_c(pick_b); pick_c <= 2e4; pick_c += pick_b)
			{
				int cursol = abs(a-pick_a) + abs(b-pick_b) + abs(c-pick_c);
				if (cursol < best_sol)
					asol=pick_a, bsol=pick_b, csol=pick_c, best_sol=cursol;
			}
	cout << best_sol<<'\n' << asol <<' ' << bsol <<' ' << csol << '\n';
	return 0;
}