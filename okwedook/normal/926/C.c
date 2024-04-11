#include <stdio.h>
#define ll long long

int a[100001], summ[100001];

ll getsum(ll l, ll r) {
	return summ[r] - summ[l - 1];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	summ[0] = 0;
	for (int i = 1; i <= n; ++i)
		summ[i] = summ[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) 
		if (n % i == 0) {
			ll firstsum = getsum(1, i), secsum = 0;
			if (i == n && firstsum == 0) {
				puts("YES");
				return 0;
			}
			if (i != n) secsum = getsum(i + 1, 2 * i);
			int flag = 0;
			if (!(firstsum == i && secsum == 0 || firstsum == 0 && secsum == i)) continue;
			for (int j = i; j <= n; j += 2 * i) 
				if (getsum(j - i + 1, j) != firstsum) flag = 1;
			for (int j = 2 * i; j <= n; j += 2 * i)
				if (getsum(j - i + 1, j) != secsum) flag = 1;
			if (flag) continue;
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}