#include <bits/stdc++.h>
using namespace std;

int N;
long long X[1005], Y[1005];

double f(int a, int b, int p) {
	long long A = Y[a] - Y[b], B = X[b] - X[a], C = X[a] * Y[b] - X[b] * Y[a];
	double meow = abs(A * X[p] + B * Y[p] + C);
	double dem = hypot(A, B);
	return meow / dem;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lld%lld", &X[i], &Y[i]);
	double d = 1000000000000;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if ((i + 1) % N != j) d = min(d, f(i, j, (i + 1) % N));
			if ((j + 1) % N != i) d = min(d, f(i, j, (j + 1) % N));
			if ((j + N - 1) % N != i) d = min(d, f(i, j, (j + N - 1) % N));
			if ((i + N - 1) % N != j) d = min(d, f(i, j, (i + N - 1) % N));
		}
	}
	printf("%.8lf\n", d/2);
}