#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr;

	while (n > 0)
	{
		arr.push_back(n % 10);
		n /= 10;
	}

	int ans = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		while (arr.back() == 0)
			arr.pop_back();

		int prod = 1;

		for (auto it : arr)
			prod *= it;

		ans = max(ans, prod);

		while (i + 1 < arr.size())
		{
			arr[i] = 9;
			if (arr[i + 1]-- == 0)
				i++;
			else
				break;
		}
	}

	cout << ans << endl;
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