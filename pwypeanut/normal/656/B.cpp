#include <bits/stdc++.h>
using namespace std;

int N, M[16], D[16];

long long gcd(long long a, long long b) {
	if (a == 0) return b;
	if (b == 0) return a;
	else return gcd(max(a, b) % min(a, b), min(a, b));
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &M[i]);
	for (int i = 0; i < N; i++) scanf("%d", &D[i]);
	long long lcm = M[0];
	for (int i = 1; i < N; i++) lcm = lcm * M[i] / gcd(lcm, M[i]);
	int ans = 0;
	for (int i = 0; i < lcm; i++) {
		int a = 0;
		for (int j = 0; j < N; j++) if (i % M[j] == D[j]) a = 1;
		ans += a;
	}
	printf("%.6lf\n", (double)ans/lcm);
}