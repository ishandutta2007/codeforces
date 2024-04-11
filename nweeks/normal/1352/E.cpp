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

const int MAXN = 8001;
array<int, MAXN> nb_egaux;
array<bool, MAXN> special;

ll solve(void)
{
	for (int i(0); i < MAXN; ++i)
		nb_egaux[i] = special[i] = 0;
	int n;
	cin >> n;
	vector<int> arr(n+1);
	for (int i(0); i < n; ++i)
	{
		cin >> arr[i+1];
		nb_egaux[arr[i+1]]++;
	}
	for (int i(0); i < n; ++i)
		arr[i+1] += arr[i];
	for (int r(2); r <= n; ++r)
		for (int l(1); l < r; ++l)
			if (arr[r] - arr[l-1] <= n)
			special[arr[r] - arr[l-1]]= true;
	int ans(0);
	for (int i(0); i < MAXN; ++i)
		if (special[i])
			ans += nb_egaux[i];
	cout << ans << '\n';
	return 0;
}