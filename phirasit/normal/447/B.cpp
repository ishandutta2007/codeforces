#include <stdio.h>

#define N 1010
#define T 26

char str[N];
int k, val[T];

int main() {
	scanf("%s%d", str, &k);
	int mx = 0;
	for(int i = 0;i < T;i++) {
		scanf("%d", &val[i]);
		if(val[i] > mx) {
			mx = val[i];
		}
	}
	long long ans = 0;
	int l = 0;
	for(int i = 0;str[i];i++) {
		l++;
		ans += (long long) (i+1) * val[str[i]-'a'];
	}
	for(int i = l+1;i <= l+k;i++) {
		ans += (long long) i * mx;
	}
	printf("%I64d\n", ans);
	return 0;
}