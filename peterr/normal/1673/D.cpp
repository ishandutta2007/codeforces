#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 1E9 + 7;

void add(long long &x, long long y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		long long b, q, y;
		cin >> b >> q >> y;
		long long c, r, z;
		cin >> c >> r >> z;
		long long cn = c + (z - 1) * r;
		long long bn = b + (y - 1) * q;
		if (c < b || cn > bn || (c - b) % q || r % q)
		{
			cout << "0\n";
			continue;
		}
		if (r == 1)
		{
			cout << "-1\n";
			continue;
		}
		long long ind1 = (c - b) / q;
		long long ind2 = (cn - b) / q;
		long long gap = (ind2 - ind1) / (z - 1);
		if (ind1 - gap < 0 || ind2 + gap >= y)
		{
			cout << "-1\n";
			continue;
		}
		long long ans = 0;
		for (long long i = 1; i * i <= r; i++)
		{
			if (!(r % i))
			{
				long long j = i;
				long long num = r / j;
				if (__gcd(num, gap) == 1)
				{
					num = num % MOD;
					add(ans, num * num % MOD);
				}
				if (r / i != i)
				{
					j = r / i;
					num = r / j;
					if (__gcd(num, gap) == 1)
					{
						num = num % MOD;
						add(ans, num * num % MOD);
					}
				}
			}
		}
		cout << ans << "\n";
		//cout << "cn " << cn << endl;
		//cout << "ind " << ind1 << endl;
		//cout << "ind " << ind2 << endl;
		//cout << "gap " << gap << endl;
	}
	return 0;
}