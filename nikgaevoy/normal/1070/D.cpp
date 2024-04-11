#include <bits/stdc++.h>

using namespace std;

using ll = long long;


ll foo (const vector<int> &arr, int k, int pos = 0, int carry = 0)
{
	map<pair<int, int>, ll> dp;

	if (pos == (int)arr.size ())
		return (carry + k - 1) / k;

	if (!dp.count ({pos, carry}))
	{
		if ((arr[pos] + carry) / k >= (carry + k - 1) / k)
			dp[{pos, carry}] = (arr[pos] + carry) / k + foo(arr, k, pos + 1, (arr[pos] + carry) % k);
		else
			dp[{pos, carry}] = (arr[pos] + carry + k - 1) / k + foo(arr, k, pos + 1, 0);
	}

	return dp[{pos, carry}];
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	vector<int> arr (n);

	for (auto &it : arr)
		cin >> it;

	cout << foo (arr, k) << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}