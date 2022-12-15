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
	int n, x;
	cin >> n >> x;
	int degX = 0;
	for (int i(1); i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		degX += u==x or v==x;
	}

	if (degX <= 1)
	{
		cout << "Ayush\n";
		return 0;
	}
	if ((n-1)%2 == 0)
		cout << "Ashish\n";
	else
		cout << "Ayush\n";
	return 0;
}