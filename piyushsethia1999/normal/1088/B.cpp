#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	sort(a.begin(), a.end());
	int i = 0;
	int sum = 0;
	for (int j = 0; j < k; ++j)
	{
		while (i < n && (a[i] - sum) <= 0)
			i++;
		if (i < n) {
			cout << a[i] - sum << "\n";
			sum += (a[i] - sum);
		}
		else
		{
			cout << 0 << "\n";
		}
	}
}