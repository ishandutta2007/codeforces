#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	string str;

	cin >> str;

	vector<int> ans;

	for (int i = 0; i < str.size(); i++)
	{
		if (str.substr(i, 4) == "twon")
		{
			ans.push_back(i + 2);
			i += 2;
		}
		else
		{
			if (str.substr(i, 3) == "one")
				ans.push_back(i + 1);
			if (str.substr(i, 3) == "two")
				ans.push_back(i + 1);
		}
	}

	cout << ans.size() << endl;
	for (auto it : ans)
		cout << it + 1 << ' ';
	cout << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}