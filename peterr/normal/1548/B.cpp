#include <bits/stdc++.h>

using namespace std;

const long long LOGN = 20;
const long long MAXN = 2E5;
long long a[MAXN];
long long table[LOGN][MAXN];


long long query(long long l, long long r)
{
	long long len = r - l + 1;
	long long ind = 63 - __builtin_clzll(len);
	return __gcd(table[ind][l], table[ind][r - (1 << ind) + 1]);
	//cout << "querying " << l << " " << r << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		for (long long i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		//if (n == 1)
		//{
			//cout << "1\n";
			//continue;
		//}
		for (long long i = 0; i < n - 1; i++)
		{
			a[i] = abs(a[i + 1] - a[i]);
			table[0][i] = a[i];
		}
		for (long long i = 1; i < LOGN; i++)
		{
			for (long long j = 0; j < n - 1; j++)
			{
				long long otherInd = min(n - 2, j + (1 << (i - 1)));
				table[i][j] = __gcd(table[i - 1][j], table[i - 1][otherInd]);
			}
		}
		long long ans = 0;
		for (long long i = 0; i < n - 1; i++)
		{
			long long j = i - 1;
			for (long long jump = n; jump; jump >>= 1)
			{
				while (j + jump < n - 1 && query(i, j + jump) != 1)
					j += jump;
			}
			//cout << "foudn " << i << " " << j << endl;
			ans = max(ans, j - i + 1);
		}
		cout << ans + 1 << "\n";
	}
	return 0;
}