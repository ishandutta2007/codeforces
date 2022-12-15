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
	int nb_cartes, nb_jokers, nb_joueurs;
	cin >> nb_cartes >> nb_jokers >> nb_joueurs;
	int x = min(nb_cartes/nb_joueurs, nb_jokers);
	nb_jokers -= x;
	int y = (nb_jokers + nb_joueurs - 2)/(nb_joueurs-1);
	cout << x -y<<'\n';

	return 0;
}