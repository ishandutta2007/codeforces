#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> arr(4);

	for (int i = 0; i < n; i++)
	{
		string str;
		int val;

		cin >> str >> val;

		int type = (str[0] - '0') * 2 + str[1] - '0';

		arr[type].push_back(val);
	}

	for (auto &row : arr)
		sort(row.begin(), row.end());

	int ans = 0;

	while (!arr[1].empty() && !arr[2].empty())
	{
		ans += arr[1].back() + arr[2].back();
		arr[1].pop_back();
		arr[2].pop_back();
	}

	while (!arr[3].empty())
	{
		ans += arr[3].back();
		arr[3].pop_back();

		int wh = -1, val = 0;

		for (int i = 0; i < 3; i++)
			if (!arr[i].empty() && arr[i].back() > val)
			{
				val = arr[i].back();
				wh = i;
			}

		ans += val;

		if (wh != -1)
			arr[wh].pop_back();
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