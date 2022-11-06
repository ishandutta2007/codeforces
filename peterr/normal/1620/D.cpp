#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 100;
int a[MAXN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		bool has1 = false;
		bool has2 = false;
		bool hasOdd = false;
		bool costOne = false;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] & 1)
				hasOdd = true;
			if (a[i] % 3 == 1)
				has1 = true;
			if (a[i] % 3 == 2)
				has2 = true;
			if (a[i] == 1)
				costOne = true;
		}
		sort(a, a + n);
		int ans = a[n - 1];
		if (!hasOdd)
			ans = min(ans, a[n - 1] / 2);
		else
			ans = min(ans, a[n - 1] / 2 + 1);
		// all 3
		if (!has1 && !has2)
			ans = min(ans, a[n - 1] / 3);
		// many 3, one 1
		if (!has2)
			ans = min(ans, a[n - 1] / 3 + 1);
		// many 3, two 1
		ans = min(ans, a[n - 1] / 3 + 2);
		// many 3, one 2
		if (!has1)
			ans = min(ans, a[n - 1] / 3 + 1);
		// many 3, two 2
		if (!costOne)
		{
			vector<int> vec;
			for (int i = 0; i < n; i++)
			{
				if (a[i] % 3 == 1)
					vec.push_back(a[i] - 4);
				else if (a[i] % 3 == 2)
					vec.push_back(a[i] - 2);
				else
					vec.push_back(a[i]);
			}
			sort(vec.begin(), vec.end());
			ans = min(ans, vec.back() / 3 + 2);
		}
		// many 3, one 2, one 1
		{
			vector<int> vec;
			for (int i = 0; i < n; i++)
			{
				if (a[i] % 3 == 1)
					vec.push_back(a[i] - 1);
				else if (a[i] % 3 == 2)
					vec.push_back(a[i] - 2);
				else
					vec.push_back(a[i] - 3);
			}
			sort(vec.begin(), vec.end());
			ans = min(ans, vec.back() / 3 + 2);
		}
		// many 3, two 2, one 1
		{
			vector<int> vec;
			for (int i = 0; i < n; i++)
			{
				if (a[i] % 3 == 1)
					vec.push_back(a[i] - 4);
				else if (a[i] % 3 == 2)
					vec.push_back(a[i] - 5);
				else
					vec.push_back(a[i] - 3);
			}
			sort(vec.begin(), vec.end());
			vec.back() = max(vec.back(), 0);
			ans = min(ans, vec.back() / 3 + 3);
		}
		// many 3, one 2, two 1
		{
			vector<int> vec;
			for (int i = 0; i < n; i++)
			{
				if (a[i] % 3 == 1)
					vec.push_back(a[i] - 4);
				else if (a[i] % 3 == 2)
					vec.push_back(a[i] - 2);
				else
					vec.push_back(a[i] - 3);
			}
			sort(vec.begin(), vec.end());
			vec.back() = max(vec.back(), 0);
			ans = min(ans, vec.back() / 3 + 3);
		}
		// many 3, two 2, two 1
		{
			vector<int> vec;
			for (int i = 0; i < n; i++)
			{
				if (a[i] % 3 == 1)
					vec.push_back(a[i] - 4);
				else if (a[i] % 3 == 2)
					vec.push_back(a[i] - 5);
				else
					vec.push_back(a[i] - 6);
			}
			sort(vec.begin(), vec.end());
			vec.back() = max(vec.back(), 0);
			ans = min(ans, vec.back() / 3 + 4);
		}
		cout << ans << "\n";
	}
	return 0;
}