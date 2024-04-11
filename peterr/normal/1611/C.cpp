#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		if (a[0] != n && a[n - 1] != n)
		{
			cout << "-1\n";
		}
		else
		{
			reverse(a, a + n);
			for (int i = 0; i < n; i++)
				cout << a[i] << " \n"[i == n - 1];
		}
	}
	return 0;
}