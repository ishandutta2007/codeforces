#include <cstdio>
#include <cstring>
char s[20], t[20];
int main() {
	int n;
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i <= n; i++) {
		int j;
		for(j = 0; j < i; j++) {
			t[j] = s[j];
		}
		for(j = i; j < n; j++) {
			t[j + 1] = s[j];
		}
		t[i] = t[n - i];
		for(j = 0; j <= n; j++) {
			if(t[j] != t[n - j]) {
				break;
			}
		}
		if(j > n) {
			printf("%s\n", t);
			return 0;
		}
	}
	printf("NA\n");
	return 0;
}