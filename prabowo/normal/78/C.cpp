#include <cstdio>

int main () {
	int n, m, k;
	scanf ("%d %d %d", &n, &m, &k);
	
	if (n & 1) {
		if (k == 1 && m > 1) return 0 * printf ("Timur\n");
		
		for (int i=2; i*i<=m; i++) 
			if (m % i == 0 && m / i >= k)
				return 0 * printf ("Timur\n");
				
	}
				
	printf ("Marsel\n");
	return 0;
}