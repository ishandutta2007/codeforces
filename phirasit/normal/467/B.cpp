#include <stdio.h>

#define N 1010

int x[N];
int n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0;i <= m;i++) {
		scanf("%d", &x[i]);
	}
	int ans = 0;
	for(int i = 0;i < m;i++) {
		int cnt = 0;
		int diff = x[i] ^ x[m];
		while(diff) {
			cnt++;
			diff -= diff & (-diff);
		}
		ans += cnt <= k;
	}
	printf("%d\n", ans);
	return 0;
}