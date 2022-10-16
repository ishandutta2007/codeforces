#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int sum = accumulate(a.begin(), a.end(), 0);

	if (sum % k != 0)
		cout << "No" << endl;
	else
	{
		vector<int> ans;
		int ptr = 0;
		const int part = sum / k;

		for (int i = 0; i < k; i++)
		{
			int cur = 0;
			const int start = ptr;
			while (ptr < n && cur + a[ptr] <= part)
			{
				cur += a[ptr];
				ptr++;
			}

			if (cur != part)
			{
				cout << "No" << endl;
				return;
			}

			ans.push_back(ptr - start);
		}

		assert(ptr == n);

		cout << "Yes" << endl;
		assert((int)ans.size() == k);
		for (int i = 0; i < k; i++)
			cout << ans[i] << " \n"[i + 1 == k];
	}
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