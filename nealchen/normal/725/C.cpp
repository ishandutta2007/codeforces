#include <stdio.h>
char s[30], T[2][15] = {};
int t[128], i, j, k, l, m;
int main() {
	gets(s);
	for(i = 'A'; i <= 'Z'; ++i) t[i] = -1;
	for(i = 0; s[i] && t[s[i]] == -1; ++i) t[s[i]] = i;
	j = t[s[i]];
	if(i == j + 1) return !printf("Impossible");
	if(i - j & 1) {
		m = (i - j) / 2;
		for(k = m, l = j; k >= 0; --k, ++l) T[0][k] = s[l];
		for(k = 0; l < i; ++k, ++l) T[1][k] = s[l];
		for(++l, m = 1; s[l]; ++l) {
			T[m][k] = s[l];
			m ? ++k : --k;
			if(k > 12) k = 12, m = 0;
		}
		for(l = 0; l < j; ++l) {
			T[m][k] = s[l];
			m ? ++k : --k;
			if(k > 12) k = 12, m = 0;
		}
		puts(T[0]);
		puts(T[1]);
	} else {
		m = (i - j) / 2;
		for(k = m - 1, l = j; k >= 0; --k, ++l) T[0][k] = s[l];
		for(k = 0; k < m; ++k, ++l) T[1][k] = s[l];
		for(++l, m = 1; s[l]; ++l) {
			T[m][k] = s[l];
			m ? ++k : --k;
			if(k > 12) k = 12, m = 0;
		}
		for(l = 0; l < j; ++l) {
			T[m][k] = s[l];
			m ? ++k : --k;
			if(k > 12) k = 12, m = 0;
		}
		puts(T[0]);
		puts(T[1]);
	}
	return 0;
}