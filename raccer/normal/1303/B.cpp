#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		long long n, a, b; cin >> n >> a >> b;
		long long l = n, r = 2000000000000000000;
		while (l < r) {
			long long mid = l + r >> 1;
			long long tmp = mid / (a + b) * a;
			if (mid % (a + b)) tmp += min(a, mid % (a + b));
			if (tmp >= (n + 1 >> 1)) r = mid;
			else l = mid + 1;
		}
		printf("%I64d\n", l);
	}
	return 0;
}