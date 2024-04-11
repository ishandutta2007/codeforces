#include <cstdio>

int main () {
	int n, a, b;
	scanf ("%d %d %d", &n, &a, &b);
	
	if (a * b < n) return 0 * printf ("-1\n");
	
	int odd = 1;
	int even = 2;
	for (int i=0; i<a; i++) {
		for (int j=0; j<b; j++) {
			if (i + j & 1) {
				if (even <= n) {
					printf ("%d ", even);
					even += 2;
					continue;
				}
			} else {
				if (odd <= n) {
					printf ("%d ", odd);
					odd += 2;
					continue;
				}
			}
			
			printf ("0 ");
		}	
		printf ("\n");	
	}
	return 0;
}