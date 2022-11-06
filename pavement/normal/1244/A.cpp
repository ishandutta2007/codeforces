#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, a, b, c, d, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int pen = a / c + (a % c != 0), pencil = b / d + (b % d != 0);
		if (pen + pencil > k) printf("-1\n");
		else printf("%d %d\n", pen, pencil);
	}
}