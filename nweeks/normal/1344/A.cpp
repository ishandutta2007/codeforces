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
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;
	vector<bool>  seen(n);
	for (int i(0); i < n; ++i)
	{
		int room = (i + arr[i])%n;
		if (room < 0) room += n;
		seen[room] = true;
	}
	for (int i(0); i < n; ++i)
		if (!seen[i])
		{
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n";

	return 0;
}