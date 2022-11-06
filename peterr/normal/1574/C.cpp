#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
long long a[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<long long> b;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		b.insert(a[i]);
	}
	int m;
	cin >> m;
	while (m--)
	{
		long long x, y;
		cin >> x >> y;
		long long ans = 4E18;
		if (b.lower_bound(x) != b.end())
		{
			ans = min(ans, y - (sum - *b.lower_bound(x)));
		}
		auto it = b.lower_bound(x);
		if (it != b.begin())
		{
			it--;
			ans = min(ans, x - *it + max(y - (sum - *it), 0LL));
		}
		ans = max(ans, 0LL);
		cout << ans << "\n";
	}
	return 0;
}