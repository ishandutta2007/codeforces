#include <stdio.h>

char str[1010];
int use[1010];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	int ans = 0;
	for(int i = 0;i < n;i++) {
		scanf("%s", str);
		int g, s;
		for(int j = 0;j < m;j++) {
			if(str[j] == 'G') {
				g = j;
			}
			if(str[j] == 'S') {
				s = j;
			}
		}
		if(g > s) {
			ans = -1;
			break;
		}
		if(!use[s-g]) {
			use[s-g] = 1;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}