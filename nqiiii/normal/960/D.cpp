#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const Long mod = 1ll << 62;
int q;
Long delta[100];

int BeLong(Long p) {
	int ans = -1;
	while (p) {
		p /= 2; ++ans;
	}
	return ans;
}

int main() {
	scanf("%d", &q);
	while (q--) {
		int op;
		Long x, y;
		scanf("%d%lld", &op, &x);
		int p = BeLong(x);
		Long now = 1ll << p;
		if (op == 1) {
			scanf("%lld", &y); y = (y + mod) % mod;
			delta[p] = (delta[p] + y) % now;
		} else if (op == 2) {
			scanf("%lld", &y); y = (y + mod) % mod;
			for (int i = p; i <= 62; ++i) {
				delta[i] = (delta[i] + y) % (1ll << i);
				y = (y + y) % mod;
			}
		} else if (op == 3) {
			x = (x + delta[p]) % (1ll << p) + (1ll << p);
			Long ans = 0;
			for (int i = p; i >= 0; --i) {
				printf("%lld ", (x - delta[i]) % (1ll << i) + (1ll << i));
				x /= 2;
			}
			printf("\n");
		}
	}
}