#include <bits/stdc++.h>

using namespace std;

struct UnionFind
{
	vector<int> s;
	vector<int> p;
	
	UnionFind(int n)
	{
		s = vector<int>(n, 1);
		p = vector<int>(n);
		iota(p.begin(), p.end(), 0);
	}
	
	bool mge(int x, int y)
	{
		x = getRoot(x);
		y = getRoot(y);
		if (x == y)
			return false;
		if (s[x] > s[y])
			swap(x, y);
		p[x] = y;
		s[y] += s[x];
		return true;
	}
	
	bool same(int x, int y) { return getRoot(x) == getRoot(y); }
	
	int getRoot(int x)
	{
		if (p[x] != x)
			p[x] = getRoot(p[x]);
		return p[x];
	}
};

const int MAXN = 2000;
const int LOG = 30;
int a[MAXN];

bool check(int n)
{
	UnionFind UF(n + LOG);
	int mask = 0;
	for (int i = 0; i < n; i++)
	{
		mask = mask | a[i];
		for (int j = 0; j < LOG; j++)
		{
			if (a[i] & (1 << j))
				UF.mge(i, n + j);
		}
	}
	return UF.s[UF.getRoot(0)] == n + __builtin_popcount(mask);
}

int solve(int n)
{
	if (check(n))
		return 0;
	for (int i = 0; i < n; i++)
	{
		a[i]++;
		if (check(n))
			return 1;
		a[i] -= 2;
		if (check(n))
			return 1;
		a[i]++;
	}
	int most = 0;
	for (int i = 0; i < n; i++)
	{
		most = max(most, __builtin_ctz(a[i]));
	}
	int ptr = -1;
	while (1)
	{
		ptr++;
		if (__builtin_ctz(a[ptr]) == most)
		{
			a[ptr]--;
			break;
		}
	}
	while (1)
	{
		ptr++;
		if (__builtin_ctz(a[ptr]) == most)
		{
			a[ptr]++;
			break;
		}
	}
	return 2;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (!a[i])
			{
				a[i]++;
				ans++;
			}
		}
		ans += solve(n);
		cout << ans << "\n";
		for (int i = 0; i < n; i++)
			cout << a[i] << " \n"[i == n - 1];
	}
	return 0;
}