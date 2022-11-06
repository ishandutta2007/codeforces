#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E6;
int a[MAXN];

long long best(int ind, int g, bool parity, int n)
{
	vector<int> vec;
	long long ans = 0;
	for (int i = ind; i < n; i += g)
	{
		vec.push_back(a[i]);
		ans += a[i];
	}
	sort(vec.begin(), vec.end());
	int ptr = 0;
	if (parity)
	{
		ptr = 1;
		ans -= 2 * vec[0];
	}
	while (ptr + 1 < (int) vec.size())
	{
		if (vec[ptr] + vec[ptr + 1] < 0)
		{
			ans -= 2 * vec[ptr];
			ans -= 2 * vec[ptr + 1];
			ptr += 2;
		}
		else
			break;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int g;
		cin >> g;
		for (int i = 0; i < m - 1; i++)
		{
			int x;
			cin >> x;
			g = __gcd(g, x);
		}
		long long ans0 = 0;
		long long ans1 = 0;
		for (int i = 0; i < g; i++)
		{
			ans0 += best(i, g, false, n);
			ans1 += best(i, g, true, n);
		}
		cout << max(ans0, ans1) << "\n";
	}
	return 0;
}