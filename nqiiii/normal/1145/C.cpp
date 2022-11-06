#include <bits/stdc++.h>
using namespace std;
int n, t;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 4; ++i) {
		t = (t << 1) | (n & 1); n >>= 1;
	}
	--t; n = 0;
	for (int i = 1; i <= 4; ++i) {
		n = (n << 1) | (t & 1); t >>= 1;
	}
	printf("%d", n);
}