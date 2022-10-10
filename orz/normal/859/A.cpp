#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
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
	int k, m, n;
	cin >> k >> m;
	for (int i = 1; i < k; ++i)
	{
		cin >> n;
		if (n > m)
			m = n;
	}
	cout << max(0, m - 25);
	//system("pause");
	return 0;
}