#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long li;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	li neg = ((n - 1) / 2) * li((n - 1) / 2 + 1);
	if (n % 2 == 0) neg += n / 2;
	li pos = n * li(n - 1) / 2;

	li ans = 0;
	forn(i, m){
		int x, d;
		scanf("%d%d", &x, &d);
		ans += x * li(n);
		if (d < 0)
			ans += neg * d;
		else
			ans += pos * d;
	}

	printf("%.15f\n", double(ans) / n);
	return 0;
}