#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 23;
const int MOD = 998244353;
int a[MAXN][26];
int mn[1 << MAXN][26];
int ans[1 << MAXN];

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int flip(int mask, int n)
{
	return mask ^ ((1 << n) - 1);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (char ch : s)
		{
			a[i][ch - 'a']++;
		}
		for (int j = 0; j < 26; j++)
		{
			mn[1 << i][j] = a[i][j];
		}
	}
	for (int mask = 2; mask < (1 << n); mask++)
	{
		if (__builtin_popcount(mask) == 1)
			continue;
		for (int i = 0; i < 26; i++)
		{
			int sub = mask - (mask & -mask);
			mn[mask][i] = min(mn[sub][i], a[__builtin_ctz(mask)][i]);
			//cout << bitset<5>(mask) << " " << i << " " << mn[mask][i] << "\n";
		}
	}
	for (int mask = 0; mask < (1 << n) - 1; mask++)
	{
		ans[mask] = 1;
		for (int i = 0; i < 26; i++)
		{
			ans[mask] = (int) ((long long) ans[mask] * (mn[flip(mask, n)][i] + 1) % MOD);
		}
	}
	//for (int mask = 0; mask < (1 << n); mask++)
	//{
		//cout << bitset<5>(mask) << " " << ans[mask] << endl;
	//}
	for (int i = 0; i < n; i++)
	{
		for (int mask = 0; mask < (1 << n) - 1; mask++)
		{
			if (mask & (1 << i))
				add(ans[mask], MOD - ans[mask ^ (1 << i)]);
		}
	}
	for (int mask = 0; mask < (1 << n); mask++)
	{
		if (flip(mask, n) < mask)
			swap(ans[mask], ans[flip(mask, n)]);
	}
	//for (int mask = 0; mask < (1 << n); mask++)
	//{
		//cout << bitset<5>(mask) << " " << ans[mask] << endl;
	//}
	for (int i = 0; i < n; i++)
	{
		for (int mask = 0; mask < (1 << n); mask++)
		{
			if (mask & (1 << i))
				add(ans[mask], ans[mask ^ (1 << i)]);
		}
	}
	//for (int mask = 0; mask < (1 << n); mask++)
	//{
		//cout << bitset<5>(mask) << " " << ans[mask] << endl;
	//}
	int total = ans[(1 << n) - 1];
	for (int mask = 0; mask < (1 << n); mask++)
	{
		if (mask < flip(mask, n))
		{
			swap(ans[mask], ans[flip(mask, n)]);
			int j = mask;
			for (int k = 0; k < 2; k++)
			{
				ans[j] = MOD - ans[j];
				if (ans[j] == MOD)
					ans[j] = 0;
				add(ans[j], total);
				j = flip(j, n);
			}
		}
	}
	ans[0] = 1;
	long long res = 0;
	for (int mask = 1; mask < (1 << n); mask++)
	{
		int mult = 0;
		for (int i = 0; i < n; i++)
		{
			if (mask & (1 << i))
				mult += i + 1;
		}
		mult *= __builtin_popcount(mask);
		res = res ^ ((long long) ans[mask] * mult);
	}
	cout << res << "\n";
	return 0;
}