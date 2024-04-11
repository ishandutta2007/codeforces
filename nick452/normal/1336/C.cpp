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
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	string s;
	string t;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	auto check = [&](int at, char val) {
		return at >= m || val == t[at];
	};
	reverse(s.begin(), s.end());
	vector<vector<int>> f(n + 1, vector<int>(n + 1));
	f[0][0] = 1;
	for (int current = 0; current < n; ++current)
		for (int n1 = 0; n1 <= current; ++n1)
		{
			int n2 = current - n1;
			if (f[n1][n2])
			{
				if (check(n1, s[current]))
					if (n1 == 0)
						f[n1 + 1][n2] = add(f[n1 + 1][n2], mul(f[n1][n2], min(n2 + 1, n - m + 1)));
					else
						f[n1 + 1][n2] = add(f[n1 + 1][n2], f[n1][n2]);
				if (check(n - 1 - n2, s[current]))
					f[n1][n2 + 1] = add(f[n1][n2 + 1], f[n1][n2]);
			}
		}
	int ret = 0;
	for (int n1 = 0; n1 <= n; ++n1)
		ret = add(ret, f[n1][n - n1]);
	printf("%d\n", ret);
	return 0;
}