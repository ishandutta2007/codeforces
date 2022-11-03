#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
int n, a[maxn], x, f;

long long ans = 0;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	scanf("%d%d", &x, &f);

	for (int i = 1; i <= n; ++i) {
		ans += a[i] / (x + f);
		a[i] %= x + f;
		if (a[i] > x) ++ans;
	}

    cout << ans * f <<endl;
	
	return 0;
}