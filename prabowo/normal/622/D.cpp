#include <cstdio>

int a[1000000];

int main () {
	int n;
	scanf ("%d", &n);
	
	for (int i=0; i<n-1; i++) {
		if (i & 1) {
			a[n + (i >> 1)] = i + 1;
			a[n + (i >> 1) + (n - i - 1)] = i + 1;
		} else {
			a[i >> 1] = i + 1;
			a[(i >> 1) + (n - i - 1)] = i + 1;
		}
	}
	
	for (int i=0; i<n<<1; i++) {
		if (a[i]) printf ("%d ", a[i]);
		else printf ("%d ", n);
	}
	
	return 0;
}