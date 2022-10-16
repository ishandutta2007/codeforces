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

	vector<int> pm(arr.size() + 1);
	pm.front() = numeric_limits<int>::min();

	for (int i = 1; i < pm.size(); i++)
		pm[i] = max(pm[i - 1], arr[i - 1]);

	int ans = 0;

	for (int i = 0; i < arr.size(); i++)
		ans = max(ans, pm[i + 1] - arr[i]);

	int x = 0;

	while ((1u << (unsigned) x) <= ans)
		x++;

	cout << x << endl;
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