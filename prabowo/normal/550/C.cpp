#include <cstdio>
#include <cstring>

int main () {
	char s[102];
	gets (s);
	
	int n = strlen (s);
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' || s[i] == '8') {
			return 0 * printf ("YES\n%c\n", s[i]);
		}
		for (int j = i + 1; j < n; j++) {
			if ( ((s[i] - '0') * 10 + (s[j] - '0')) % 8 == 0) return 0 * printf ("YES\n%c%c\n", s[i], s[j]);
			for (int k = j + 1; k < n; k++) {
				if (( (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0') ) % 8 == 0) {
					return 0 * printf ("YES\n%c%c%c\n", s[i], s[j], s[k]);
				}
			}
		}
	}
	
	printf ("NO\n");
	return 0;
}