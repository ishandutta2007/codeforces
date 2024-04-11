#include <stdio.h>

int cnt[100];
int n;

int main() {
	scanf("%d",&n);
	long long ans = 0;
	while(n--) {
		int a,j=0;
		scanf("%d",&a);
		while(a) {
			j += a%2;
			a /= 2;
		}
		ans += cnt[j]++;
	}
	printf("%I64d\n",ans);
	return 0;
}