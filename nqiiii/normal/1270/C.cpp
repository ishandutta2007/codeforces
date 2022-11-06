#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
ll sum, xo;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		sum = xo = 0;
		for (int i = 1; i <= n; ++i) {
			int a; cin >> a;
			sum += a; xo ^= a;
		}
		printf("2\n");
		printf("%lld ", xo);
		sum += xo;
		printf("%lld\n", sum);
	}
}