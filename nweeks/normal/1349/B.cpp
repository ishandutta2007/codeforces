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
		cout << (solve() ? "yes" : "no") << '\n';
}

ll solve(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;

	bool at_least_one(false);
	for (int i(0); i < n; ++i)
		at_least_one = at_least_one or (arr[i] == k);
	if (!at_least_one)
		return 0;
	if (n == 1)
		return true;
	for (int i(0); i + 2 <= n; ++i)
		if (arr[i] >= k and arr[i+1] >= k)
			return true;
	for (int i(0); i +3 <= n; ++i)
		if ((arr[i] >= k) + (arr[i+1] >= k) + (arr[i+2] >= k) >= 2)
			return true;
	return false;
}