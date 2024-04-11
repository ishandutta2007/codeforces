#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


string extend(const string &str)
{
	const char ast = '*';
	string ans(1, ast);
	ans.reserve(2 * str.size() + 1);

	for (auto it : str)
	{
		ans += it;
		ans += ast;
	}

	return ans;
}


vector<int> Manacher(const string &str, int to_stop = numeric_limits<int>::max())
{
	int pos = 0, rb = 0;
	vector<int> ans(str.size(), 1);

	for (int i = 0; i < min(to_stop, (int) str.size()); i++)
	{
		if (i < rb)
			ans[i] = min(ans[2 * pos - i], rb - i);

		while (0 <= i - ans[i] && i + ans[i] < str.size() && str[i - ans[i]] == str[i + ans[i]])
			ans[i]++;

		if (rb < i + ans[i])
		{
			rb = i + ans[i];
			pos = i;
		}
	}

	return ans;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	string str;

	cin >> str;

	cerr << str.size() << endl;

	auto mn = Manacher(extend(str));

	vector<int> ord(str.size() + 1);

	for (int i = 1; i <= str.size(); i++)
		if (mn[i] == i + 1)
			ord[i] = 1 + ord[i / 2];

	cout << accumulate(ord.begin(), ord.end(), 0) << endl;
}


void gen(ostream &cout = std::cout)
{
	cout << string((int) 3e6, 'Z') + 'Z' + string((int) 2e6 - 1, 'Z') << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	stringstream ss;

	gen(ss);

	solve(ss);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}