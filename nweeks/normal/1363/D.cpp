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

int tailleTab, taillePass;

int makeQuery(const vector<int> &indices)
{
	cout << "? " << SZ(indices);
	for (auto v : indices)
		cout << ' ' << v;
	cout << endl;
	cout.flush();
	int ret;
	cin >> ret;
	return ret;
}

int askRange(int l, int r)
{
	vector<int> ind(r-l+1);
	for (int i(0); i < r-l+1; ++i)
		ind[i] = l + i;
	return makeQuery(ind);
}

ll solve(void)
{
	cin >> tailleTab >> taillePass;
	vector<vector<int>> subsets(taillePass);
	for (auto &v : subsets)
	{
		int taille;
		cin >> taille;
		v.resize(taille);
		for (auto &w : v)
			cin >> w;
	}
	int maxTab = askRange(1, tailleTab);

	int lo(1), up(tailleTab);
	while (lo < up)
	{
		int mid = (lo + up)/2;
		if (askRange(lo, mid) == maxTab)
			up = mid;
		else
			lo = mid+1;
	}

	vector<int> sol(taillePass);

	for (int i(0); i < taillePass; ++i)
	{
		vector<int> ind = subsets[i];
		bool contientMax(false);
		for (auto e : ind)
			if (e == lo)
				contientMax = true;	
		if (!contientMax)
			sol[i] = maxTab;
		else
		{
			vector<int> complementaire;
			for (int j(1); j <= tailleTab; ++j)
			{
				bool dedans(false);
				for (auto v : ind)
					if (v == j)
						dedans = true;
				if (!dedans)
					complementaire.push_back(j);
			}
			sol[i] = makeQuery(complementaire);
		}
	}
	cout << "!";
	for (auto s : sol)
		cout << " " << s;
	cout << endl;
	cout.flush();
	string ans;
	cin >> ans;
	assert(ans == "Correct");
	return 0;
}