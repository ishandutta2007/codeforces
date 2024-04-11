#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void gen_ans(string a, const string &b, vector<int> &ans)
{
	int l = 0, r = a.size();
	bool rev = false;

	auto atpos = [&a, &l, &r, &rev](int pos) -> char
	{
		if (rev)
			return char(a[r - 1 - pos] ^ '0' ^ '1');
		return a[l + pos];
	};

	auto mov = [&ans, &l, &r, &rev]()
	{
		rev = !rev;

		ans.push_back(r - l);
	};

	auto sw = [&ans, &a, &l, &r, &rev]()
	{
		a[rev ? r - 1 : l] ^= '0' ^ '1';

		ans.push_back(1);
	};

	auto nxt = [&l,&r, &rev]()
	{
		if (rev)
			l++;
		else
			r--;
	};

	while (l < r)
	{
		if (atpos(r - l - 1) != b[r - l - 1])
		{
			if (atpos(0) == b[r - l - 1])
				sw();
			mov();
		}

		nxt();
	}
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	string a, b;

	cin >> a >> b;

	vector<int> ans;
	ans.reserve(b.size() * 2);

	gen_ans(a, b, ans);

	cout << ans.size();

	for (auto it : ans)
		cout << ' ' << it;
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

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}