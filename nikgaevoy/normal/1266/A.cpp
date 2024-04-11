#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		static string str;

		cin >> str;

		if (count(str.begin(), str.end(), '0') == str.size())
		{
			cout << "red" << endl;

			continue;
		}

		bool ok = accumulate(str.begin(), str.end(), 0ll) % 3 == 0;
		ok &= str.find('0') != std::string::npos;
		ok &= str.find('2') != std::string::npos || str.find('4') != std::string::npos ||
		      str.find('6') != std::string::npos || str.find('8') != std::string::npos ||
		      count(str.begin(), str.end(), '0') > 1;

		cout << (ok ? "red" : "cyan") << endl;
	}
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