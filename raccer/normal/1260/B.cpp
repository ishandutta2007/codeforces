#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		long long a, b; cin >> a >> b;
		if (2 * b >= a && b <= 2 * a && (2 * a - b) % 3 == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}