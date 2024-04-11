#include <stdio.h>

#define N 100010

char str[N];

int sum1[N], sum2[N];
int n, k, w;

int main() {
	scanf("%d%d%d", &n, &k, &w);
	scanf("%s", str+1);
	sum1[0] = sum2[0] = 0;
	for(int i = 1;i <= n;i++) {
		sum1[i] = str[i]-'0';
		if(i > 1) {
			sum1[i] += sum1[i-1];
		}
		sum2[i] = str[i]-'0';
		if(i > k) {
			sum2[i] += sum2[i-k];
		}
	}
	while(w--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int r = sum2[b] - sum2[a-1];
		int ans = sum1[b] - sum1[a-1] - r + (b-a+1)/k - r;
		printf("%d\n", ans);
	}
	return 0;
}