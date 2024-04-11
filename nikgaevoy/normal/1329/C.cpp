#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


bool del(vector<int> &arr, int v, int g, int d)
{
	if (arr[v] == 0)
		return d > g;

	auto ch = arr[2 * v] > arr[2 * v + 1] ? 2 * v : 2 * v + 1;
	auto tmp = arr[v];
	arr[v] = arr[ch];

	if (!del(arr, ch, g, d + 1))
	{
		arr[v] = tmp;

		return false;
	}

	return true;
}


void slv(vector<int> &arr, vector<int> &ans, int v, int g, int d)
{
	while (arr[v] != 0 && del(arr, v, g, d))
		ans.push_back(v);

	if (arr[v] != 0)
	{
		slv(arr, ans, 2 * v, g, d + 1);
		slv(arr, ans, 2 * v + 1, g, d + 1);
	}
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	unsigned h, g;

	cin >> h >> g;

	vector<int> arr(1u << h), ans;

	for (int i = 1; i < arr.size(); i++)
		cin >> arr[i];

	arr.resize(2 * arr.size());

	slv(arr, ans, 1, g, 0);

	assert(ans.size() == (1u << h) - (1u << g));

	cout << accumulate(arr.begin(), arr.end(), 0ll) << '\n';
	for (auto it : ans)
		cout << it << ' ';
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

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}