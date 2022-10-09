/*
2021.10.09
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

bool solve()
{
	ll s, n, k;
	cin >> s >> n >> k;
	if (k > s) return 0;
	if (k == s) return 1;
	if ((s / n) > k) return 0;
	long long t = n / k;
	long long b1 = 2 * k * t + (n - k * t);
	if (s >= b1) return 0;
	if (n <= k && k < s - n + 1) return 0;
	return 1;
	// 1 1 1 1 1 1 1 1 (s - n + 1)
	
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		puts(solve() ? "YES" : "NO");
	}	
}