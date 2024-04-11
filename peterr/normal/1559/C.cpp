#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E4;
int a[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		if (*min_element(a + 1, a + n + 1) == 1 || a[1] == 1)
		{
			cout << n + 1 << " ";
			for (int i = 1; i <= n; i++)
			{
				cout << i << " ";
			}
			cout << "\n";
			continue;
		}
		if (*max_element(a + 1, a + n + 1) == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				cout << i << " ";
			}
			cout << n + 1 << "\n";
			continue;
		}
		int ind = 1;
		while (a[ind] == 0)
		{
			cout << ind << " ";
			ind++;
		}
		cout << n + 1 << " ";
		while (ind <= n)
		{
			cout << ind << " ";
			ind++;
		}
		cout << "\n";
	}
	return 0;
}