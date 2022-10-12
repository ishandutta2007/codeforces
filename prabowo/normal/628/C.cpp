#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, k;
	scanf ("%d %d", &n, &k);
	
	char s[100002], t[100002];
	gets (s);
	gets (s);
	
	t[n] = '\0';
	while (n--) {
		if (max('z' - s[n], s[n] - 'a') < k) {
			if ('z' - s[n] < s[n] - 'a') {
				t[n] = 'a';
				k -= s[n] - 'a';
			} else {
				t[n] = 'z';
				k -= 'z' - s[n];
			}
		} else {
			if ('z' - s[n] >= k) {
				t[n] = s[n] + k;
				k = 0;
			} else {
				t[n] = s[n] - k;
				k = 0;
			}
		}
	}
	
	if (k) puts("-1");
	else puts(t);
	
	return 0;
}