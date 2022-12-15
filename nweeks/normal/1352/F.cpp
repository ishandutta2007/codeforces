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
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	if (arr[1] + arr[2] == 0)
	{
		for (int i(0); i <= arr[0]; ++i)
			cout << 0;
		cout << '\n';
		return 0;
	}
	if (arr[0] + arr[1] == 0)
	{
		for (int i(0); i <= arr[2]; ++i)
			cout << 1;
		cout << '\n';
		return 0;
	}
	for (int i(0); i <= arr[2]; ++i)
		cout << 1;
	for (int i(0); i < (arr[1]-1)/2; ++i)
		cout << "01";
	for (int i(0); i <= arr[0]; ++i)
		cout << "0";
	if (arr[1]%2==0)
		cout << 1;
	cout << '\n';
	return 0;
}