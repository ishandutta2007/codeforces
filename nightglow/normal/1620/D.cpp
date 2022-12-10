#include <bits/stdc++.h>

#define N 50

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int dp[N + 1], n;

int a[105];

void Main()
{
	scanf("%d", &n); int ans = (int)1e9;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int one = 0; one < 3; ++one)
		for (int two = 0; two < 6; ++two)
		{
			int cnt = 0;
			memset(dp, 0, sizeof(dp));		
			for (int i = 0; i <= one; ++i)
				for (int j = 0; j <= two; ++j)
					dp[i + j * 2] = 1;
			for (int i = 1; i <= n; ++i)
			{
				int j;
				for (j = 50; j >= 0; --j)
					if (dp[j] && a[i] >= j && (a[i] - j) % 3 == 0)
					{
						cnt = max(cnt, (a[i] - j) / 3);
						break;
					}
				if (j < 0)
				{
					cnt = 1e9; break;
				}
			}
			ans = min(ans, one + two + cnt);
		}
	printf("%d\n", ans); 
}

int main()
{
	int T; scanf("%d", &T);
	for (;T--;) Main();
}