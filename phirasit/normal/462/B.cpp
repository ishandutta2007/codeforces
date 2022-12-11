#include <stdio.h>
#include <algorithm>

#define N 100010
#define K 26

using namespace std;

char str[N];
int cnt[K];
int n, k;

long long ans = 0;

int main() {
	scanf("%d%d%s", &n, &k, str);
	for(int i = 0;i < n;i++) {
		cnt[str[i]-'A']++;
	}
	sort(cnt, cnt+K);
	for(int i = K-1;i >= 0;i--) {
		if(cnt[i] >= k) {
			ans += (long long)k * k;
			k = 0;
		}else {
			ans += (long long)cnt[i] * cnt[i];
			k -= cnt[i];
		}
	}
	printf("%I64d\n", ans);
	return 0;
}