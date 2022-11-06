#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll t, x, y;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld", &x, &y);
		if (x >= y) {
			printf("YES\n");
			continue;
		}
		x -= x % 2 != 0;
		if (x <= 1) {
			if (x >= y) printf("YES\n");
			else printf("NO\n");
		} else if (x == 2) {
			if (y <= 3) printf("YES\n");
			else printf("NO\n");
		} else printf("YES\n");
	}
}