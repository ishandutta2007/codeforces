#include <bits/stdc++.h>
using namespace std;

int N;
int A[200005];
int digits[25];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 20; j++) if (A[i] & (1 << j)) digits[j]++;
	}
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		long long val = 0;
		for (int j = 0; j < 20; j++) {
			if (digits[j] > i) val += (1 << j);
		}
		ans += val * val;
	}
	printf("%lld\n", ans);
}