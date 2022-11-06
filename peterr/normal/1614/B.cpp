#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
pair<int, int> a[MAXN];
int where[MAXN];

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
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a, a + n);
		int x = 1;
		long long ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			int ind = a[i].second;
			int many = a[i].first;
			where[ind] = x;
			ans += (long long) many * abs(x) * 2;
			x = -x;
			if (x > 0)
				x++;
		}
		cout << ans << "\n";
		cout << "0 ";
		for (int i = 0; i < n; i++)
		{
			cout << where[i] << " \n"[i == n - 1];
		}
	}
	return 0;
}