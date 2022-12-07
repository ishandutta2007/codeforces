#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long k[200010];
long long sum[200010];
int main() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	for(int i = 1; i <= q; i++) scanf("%lld", k + i);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	long long run = 0;
	for(int i = 1; i <= q; i++) {
		run += k[i];
		int num = upper_bound(sum + 1, sum + n + 1, run) - sum;
		num = n + 1 - num;
		if(num == 0) run = 0, num = n;
		printf("%d\n", num);
	}
}