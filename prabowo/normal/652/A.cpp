#include <bits/stdc++.h>
using namespace std;

int main () {
	int h1, h2;
	int a, b;
	
	scanf ("%d %d", &h1, &h2);
	scanf ("%d %d", &a, &b);
	
	if (a <= b && h1 + a * 8 < h2) return 0 * printf ("-1\n");
	
	int ans = 0;
	while (h1 + a * 8 < h2) {
		ans++;
		h1 += (a - b) * 12;
	}
	
	printf ("%d\n", ans);
	
	
	return 0;
}