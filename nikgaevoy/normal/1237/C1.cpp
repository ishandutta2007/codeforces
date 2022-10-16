#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> arr(n, vector<int>(3));

	for (auto &row : arr)
	{
		for (auto &it : row)
			cin >> it;
	}

	vector<bool> used(n);

	int cur = 0;

	auto dist = [](const vector<int> &a, const vector<int> &b) {
		int sum = 0;

		for (int i = 0; i < a.size(); i++)
			sum += abs(a[i] - b[i]);

		return sum;
	};

	while (cur < n)
	{
		if (used[cur])
		{
			cur++;

			continue;
		}

		int sn = -1;

		for (int i = cur + 1; i < n; i++)
			if (!used[i] && (sn == -1 || dist(arr[cur], arr[i]) < dist(arr[cur], arr[sn])))
				sn = i;

		assert(sn != -1);

		cout << cur + 1 << ' ' << sn + 1 << endl;

		used[cur] = true;
		used[sn] = true;
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