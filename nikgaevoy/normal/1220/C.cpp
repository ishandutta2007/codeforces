#include <bits/stdc++.h>


using namespace std;


using ll = long long;
mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	string str;

	cin >> str;

	char le = numeric_limits<char>::max();

	for (auto it : str)
	{
		cout << (le < it ? "Ann" : "Mike") << endl;

		le = min (le, it);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4);
	cout << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}