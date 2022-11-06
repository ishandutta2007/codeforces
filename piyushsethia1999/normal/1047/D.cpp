#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	int ar = n * m;
	if (n > m)
		swap(n, m);
	int re = 0;
	if (n == 1)
	{
		m %= 6;
		if (m > 3)
			m = 6 - m;
		re = m;
	}
	else if (n == 2)
	{
		if (m == 2)
			re = 4;
		else if (m == 3)
			re = 2;
		else if (m == 7)
			re = 2; 
		else
			re = 0;
	}
	else if ((m * n) & 1)
	{
		re = 1;
	}
	else
		re = 0;
	cout << (ar - re);
}