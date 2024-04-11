#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int krabs(int a)
{
	if (a > 0)
		return a;
	return -a;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	sort(a.begin(), a.end());
	int t = 0;
	if (n == 1)
		cout << a[0];
	else if (a[a.size() - 1] >= 0)
	{
		if (a[0] <= 0)
			for (int i = 0; i < n; ++i)
				t += krabs(a[i]);
		else {
			for (int i = 0; i < n; ++i)
				t += krabs(a[i]);
			t -= (2 * krabs(a[0]));
		}
		cout << t;
	}
	else {
		for (int i = 0; i < n; ++i)
			t += krabs(a[i]);
		t -= 2 * krabs(a[n - 1]);
		cout << t;
	}
}