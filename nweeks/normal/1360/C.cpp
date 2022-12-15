#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		solve();
}

ll solve(void)
{
	int n;
	cin >> n;
	bool can[2] = {true, true};
	vector<int> arr(n);
	for (auto &v : arr)
	{
		cin >> v;
		can[v%2] ^= 1;
	}
	sort(arr.begin(), arr.end());

	if (!can[0])
	{
		for (int i(0); i+1 < n; ++i)
			if (arr[i+1] == arr[i] + 1)
			{
				cout << "YES\n";
				return 0;
			}
		cout << "NO\n";
	}
	else
		cout << "YES\n";
	return 0;
}