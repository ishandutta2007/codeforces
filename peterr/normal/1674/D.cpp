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
		for (int i = n - 1; i >= 1; i -= 2)
		{
			if (a[i] < a[i - 1])
				swap(a[i], a[i - 1]);
		}
		bool ans = true;
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
				ans = false;
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}