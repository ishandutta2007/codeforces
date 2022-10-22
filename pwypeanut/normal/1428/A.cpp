#include <bits/stdc++.h>
using namespace std;

int TC;

int main() {
	scanf("%d", &TC);
	while (TC--) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 == x2 || y1 == y2) printf("%d\n", abs(x1 - x2) + abs(y1 - y2));
		else printf("%d\n", abs(x1 - x2) + abs(y1 - y2) + 2);
	}
}