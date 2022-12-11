#include <stdio.h>

#define N 60

char str[N];
long long ans = 0;
int n;

int main() {
	scanf("%d%s", &n, str);
	for(long long i = 0;i < n;i++) {
		if(str[i] == 'B') {
			long long r = 1;
			for(int j = 0;j < i;j++) {
				r <<= 1;
			}
			ans += r;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}