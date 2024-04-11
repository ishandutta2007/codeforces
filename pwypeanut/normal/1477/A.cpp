#include <bits/stdc++.h>
using namespace std;

int N, TC;
long long K;
long long arr[200005];

long long gcd(long long a, long long b) {
	if (min(a, b) == 0) return max(a, b);
	return gcd(max(a, b) % min(a, b), min(a, b));
}

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d%lld", &N, &K);
		for (int i = 0; i < N; i++) scanf("%lld", &arr[i]);
		sort(arr, arr + N);
		long long ans = arr[1] - arr[0];
		for (int i = 0; i < N-1; i++) ans = gcd(ans, arr[i+1] - arr[i]);
		if (((arr[0] % ans) + ans) % ans == ((K % ans) + ans) % ans) printf("YES\n");
		else printf("NO\n");
	}
}