#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

long long a[N], h;

int n, T;

int check(long long p)
{
	long long ans = 0;
	for (int i = 1; i <= n; ++i) ans += min(p, a[i + 1] - a[i]);
	return ans >= h;
}

void Main()
{
	scanf("%d%lld", &n, &h);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]); a[n + 1] = 2e18;
	long long l = 0, r = 2e18, mid = 0;
	while (((l + r) >> 1) != mid) 
	{
		mid = (l + r) >> 1;
		if (check(mid)) r = mid; else l = mid;
	}
	cout << r << endl;
}

int main()
{
	scanf("%d", &T); 
	for (;T--;) Main();
}