#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 50;
int n, f[N][5][5], a[N];
long long target;
long double p;

int comb(int n, int k)
{
	if (k == 0) return 1;
	if (k == 1) return n;
	if (k == 2) return n * (n - 1) / 2;
	if (k == 3) return n * (n - 1) / 2 * (n - 2) / 3;
	throw;
}

bool check(int x)
{
	memset(f, 0, sizeof f);
	int f0 = comb(n - x, 3);
	int f1 = x * comb(n - x, 2);
	int f2 = (n - x) * comb(x, 2);
	int f3 = comb(x, 3);
	long long win = 0;
	//        22,33  23,32
	win += f1 * (1 + 2);
	//         33    13,23,31,32 11 22
	win += f2 * 6;
	win += f3 * 6;

	//printf("x = %d, f = %d %d %d %d, win = %lld\n", x, f0, f1, f2, f3, win);
	return win >= target;
}

int main()
{
	cin >> n >> p;
	long long w = p * 10000;
	target = (1ll * n * (n - 1) * (n - 2) * w + 9999) / 10000;
	f[0][0][0] = 1;
	int l = 0, r = n, ans = -1;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
}