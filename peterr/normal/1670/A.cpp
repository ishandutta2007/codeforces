#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E5;
int a[MAXN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int neg = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] < 0)
				neg++;
		}
		bool ans = true;
		for (int i = 0; i < neg - 1; i++)
		{
			if (abs(a[i]) < abs(a[i + 1]))
				ans = false;
		}
		for (int i = neg; i < n - 1; i++)
		{
			if (abs(a[i]) > abs(a[i + 1]))
				ans = false;
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}