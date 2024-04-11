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
		if (n == 1)
		{
			if (a[0] == 1)
				cout << "YES\n";
			else
				cout << "NO\n";
			continue;
		}
		sort(a, a + n);
		if (a[n - 1] - a[n - 2] > 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}