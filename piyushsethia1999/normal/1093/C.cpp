#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<int> b(n / 2); for (int o = 0; o < n / 2; o++) { cin >> b[o]; }
	std::vector<int> a(n);
	a[n / 2] = (b[n / 2 - 1] + 1) / 2;
	a[n / 2 - 1] = (b[n / 2 - 1]) / 2;
	for (int o = 1; o < n / 2; ++o)
	{
		int i = n / 2 - (o + 1);
		int j = n / 2 + (o);
		if ((b[i] - a[i + 1]) >= a[j - 1])
		{
			a[i] = a[i + 1];
			a[j] = b[i] - a[i + 1];
		}
		else
		{
			a[i] = b[i] - a[j - 1];
			a[j] = a[j - 1];
		}
	}
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
}