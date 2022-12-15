#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

bool solve(void)
{
	int nb_personnes, t_init;

	cin >> nb_personnes >> t_init;

	bool can=true;

	ll my_lo=t_init, my_up=t_init;

	int prev_t = 0;
	for (int i(0); i < nb_personnes; ++i)
	{
		ll arrival, his_lo, his_up;
		cin >> arrival >> his_lo >> his_up;

		my_up += (arrival - prev_t);
		my_lo -= (arrival - prev_t);
		prev_t = arrival;

		if (my_up < his_lo or my_lo > his_up)
			can = false;
		my_lo = max(my_lo, his_lo);
		my_up = min(my_up, his_up);
	}
	return can;	
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int q;
	cin >> q;
	while (q--)
	{
		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}