#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<tuple<int, int, int>> arr(n);

	for (auto &[l, r, c]: arr)
	{
		cin >> l >> r >> c;
		r++;
	}

	int rb = numeric_limits<int>::lowest();
	int lb = numeric_limits<int>::max();

	minheap<int> hl, hr, both;
	vector<int> ans;

	for (auto[l, r, c]: arr)
	{
		if (l < lb)
		{
			hl = {};
			both = {};

			lb = l;
		}
		if (r > rb)
		{
			hr = {};
			both = {};

			rb = r;
		}

		if (l == lb)
			hl.push(c);
		if (r == rb)
			hr.push(c);
		if (l == lb && r == rb)
			both.push(c);

		assert(!hl.empty() && !hr.empty());

		int cur = hl.top() + hr.top();

		if (!both.empty())
			cur = min(cur, both.top());

		ans.push_back(cur);
	}

	for (auto it: ans)
		cout << it << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto it: ranges::iota_view(0, t))
		solve_test(cin, cout);
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

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}