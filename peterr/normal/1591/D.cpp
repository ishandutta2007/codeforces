#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 5E5;
int a[MAXN + 1];
int bit[MAXN + 1];

void add(int pos, int amt)
{
	while (pos <= MAXN)
	{
		bit[pos] += amt;
		pos += pos & -pos;
	}
}

int query(int pos)
{
	int ans = 0;
	while (pos)
	{
		ans += bit[pos];
		pos -= pos & -pos;
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		fill(bit, bit + n + 1, 0);
		set<int> nums;
		bool dup = false;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (nums.count(a[i]))
				dup = true;
			nums.insert(a[i]);
		}
		if (dup)
			cout << "YES\n";
		else
		{
			long long cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				cnt += (i - 1) - query(a[i]);
				add(a[i], 1);
			}
			if (cnt & 1)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
	return 0;
}