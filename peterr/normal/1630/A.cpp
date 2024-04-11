#include <bits/stdc++.h>
 
using namespace std;

int inv(int x, int bits)
{
	int ans = 0;
	for (int i = 0; i < bits; i++)
	{
		if (!(x & (1 << i)))
			ans = ans | (1 << i);
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
		int n, k;
		cin >> n >> k;
		int bits = __builtin_ctz(n);
		if (k == n - 1 && n == 4)
			cout << "-1\n";
		else if (k == n - 1)
		{
			set<int> s;
			cout << n - 1 << " " << n - 2 << "\n";
			cout << 0 << " " << 1 << "\n";
			cout << 3 << " " << n - 3 << "\n";
			cout << 2 << " " << n - 4 << "\n";
			s.insert(n - 1);
			s.insert(n - 2);
			s.insert(0);
			s.insert(1);
			s.insert(2);
			s.insert(3);
			s.insert(n - 3);
			s.insert(n - 4);
			for (int i = 0; i < n; i++)
			{
				if (s.count(i))
					continue;
				s.insert(i);
				s.insert(inv(i, bits));
				cout << i << " " << inv(i, bits) << "\n";
			}		
		}
		else if (k == 0)
		{
			set<int> s;
			for (int i = 0; i < n; i++)
			{
				if (s.count(i))
					continue;
				s.insert(i);
				s.insert(inv(i, bits));
				cout << i << " " << inv(i, bits) << "\n";
			}
		}
		else
		{
			set<int> s;
			cout << 0 << " " << inv(k, bits) << "\n";
			cout << k << " " << n - 1 << "\n";
			s.insert(0);
			s.insert(k);
			s.insert(n - 1);
			s.insert(inv(k, bits));
			for (int i = 1; i < n; i++)
			{
				if (s.count(i))
					continue;
				s.insert(i);
				s.insert(inv(i, bits));
				cout << i << " " << inv(i, bits) << "\n";
			}
		}
	}
	return 0;
}