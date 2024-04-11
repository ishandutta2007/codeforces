#include <bits/stdc++.h>
using namespace std;

int N, P, A[100005], B[100005];

bool attempt(double x) {
	double ans = 0;
	for (int i = 0; i < N; i++) {
		double sustain = (double)B[i] / A[i];
		if (sustain >= x) continue;
		double deficit = x - sustain;
		ans += deficit * A[i] / P;
	}
	return ans <= x;
}

int main() {
	scanf("%d%d", &N, &P);
	for (int i = 0; i < N; i++) scanf("%d%d", &A[i], &B[i]);
	double bot = 0, top = 20000000001ll, mid;
	while (bot + 1e-05 < top) {
		mid = (bot + top)/2;
		if (attempt(mid)) bot = mid;
		else top = mid;
	}
	if (bot < 15000000000ll) printf("%.5lf\n", bot);
	else printf("-1\n");
}