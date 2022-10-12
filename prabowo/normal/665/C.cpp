#include <cstdio>
#include <cstring>

const int N = 200000;
char s[N + 5];
int main () {
	gets (s);
	int n = strlen(s);
	
	for (int i=1; i<n; i++) if (s[i] == s[i-1]) {
		while (s[i] == s[i-1] || s[i] == s[i + 1]) {
			s[i]++;
			if (s[i] > 'z') s[i] = 'a';
		}
	}
	
	puts (s);
	
	return 0;
}