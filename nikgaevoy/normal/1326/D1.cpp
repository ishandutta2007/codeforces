#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


string extend(const string &str)
{
	string ret = "*";

	for (auto it : str)
	{
		ret += it;
		ret += '*';
	}

	return ret;
}


int Manacher(const string &str)
{
	vector<int> ans(str.size());

	int rb = 0, mid = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (i < rb)
			ans[i] = min(ans[2 * mid - i], rb - i);

		while (0 <= i - ans[i] && i + ans[i] < str.size() && str[i - ans[i]] == str[i + ans[i]])
			ans[i]++;

		if (i + ans[i] > rb)
		{
			rb = i + ans[i];
			mid = i;
		}
	}

	return str.size() - mid;
}


string solve_string(const string &str)
{
	int ml = 0, mr = str.size();

	while (str[ml] == str[mr - 1])
	{
		ml++;
		mr--;
	}

	auto mid = extend(str.substr(ml, mr - ml));

	auto add = Manacher(mid);

	mr -= add - 1;

	assert(ml < mr);

	auto t = str.substr(0, ml) + str.substr(mr);

	auto rt = t;
	reverse(rt.begin(), rt.end());

	assert(rt == t);

	return t;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	string str;

	cin >> str;

	auto rts = str;

	reverse(rts.begin(), rts.end());

	if (str == rts)
	{
		cout << str << '\n';

		return;
	}

	auto ans = solve_string(str);
	auto rans = solve_string(rts);

	if (rans.size() > ans.size())
		rans.swap(ans);

	cout << ans << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	cout << 1 << endl;

	uniform_int_distribution<char> uid('a', 'c');

	string str(5, 'a');

	for (auto &it : str)
		it = uid(mt);

	cout << str << endl;
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

	while(true)
	{
		stringstream ss;

		gen(ss);

		cout << ss.str() << endl;

		solve(ss);
	}

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}