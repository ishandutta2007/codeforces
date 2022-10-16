#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	int all = accumulate(arr.begin(), arr.end(), 0);

	int sum = arr[0];

	vector<int> ans = {0};

	for (int i = 1; i < arr.size(); i++)
		if (2 * arr[i] <= arr[0])
		{
			sum += arr[i];

			ans.push_back(i);
		}

	if (2 * sum <= all)
		cout << 0 << endl;
	else
	{
		cout << ans.size() << endl;

		for (auto it : ans)
			cout << it + 1 << ' ';
		cout << endl;
	}
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