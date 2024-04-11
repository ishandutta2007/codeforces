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
	{
		solve();
		cout << '\n';
	}
}

ll solve(void)
{
	int nbElem;
	cin >> nbElem;

	vector<int> arr(nbElem);
	for (auto &v : arr)
		cin >> v;
	int tot(0);
	for (auto v : arr)
		tot = tot ^ v;
	if (!tot)
	{
		cout << "DRAW";
		return 0;
	}
	int largest_bit(0);
	for (int i(0); i < 30; ++i)
		if ((1<<i)&tot)
			largest_bit = i;
	
	int nbAvec(0), nbSans(0);
	for (auto v : arr)
	{
		if ((1<<largest_bit)&v)
			nbAvec++;
		else
			nbSans++;
	}
	
	if (nbSans% 2 == 0)
	{
		int nbPris = nbAvec - nbAvec/2;
		if (nbPris%2)
			cout << "WIN";
		else
			cout << "LOSE";
	}
	else
		cout << "WIN";
	return 0;
}