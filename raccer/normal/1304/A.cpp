#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		long long x, y, a, b; cin >> x >> y >> a >> b;
		if ((y - x) % (a + b) == 0) printf("%I64d\n", (y - x) / (a + b));
		else printf("-1\n");
	}
	return 0;
}