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
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;
	set<int> numb(arr.begin(), arr.end());
	if (SZ(numb) > k)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i(1); i <= n; ++i)
		if (SZ(numb) < k)
			numb.insert(i);
	cout << n * k << '\n';
	for (int i(0); i < n; ++i)
	{
		for (auto v : numb)
			cout << v << ' ';
	}
	cout << '\n';
	return 0;
}