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
	vector<int> possible;
	for (int i(1); i*i <= n; ++i)
		if (n%i==0)
		{
			possible.push_back(i);
			if (n/i != i)
				possible.push_back(n/i);
		}
	sort(possible.begin(), possible.end());
	while (possible.back() > k)
		possible.pop_back();
	cout<< n / possible.back() << '\n';

	return 0;
}