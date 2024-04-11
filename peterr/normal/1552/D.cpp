#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
int a[MAXN];

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
		bool ans = false;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (!a[i])
				ans = true;
			a[i] = abs(a[i]);
		}
		sort(a, a + n);
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] == a[i + 1])
				ans = true;
		}
		vector<int> vec;
		for (int i = 0; i < n; i++)
		{
			for (int j = (int) vec.size() - 1; j >= 0; j--)
			{
				if (abs(vec[j]) == abs(a[i]))
					ans = true;
				vec.push_back(vec[j] + a[i]);
				vec.push_back(vec[j] - a[i]);
			}
			vec.push_back(a[i]);
			vec.push_back(-a[i]);
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}