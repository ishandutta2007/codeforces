#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
	int n, k;
	cin >> n >> k;
	vector < int > a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	int ans = b[0] / a[0];
	for (int i = 1; i < n; i++) ans = min(ans, b[i] / a[i]);
	for (int i = 0; i < n; i++) b[i] -= a[i] * ans;

	while (k >= 0)
	{
		ans++;
		for (int i = 0; i < n; i++)
		{
			if (b[i] < a[i])
			{
				k -= (a[i] - b[i]);
				b[i] = 0;
			}
			else b[i] -= a[i];
		}
	}
	cout << ans - 1;
	return 0;
}