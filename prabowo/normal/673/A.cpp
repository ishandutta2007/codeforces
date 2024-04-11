#include <cstdio>

int main () {
	int n;
	scanf ("%d", &n);
	
	int t, prev = 0;
	for (int i=0; i<n; i++) {
		scanf ("%d", &t);
		if (t - prev > 15) return 0 * printf ("%d\n", prev + 15);
		prev = t;
	}
	
	if (90 - prev > 15) return 0 * printf ("%d\n", prev + 15);
	
	return 0 * printf ("90\n");;
}