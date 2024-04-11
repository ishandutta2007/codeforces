#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];

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
		string s;
		cin >> s;
		vector<int> red;
		vector<int> blue;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'R')
				red.push_back(a[i]);
			else
				blue.push_back(a[i]);
		}
		sort(red.rbegin(), red.rend());
		sort(blue.begin(), blue.end());
		bool ans = true;
		for (int i = 0; i < (int) blue.size(); i++)
		{
			if (blue[i] < i + 1)
				ans = false;
		}
		for (int i = 0; i < (int) red.size(); i++)
		{
			if (red[i] > n - i)
				ans = false;
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
}