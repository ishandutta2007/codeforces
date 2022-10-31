#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

inline int add(int a, int b) { return (a + b >= MOD) ? (a + b - MOD) : (a + b); }
inline int sub(int a, int b) { return (a >= b) ? (a - b) : (a - b + MOD); }
inline int mul(int a, int b) { return (long long)a * b % MOD; }

int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; ++i)
		if (a[i])
		{
			long long bits = 1;
			for (; !(a[i] & bits); bits <<= 1);
			for (int j = 0 ; j < n; ++j)
				if (i != j && (a[j] & bits) > 0)
					a[j] ^= a[i];
		}
	int dup = 1;
	vector<long long> b;
	for (int i = 0; i < n ;++i)
		if (a[i])
			b.push_back(a[i]);
		else
			dup = mul(dup, 2);
	a = b;
	n = a.size();
	vector<int> results(m + 1);
	if (n <= m / 2 + 1)
	{
		for (int mask = 0; mask < (1 << n); ++mask)
		{
			long long val = 0;
			for (int i = 0; i < n; ++i)
				if ((mask >> i) & 1)
					val ^= a[i];
			int cnt = 0;
			for (int i = 0; i < m; ++i)
				cnt += ((val >> i) & 1);
			++results[cnt];
		}
	}
	else
	{
		set<long long> isolated;
		for (int i = 0; i < m; ++i)
			isolated.insert(1LL << i);
		for (int i = 0; i < n; ++i)
		{
			long long bits = 1;
			for (; !(a[i] & bits); bits <<= 1);
			isolated.erase(bits);
		}
		vector<long long> selected(isolated.begin(), isolated.end());
		int l = selected.size();
		vector<vector<int>> f(n + 1, vector<int>(1 << l));
		f[0][0] = 1;
		for (int i = 0; i < n; ++i)
		{
			int mask = 0;
			for (int j = 0; j < l; ++j)
				if (selected[j] & a[i])
					mask ^= (1 << j);
			for (int count = n; count >= 0; --count)
				for (int subset = 0; subset < (1 << l); ++subset)
					if (f[count][subset])
						f[count + 1][subset ^ mask] = add(f[count + 1][subset ^ mask], f[count][subset]);
		}
		for (int count = n; count >= 0; --count)
			for (int subset = 0; subset < (1 << l); ++subset)
				if (f[count][subset])
				{
					int actual_count = count;
					for (int i = 0; i < l; ++i)
						actual_count += ((subset >> i) & 1);
					results[actual_count] = add(results[actual_count], f[count][subset]);
				}
	}
	for (int i = 0; i < m + 1; ++i)
		cout << mul(dup, results[i]) << " ";
	cout << endl;
	return 0;
}