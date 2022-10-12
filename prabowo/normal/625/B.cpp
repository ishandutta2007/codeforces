#include <cstdio>
#include <cstring>

char s[100002];
char t[33];
bool place[100002];

int main () {
	gets (s);
	gets (t);
	
	int n = strlen (s);
	int m = strlen (t);
	
	int ans = 0;
	for (int i=0; i<n-m+1; i++) {
		bool tmp = 0;
		bool same = 1;
		for (int j=0; j<m; j++) {
			if (s[i + j] ^ t[j]) {
				same = 0;
				break;
			}
			
			tmp |= place[i + j];
		}
		
		if (same && !tmp) {
			ans++;
			place[i + m - 1] = 1;
		}
	}
	
	printf ("%d\n", ans);
	return 0;
}