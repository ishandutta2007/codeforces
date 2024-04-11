#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];

long long solve(const vector<int> &pos, const vector<int> &neg, int k)
{
	long long ans = 0;
	int ptr = (int) neg.size() - 1;
	while (ptr >= 0)
	{
		ans += 2 * neg[ptr];
		ptr -= k;
	}
	ptr = (int) pos.size() - 1;
	bool first = true;
	while (ptr >= 0)
	{
		if (first)
			ans += pos[ptr];
		else
			ans += 2 * pos[ptr];
		first = false;
		ptr -= k;
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> pos, neg;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (x > 0)
				pos.push_back(x);
			else if (x < 0)
				neg.push_back(-x);
		}
		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());
		cout << min(solve(pos, neg, k), solve(neg, pos, k)) << "\n";
	}
	return 0;
}