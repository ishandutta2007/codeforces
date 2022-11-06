#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	if (n == 1 || n == 2)
		cout << "No\n";
	else
	{
		cout << "Yes\n";
		int a[n + 1] = {0};
		std::vector<int> v;
		int m = (n + 1) / 2;
		for (int i = 0; i <= 20; ++i)
			if (m & (1 << i)) {
				a[1 << i]++;
				v.pb(1 << i);
			}
		cout << v.size() << " ";
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << " ";
		cout << "\n";
		cout << n - v.size() << " ";
		for (int i = 1; i <= n; ++i)
			if (!a[i])
				cout << i << " ";
	}
}