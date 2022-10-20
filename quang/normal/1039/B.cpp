#include <bits/stdc++.h>

using namespace std;

int ask(long long l, long long r) {
	printf("%lld %lld\n", l, r);
	fflush(stdout);
	char u[10];
	memset(u, 0, sizeof u);
	scanf("%s", u);
	if (u[0] == 'Y') {
		return 1;
	} else if (u[0] == 'N') {
		return 0;
	} else {
		return -1;
	}
}

long long n;
int k;

int main() {
	srand(time(0));
	scanf("%lld %d", &n, &k);
	long long low = 1, high = n;
	while (1) {
		if (high - low + 1 < 60ll) {
			long long id = low + rand() % (high - low + 1);
			int ver = ask(id, id);
			if (ver == 1 || ver == -1) {
				return 0;
			} else {
				low = max(1ll, low - k);
				high = min(n, high + k);
			}
		} else {
			long long mid = (low + high) >> 1ll;
			int ver = ask(low, mid);
			if (ver == -1) {
				return 0;
			}
			if (ver == 0) {
				low = max(1ll, mid + 1 - k);
				high = min(n, high + k);
			} else {
				low = max(1ll, low - k);
				high = min(n, mid + k);
			}
		}
	}
	return 0;
}