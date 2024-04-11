#include <bits/stdc++.h>
using namespace std;

int W, H;

int main() {
	scanf("%d%d", &W, &H);
	int ans = 1;
	for (int i = 0; i < W+H; i++) {
		ans *= 2;
		ans %= 998244353;
	}
	printf("%d\n", ans);
}