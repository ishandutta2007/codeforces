#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


vector<int> z_func(const string &str)
{
	vector<int> z(str.size());

	int rb = 0, pos = 0;

	for (int i = 1; i < str.size(); i++)
	{
		if (i < rb)
			z[i] = min(z[i - pos], rb - i);
		while (i + z[i] < str.size() && str[i + z[i]] == str[z[i]])
		{
			z[i]++;
			rb = i + z[i];
			pos = i;
		}
	}

	return z;
}


vector<int> zz_func(const string &str, const string &patt)
{
	vector<int> z(str.size()), ans(str.size() + 1);
	auto pz = z_func(patt);

	int rb = 0, pos = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (i < rb)
			z[i] = min(pz[i - pos], rb - i);
		while (i + z[i] < str.size() && z[i] < patt.size() && str[i + z[i]] == patt[z[i]])
		{
			z[i]++;
			ans[i + z[i]] = z[i];
			rb = i + z[i];
			pos = i;
		}
	}

	return ans;
}


vector<int> Manacher(const string &str)
{
	vector<int> ans(str.size());

	int rb = 0, pos = 0;

	for (int i = 0; i < str.size(); i++)
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

	auto rts = str;

	reverse(rts.begin(), rts.end());

	auto zz = zz_func(str, rts);

	auto mn = Manacher(str);

	vector<pair<int, int>> pref(zz.size() + 1);

	for (int i = 1; i < pref.size(); i++)
		pref[i] = zz[i - 1] > pref[i - 1].first ? pair{zz[i - 1], i - 1 - zz[i - 1]} : pref[i - 1];

	int best = 0;
	vector<pair<int, int>> ans;

	for (int i = 0; i < mn.size(); i++)
	{
		auto sz = pref[i - mn[i] + 2];

		int len = min(sz.first, (int) str.size() - (i + mn[i]));
		int cl = 2 * len + 2 * mn[i] - 1;

		if (cl > best)
		{
			best = cl;

			if (len > 0)
				ans = {{sz.second,        len},
				       {i - mn[i] + 1,    2 * mn[i] - 1},
				       {str.size() - len, len}};
			else
				ans = {{i - mn[i] + 1, 2 * mn[i] - 1}};
		}
	}

	cerr << best << endl;

	cout << ans.size() << endl;
	for (auto it : ans)
		cout << it.first + 1 << ' ' << it.second << endl;
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