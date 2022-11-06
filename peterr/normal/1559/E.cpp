#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 998244353;
const int MAXM = 1E5;
const int MAXN = 50;
const int MAXDIV = 128;
pair<int, int> a[MAXN + 1];
int dp[MAXM + 1];
int pref[MAXM + 1];
int sieve[MAXM + 1];
int mob[MAXM + 1];
vector<int> primes;

void add(int& x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int solve(int n, int m, int p)
{
	m = m / p;
	fill(dp, dp + m + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		pref[0] = dp[0];
		for (int j = 1; j <= m; j++)
		{
			pref[j] = pref[j - 1];
			add(pref[j], dp[j]);
		}
		int lo = (a[i].first + p - 1) / p;
		int hi = (a[i].second) / p;
		for (int j = m; j >= 0; j--)
		{
			dp[j] = 0;
			if (lo > hi)
				continue;
			int lb = max(0, j - hi);
			int ub = j - lo;
			if (ub < 0)
				continue;
			add(dp[j], pref[ub]);
			if (lb)
				add(dp[j], MOD - pref[lb - 1]);
		}
		//cout << "iter " << i << endl;
		//for (int j = 0; j <= m; j++)
		//{
			//cout << "sz " << j << " = " << dp[j] << endl;
		//}
	}
	int ans = 0;
	for (int i = 0; i <= m; i++)
	{
		add(ans, dp[i]);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mob[1] = 1;
	for (int i = 2; i <= MAXM; i++)
	{
		if (!sieve[i])
		{
			sieve[i] = i;
			mob[i] = -1;
			primes.push_back(i);
		}
		for (int j = 0; j < (int) primes.size(); j++)
		{
			if (primes[j] > sieve[i] || primes[j] * i > MAXM)
				break;
			sieve[primes[j] * i] = primes[j];
			if (primes[j] == sieve[i])
				mob[primes[j] * i] = 0;
			else
				mob[primes[j] * i] = -mob[i];
		}
	}
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	int ans = 0;
	for (int i = 1; i <= MAXM; i++)
	{
		if (!mob[i])
			continue;
		int x = solve(n, m, i);
		if (mob[i] == -1)
			x = MOD - x;
		add(ans, x); 
	}
	cout << ans << "\n";
	return 0;
}