#include <cstdio>
#include <cstring>

int main () {
	long long ans = 0;
	char s[300005];
	gets (s);
	
	int n = strlen(s);
	for (int i=1; i<n; i++) {
		if ( ((s[i - 1] - '0') * 10 + (s[i] - '0')) % 4 == 0) ans += i;
	}
	
	for (int i=0; i<n; i++) 
		ans += (s[i] - '0') % 4 == 0;
		
	printf ("%I64d\n", ans);
	return 0;
}