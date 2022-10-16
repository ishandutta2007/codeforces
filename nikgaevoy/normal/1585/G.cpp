#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


auto foo(const vector<vector<int>> &gr, int v, deque<unsigned> &ans, unordered_set<unsigned> &us)
{
	const auto &row = gr[v];

	if (row.empty())
	{
		ans = {1, 0};
		us = {1, 0};

		return ans.front();
	}

	foo(gr, row.front(), ans, us);

	for (auto it: row | views::drop(1))
	{
		deque<unsigned> ch;

		foo(gr, it, ch, us);

		if (ch.size() < ans.size())
			ans.swap(ch);

		while (ans.size() < ch.size())
			ch.pop_back();

		for (auto i: ranges::iota_view(0, ssize(ans)))
			ans[i] ^= ch[i];

		us.clear();
	}

	auto nxt = ans.front();

	if (us.empty())
	{
		for (auto it: ans)
			us.insert(it);

		nxt = 0;
	}

	while (us.contains(nxt))
		nxt++;

	ans.push_front(nxt);
	us.insert(nxt);

	return ans.front();
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> gr(n);
	vector<int> roots;

	for (auto it: ranges::iota_view(0, n))
	{
		int p;

		cin >> p;
		p--;

		if (p < 0)
			roots.push_back(it);
		else
			gr[p].push_back(it);
	}

	unsigned x = 0;

	for (auto it: roots)
	{
		deque<unsigned> ans;
		unordered_set<unsigned> tmp;

		x ^= foo(gr, it, ans, tmp);
	}

	cout << (x == 0 ? "no" : "yes") << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (weakly_incrementable auto it: ranges::iota_view(0, t))
		solve_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	constexpr int t = 1, n = 2e5;

	cout << t << endl;

	for (auto test: ranges::iota_view(0, t))
	{
		cout << n << endl;

		for (auto it: ranges::iota_view(0, n))
			cout << it << ' ';
		cout << endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	stringstream ss;

	gen(ss);

	solve(ss);

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}