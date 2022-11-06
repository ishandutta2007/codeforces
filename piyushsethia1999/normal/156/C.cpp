#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mp make_pair

using namespace std;
std::vector<std::vector<int> > c(3000, std::vector<int>(200, 0));
int mod = 1e9 + 7;

void preprocess(int n, int m)
{
	for (int i = 0; i < n; ++i)
		c[i][0] = 1;
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j) {
			c[i][j] = c[i-1][j] + c[i-1][j-1];
			if(c[i][j] > mod)
				c[i][j] -= mod;
		}
}
int C(int a, int b)
{
	return c[a][b];
}
int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int t; cin >> t;
	preprocess(3000, 200);
	while(t--)
	{
		string S;
		cin >> S;
		int n = 0;
		int s = S.size();
		for (int i = 0; i < s; ++i)
			n += (S[i] - 'a' + 1);
		int res = -1;
		for (int i = 0; i < s; ++i)
		{
			if(26 * i <= (n - s) && (i & 1))
				res = (res - C(s, i) * C(n - 1 - 26 * i, s - 1)) % mod;
			else if(26 * i <= (n - s))
				res = (res + C(s, i) * C(n - 1 - 26 * i, s - 1)) % mod;
		}
		cout << (res + mod) % mod << "\n";
	}
}