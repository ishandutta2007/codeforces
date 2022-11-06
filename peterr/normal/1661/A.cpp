#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 25;
int a[MAXN];
int b[MAXN];

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
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			if (b[i] < a[i])
				swap(a[i], b[i]);
		}
		long long ans = 0;
		for (int i = 0; i < n - 1; i++)
		{
			ans += abs(a[i + 1] - a[i]);
			ans += abs(b[i + 1] - b[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}