#include <cstdio>

int main () {
	long long n;
	scanf ("%I64d", &n);
	
	int cnt = 1;
	while (cnt < n) n -= cnt++;
	
	printf ("%I64d\n", n);
	
	return 0;
}