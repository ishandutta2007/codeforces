#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4E6;
int dp[MAXN + 1];
int where[MAXN + 1];
int sieve[MAXN + 1];
vector<int> primes;

void add(int &x, int y, int mod)
{
	 x += y;
	 if (x >= mod)
		x -= mod;
	assert(x >= 0 && x < mod);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i <= MAXN; i++)
	{
		if (!sieve[i])
		{
			sieve[i] = i;
			primes.push_back(i);
		}
		for (int j = 0; j < (int) primes.size(); j++)
		{
			if (primes[j] > sieve[i] || primes[j] * i > MAXN)
				break;
			sieve[primes[j] * i] = primes[j];
		}
	}
	int n, m;
	cin >> n >> m;
	dp[1] = 1;
	int pref = 1;
	int sum = 0;
	for (int i = 2; i <= n; i++)
	{
		//if (i % 1000 == 0)
			//cout << "iter " << i << endl;
		//cout << "pref " << pref << endl;
		dp[i] = pref;
		//for (int j = 2, la; j <= i; j = la + 1) {
			//la = min(i, i / (i / j));
			////n / x yields the same value for i <= x <= la.
			//int len = la - j + 1;
			//int other = i / j;
			////cout << "found " << other << " " << len << endl;
			//add(dp[i], (int) ((long long) dp[other] * len % m), m);
			//if (la == i)
				//break;
		//}
		int j = i;
		vector<int> div;
		div.push_back(1);
		while (j > 1)
		{
			int p = sieve[j];
			int cnt = 0;
			while (j % p == 0)
			{
				cnt++;
				j /= p;
			}
			for (int k = (int) div.size() - 1; k >= 0; k--)
			{
				int cur = div[k];
				for (int z = 0; z < cnt; z++)
				{
					cur *= p;
					div.push_back(cur);
				}
			}
		}
		//cout << "div of " << i << endl;
		//for (int d : div)
			//cout << d << " ";
		//cout << endl;
		for (int p : div)
		{
			if (p == 1 || p == i)
				continue;
			add(sum, m - dp[where[p]], m);
			where[p]++;	
			add(sum, dp[where[p]], m);
		}
		add(sum, 1, m);
		where[i] = 1;
		add(dp[i], sum, m);
		add(pref, dp[i], m);
		//cout << "dp " << i << " " << dp[i] << endl;
	}
	cout << dp[n] << "\n";
	return 0;
}