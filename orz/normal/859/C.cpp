#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define ld long double

using namespace std;
int main()
{
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n), df(n + 1), dg(n + 1);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	df[n] = 0;
	dg[n] = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		df[i] = v[i] + dg[i + 1];
		dg[i] = df[i + 1];
		if (df[i] < dg[i])
			swap(df[i], dg[i]);
	}
	cout << dg[0] << ' ' << df[0] << '\n';
	return 0;
}