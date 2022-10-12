#include <cstdio>
#include <cstring>

int main () {
	int n, p;
	scanf ("%d %d", &n, &p);
	getchar();
	
	long long ans = 0;
	char s[10];
	for (int i=0; i<n; i++) {
		gets (s);
		if (strlen(s) == 8) 
			ans += 1LL << i;
	}
	
	printf ("%I64d\n", ans * p - __builtin_popcountll(ans) * p / 2);
	return 0;
}