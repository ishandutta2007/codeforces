#include <stdio.h>

#define INF (-1u/2)
#define N 110

int k[N], time[N];

int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &k[i]);
	}
	int ans = INF;
	for(int i = 0;i < n;i++) {
		time[i] = 0;
		for(int j = 0;j < k[i];j++) {
			int t;
			scanf("%d", &t);
			time[i] += 5 * t + 15;
		}
		if(time[i] < ans) { 
			ans = time[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}