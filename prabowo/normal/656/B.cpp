#include <cstdio>
#include <cstring>

int gcd (int x, int y) {
	return y ? gcd (y, x % y) : x;
}

int main () {
	int n;
	scanf ("%d", &n);
	
	int m[n];
	int r[n];
	
	for (int i=0; i<n; i++) scanf ("%d", m + i);
	for (int i=0; i<n; i++) scanf ("%d", r + i);
	
	int lcm = 1;
	for (int i=0; i<n; i++) {
		lcm = lcm / gcd (lcm, m[i]) * m[i];
	}
	
	bool vis[lcm];
	memset (vis, 0, sizeof vis);
	
	for (int i=0; i<n; i++) {
		for (int j=r[i]; j<lcm; j+=m[i])
			vis[j] = 1;
	}
	
	int ans = 0;
	for (int i=0; i<lcm; i++) ans += vis[i];
	
	printf ("%.6lf\n", (double) ans / lcm);
	return 0;
}