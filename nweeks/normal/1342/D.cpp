#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tab, taille_max;
	cin >> nb_tab >> taille_max;

	vector<int> tailles(nb_tab);
	for (auto &v : tailles)
		cin >> v;
	vector<int> limites(taille_max);
	for (auto &v : limites)
		cin >> v;

	vector<vector<int>> test_cases;
	sort(tailles.rbegin(), tailles.rend());

	for (auto nb_elem : tailles)
	{
		--nb_elem;
		if (SZ(test_cases) == 0 or limites[nb_elem] <= SZ(test_cases.back()))
		{
			test_cases.push_back({nb_elem+1});
			continue ;
		}
		int lo(0), up(SZ(test_cases) - 1);
		while (lo < up)
		{
			int mid = (lo+up)/2;
			if (limites[nb_elem] > SZ(test_cases[mid]))
				up=mid;
			else 
				lo = mid + 1;
		}
		test_cases[lo].push_back(nb_elem+1);
	}
	cout << SZ(test_cases) << endl;
	for (auto v : test_cases)
	{
		cout << SZ(v) << ' ';
		for (auto w : v)
			cout << w << ' ';
		cout << '\n';
	}
}