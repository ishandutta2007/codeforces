#include <cstdio>

int f (long long x) {
	if (x < 4) return 0;
	if (x < 16) return 1;
	if (x < 82) return 2;
	if (x < 6724) return 0;
	if (x < 50626) return 3;
	if (x < 2562991876LL) return 1;
	return 2;
}

int main () {
	int n;
	scanf ("%d", &n);
	
	int ans = 0;
	long long a;
	for (int i=0; i<n; i++) {
		scanf ("%I64d", &a);
		ans ^= f(a);
	}
	
	if (ans) printf ("Furlo\n");
	else printf ("Rublo\n");
	return 0;
}