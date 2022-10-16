#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	vector<set<int>> wh(n + 1);

	for (int i = 0; i < arr.size(); i++)
		if (arr[i] < wh.size())
			wh[arr[i]].insert(i);

	set<int> mex;

	for (int i = 0; i < n + 1; i++)
		if (wh[i].empty())
			mex.insert(i);

	vector<int> ans;

	auto make_move = [&](int x)
	{
		ans.push_back(x);
		int val = *mex.begin();

		if (arr[x] < wh.size())
		{
			wh[arr[x]].erase(x);

			if (wh[arr[x]].empty())
				mex.insert(arr[x]);
		}

		assert(wh[val].empty());

		arr[x] = val;
		wh[val].insert(x);
		mex.erase(val);
	};

	int q = 0;
	while (q < arr.size())
	{
		while (*mex.begin() < arr.size())
			make_move(*mex.begin());

		while (q < arr.size() && arr[q] == q)
			q++;

		if (q < arr.size())
			make_move(q);
	}

	assert(is_sorted(arr.begin(), arr.end()));
	assert(ans.size() <= 2 * n);

	cout << ans.size() << '\n';

	for (auto it : ans)
		cout << it + 1 << ' ';
	cout << '\n';
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