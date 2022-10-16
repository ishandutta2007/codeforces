#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	string str;

	cin >> n >> str;

	int bal = 0, mb = 0;

	for (auto it : str)
	{
		if (it == '(')
			bal++;
		else
			bal--;
		mb = min (mb, bal);
	}

	cout << (bal == 0 && mb >= -1 ? "Yes" : "No") << endl;
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