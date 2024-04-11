#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, q;

	cin >> n >> q;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	int sum = accumulate(arr.begin(), arr.end(), 0);

	for (int i = 0; i < q; i++)
	{
		int t, k;

		cin >> t >> k;
		k--;

		if (t == 1)
		{
			sum -= arr[k];
			arr[k] = 1 - arr[k];
			sum += arr[k];
		}
		else
		{
			cout << (sum > k ? 1 : 0) << '\n';
		}
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

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int)str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}