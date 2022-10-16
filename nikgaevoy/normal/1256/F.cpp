#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


int buble(string str)
{
	int q = 0;

	for (int i = 0; i < str.size(); i++)
		for (int j = 1; j < str.size(); j++)
			if (str[j] < str[j - 1])
			{
				swap(str[j], str[j - 1]);
				q++;
			}

	return q;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	string s, t;

	cin >> n >> s >> t;

	auto ts = s, tt = t;

	sort(ts.begin(), ts.end());
	sort(tt.begin(), tt.end());

	if (ts != tt)
	{
		cout << "NO" << endl;

		return;
	}

	if (unique(ts.begin(), ts.end()) != ts.end())
	{
		cout << "YES" << endl;

		return;
	}

	cout << (buble(s) % 2 == buble(t) % 2 ? "YES" : "NO") << endl;
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